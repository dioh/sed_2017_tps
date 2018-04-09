#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "preySubFlow_PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock.h"

using namespace std;

preySubFlow_PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock::preySubFlow_PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock(const string &name) :
	Atomic(name),
    PreySubModelStock(addInputPort("PreySubModelStock")),
    PreySubSubModelStock(addInputPort("PreySubSubModelStock")),
    Prey(addInputPort("Prey")),
    isSet_PreySubModelStock(false),
    isSet_PreySubSubModelStock(false),
    isSet_Prey(false),
	preySubFlow_PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock(addOutputPort("preySubFlow_PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock"))
{
}


Model &preySubFlow_PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &preySubFlow_PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == PreySubModelStock) {
		PreySubModelStock = x;
		isSet_PreySubModelStock = true;
	}
	if(msg.port() == PreySubSubModelStock) {
		PreySubSubModelStock = x;
		isSet_PreySubSubModelStock = true;
	}
	if(msg.port() == Prey) {
		Prey = x;
		isSet_Prey = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &preySubFlow_PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &preySubFlow_PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock::outputFunction(const CollectMessage &msg)
{
	
	if( isSet_PreySubModelStock & isSet_PreySubSubModelStock & isSet_Prey ) {
	    Tuple<Real> out_value { 0 * PreySubModelStock + 0 *  Prey + 0 * PreySubSubModelStock };
		sendOutput(msg.time(), preySubFlow_PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock, out_value);
	}
	
	return *this ;
}