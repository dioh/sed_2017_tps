#include <algorithm>
#include <math.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "ini.h"
#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"
#include "value.h"

#include "PredatorDEVS_BASIC_COUPLED_Predator.h"

using namespace std;


PredatorDEVS_BASIC_COUPLED_Predator::PredatorDEVS_BASIC_COUPLED_Predator(const string &name) :
    Atomic(name),
    in_port_TotPredator(addInputPort("in_port_TotPredator")),
    in_port_subtract(addInputPort("in_port_subtract")),
    in_port_increment(addInputPort("in_port_increment")),
    out_port_Predator(addOutputPort("out_port_Predator"))
{
    non_negative = get_param("non_negative");

    dQRel = get_param("dQRel");
    dQMin = get_param("dQMin");

    x[0] = get_param("x0");
    x[1] = 0;

    q = x[0];

    dQ = max(fabs(x[0]) * dQRel, dQMin);

    sigma = VTime::Zero;

    gain = get_param("gain");
    if(gain == 0)
        gain = 1;

#ifdef PREDATORDEVS_BASIC_COUPLED_PREDATOR_LOG_OUTPUT
    log_output_Predator = true;
#else
    log_output_Predator = false;
#endif

    if(log_output_Predator)
    {
        // delete file from previous run
        ofstream outf(description(), std::ofstream::out);
        outf.close();
    }
}

VTime PredatorDEVS_BASIC_COUPLED_Predator::minposroot(double *coeff)
{
    float mpr;
    VTime ret;

    if(coeff[1] == 0)
        ret = VTime::Inf;
    else
    {
        mpr = -coeff[0]/coeff[1];
        ret = VTime(mpr);

        // check for negative values and overflows in VTime.asMsecs() (VTime.asMsecs() is used to advance time)
        if(mpr < 0 || ret.asMsecs() < 0 || ret.asMsecs() >= VTime::Inf.asMsecs())
            ret = VTime::Inf;
    }

    return ret;
}

double PredatorDEVS_BASIC_COUPLED_Predator::to_seconds(const VTime &vt)
{
    return vt.asMsecs() / 1000.;
}


Model &PredatorDEVS_BASIC_COUPLED_Predator::initFunction()
{
    sigma = VTime::Zero;
    holdIn(AtomicState::active, sigma);

    return *this;
}


Model &PredatorDEVS_BASIC_COUPLED_Predator::externalFunction(const ExternalMessage &msg)
{
    double diffxq[2];

    Real derx = Tuple<Real>::from_value(msg.value())[0];
    derx = derx * gain;

    VTime e = msg.time() - lastChange();

    if(msg.port() == in_port_TotPredator)
    {
        x[0] = x[0] + x[1] * this->to_seconds(e);
        x[1] = derx.value();
        if(sigma.asMsecs() > 0)
        {
            // inferior delta crossing
            diffxq[1] = -x[1];
            diffxq[0] = q - x[0] -dQ;
            sigma = this->minposroot(diffxq);

            // superior delta difference
            diffxq[0] = q - x[0] + dQ;
            VTime sigma_up = this->minposroot(diffxq);

            // keep the smallest one
            if(sigma_up < sigma)
                sigma = sigma_up;

            if(fabs(x[0] - q) > dQ)
                sigma = VTime::Zero;
        }
    }
    // Agrega posibilidad de bajar el valor de forma discreta
    else if (msg.port() == in_port_subtract)
    {
        x[0] = x[0] - derx.value();
        if(x[0] < 0 && non_negative) {
            x[0] = 0;
        }
        sigma = VTime::Zero;
    }
    // Agrega posibilidad de incrementar el valor en forma discreta
    else if (msg.port() == in_port_increment)
    {
        x[0] = x[0] + derx.value();
        sigma = VTime::Zero;
    }
    else
    {
        x[0] = derx.value();
        sigma = VTime::Zero;
    }

    holdIn(AtomicState::active, sigma);

    return *this;
}


Model &PredatorDEVS_BASIC_COUPLED_Predator::internalFunction(const InternalMessage &msg)
{
    x[0] = x[0] + x[1] * this->to_seconds(sigma);
    q = x[0];    

    dQ = max(dQRel * fabs(x[0]), dQMin);

    if(x[1] == 0)
    {
        sigma = VTime::Inf;
        passivate();
    }
    else
    {
        sigma = VTime((float) fabs(dQ/x[1]));
        holdIn(AtomicState::active, sigma);
    }

    return *this ;
}


Model &PredatorDEVS_BASIC_COUPLED_Predator::outputFunction(const CollectMessage &msg)
{
    double y[2] = {x[0], x[1]};

    y[0] = y[0] + y[1] * this->to_seconds(sigma);
    y[1] = 0;     

    if(log_output_Predator)
    {
        // send output to file
        ofstream outf(description(), std::ofstream::out | std::ofstream::app);
        outf << this->to_seconds(msg.time()) << "," << y[0] << endl;
        outf.close();
    }

    Tuple<Real> out_value{y[0]};
    sendOutput(msg.time(), out_port_Predator, out_value);

    return *this ;
}

double PredatorDEVS_BASIC_COUPLED_Predator::get_param(const string &name)
{
    double value = 0;

    try
    {
        string param = ParallelMainSimulator::Instance().getParameter(description(), name);
        stringstream param_stream(param);

        param_stream >> value;
    }
    catch(IniRequestException &)
    {}

    return value;
}