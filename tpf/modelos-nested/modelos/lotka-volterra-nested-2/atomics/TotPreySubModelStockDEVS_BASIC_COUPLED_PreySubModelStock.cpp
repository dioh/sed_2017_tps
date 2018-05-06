#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotPreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock.h"

using namespace std;

TotPreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock::TotPreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock(const string &name) :
	Atomic(name),
	in_minus_port_preySubFlow_PreySubModelStock(addInputPort("in_minus_port_preySubFlow_PreySubModelStock")),
	isSet_preySubFlow_PreySubModelStock(false),
	out_port_TotPreySubModelStock(addOutputPort("out_port_TotPreySubModelStock"))
	{
}


Model &TotPreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotPreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_minus_port_preySubFlow_PreySubModelStock) {
		preySubFlow_PreySubModelStock = x;
		isSet_preySubFlow_PreySubModelStock = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotPreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotPreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;if(isSet_preySubFlow_PreySubModelStock) { minus = minus + preySubFlow_PreySubModelStock; }double val = plus - minus;
	Tuple<Real> out_value { val };
	sendOutput(msg.time(), out_port_TotPreySubModelStock, out_value);
	return *this ;
}