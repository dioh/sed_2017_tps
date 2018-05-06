#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Flow1_PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock.h"

using namespace std;

Flow1_PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock::Flow1_PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock(const string &name) :
	Atomic(name),
    in_port_PreySubSubModelStock(addInputPort("in_port_PreySubSubModelStock")),
    in_port_PULSE_V_combiner_FP_10_I_50_Flow1(addInputPort("in_port_PULSE_V_combiner_FP_10_I_50_Flow1")),
    isSet_PreySubSubModelStock(false),
    isSet_PULSE_V_combiner_FP_10_I_50_Flow1(false),
	out_port_Flow1_PreySubSubModelStock(addOutputPort("out_port_Flow1_PreySubSubModelStock"))
{
}


Model &Flow1_PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Flow1_PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_PreySubSubModelStock) {
		PreySubSubModelStock = x;
		isSet_PreySubSubModelStock = true;
	}
	if(msg.port() == in_port_PULSE_V_combiner_FP_10_I_50_Flow1) {
		PULSE_V_combiner_FP_10_I_50_Flow1 = x;
		isSet_PULSE_V_combiner_FP_10_I_50_Flow1 = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Flow1_PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Flow1_PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_PreySubSubModelStock & isSet_PULSE_V_combiner_FP_10_I_50_Flow1 ) {
	    Tuple<Real> out_value { 0.05 * PreySubSubModelStock * PULSE_V_combiner_FP_10_I_50_Flow1 };
		sendOutput(msg.time(), out_port_Flow1_PreySubSubModelStock, out_value);
	} else {
		Tuple<Real> out_value { 0 };
		sendOutput(msg.time(), out_port_Flow1_PreySubSubModelStock, out_value);
	}
	
	return *this ;
}