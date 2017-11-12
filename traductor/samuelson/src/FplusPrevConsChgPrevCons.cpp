#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FplusPrevConsChgPrevCons.h"

using namespace std;

FplusPrevConsChgPrevCons::FplusPrevConsChgPrevCons(const string &name) :
	Atomic(name),
	in_prevConsIntegrator(addInputPort("in_prevConsIntegrator")),
	in_consumption(addInputPort("in_consumption")),
	in_timestep(addInputPort("in_timestep")),
	isSet_prevConsIntegrator(false),
	isSet_consumption(false),
	isSet_timestep(false),
	out(addOutputPort("out"))
{
}


Model &FplusPrevConsChgPrevCons::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusPrevConsChgPrevCons::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_prevConsIntegrator) {
		prevConsIntegrator = x;
		isSet_prevConsIntegrator = true;
	}
	if(msg.port() == in_consumption) {
		consumption = x;
		isSet_consumption = true;
	}
	if(msg.port() == in_timestep) {
		timestep = x;
		isSet_timestep = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FplusPrevConsChgPrevCons::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FplusPrevConsChgPrevCons::outputFunction(const CollectMessage &msg)
{
	if( isSet_prevConsIntegrator & isSet_consumption & isSet_timestep ) {
		double val = (consumption - prevConsIntegrator) / timestep;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}