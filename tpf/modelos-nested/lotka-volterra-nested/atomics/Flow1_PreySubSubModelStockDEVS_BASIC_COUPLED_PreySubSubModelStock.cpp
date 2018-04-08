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
    PULSE_V_combiner_FP_10_I_50(addInputPort("PULSE_V_combiner_FP_10_I_50")),
    PreySubSubModelStock(addInputPort("PreySubSubModelStock")),
    isSet_PULSE_V_combiner_FP_10_I_50(false),
    isSet_PreySubSubModelStock(false),
	Flow1_PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock(addOutputPort("Flow1_PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock"))
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

	if(msg.port() == PULSE_V_combiner_FP_10_I_50) {
		PULSE_V_combiner_FP_10_I_50 = x;
		isSet_PULSE_V_combiner_FP_10_I_50 = true;
	}
	if(msg.port() == PreySubSubModelStock) {
		PreySubSubModelStock = x;
		isSet_PreySubSubModelStock = true;
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
	
	if( isSet_PULSE_V_combiner_FP_10_I_50 & isSet_PreySubSubModelStock ) {
	    Tuple<Real> out_value { 0.05 * PreySubSubModelStock * PULSE_V_combiner_FP_10_I_50 };
		sendOutput(msg.time(), Flow1_PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock, out_value);
	}
	
	return *this ;
}