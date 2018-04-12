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
    in_port_PreySubModelStock(addInputPort("in_port_PreySubModelStock")),
    in_port_PreySubSubModelStock(addInputPort("in_port_PreySubSubModelStock")),
    in_port_Prey(addInputPort("in_port_Prey")),
    isSet_PreySubModelStock(false),
    isSet_PreySubSubModelStock(false),
    isSet_Prey(false),
	out_port_preySubFlow_PreySubModelStock(addOutputPort("out_port_preySubFlow_PreySubModelStock"))
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

	if(msg.port() == in_port_PreySubModelStock) {
		PreySubModelStock = x;
		isSet_PreySubModelStock = true;
	}
	if(msg.port() == in_port_PreySubSubModelStock) {
		PreySubSubModelStock = x;
		isSet_PreySubSubModelStock = true;
	}
	if(msg.port() == in_port_Prey) {
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
		sendOutput(msg.time(), out_port_preySubFlow_PreySubModelStock, out_value);
	}
	
	return *this ;
}