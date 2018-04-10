#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "TotPreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock.h"

using namespace std;

TotPreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock::TotPreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock(const string &name) :
	Atomic(name),
	in_port_minus_Flow1_PreySubSubModelStock(addInputPort("in_port_minus_Flow1_PreySubSubModelStock")),
	isSet_Flow1_PreySubSubModelStock(false),
	out_port_TotPreySubSubModelStock(addOutputPort("out_port_TotPreySubSubModelStock"))
	{
}


Model &TotPreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &TotPreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_port_minus_Flow1_PreySubSubModelStock) {
		Flow1_PreySubSubModelStock = x;
		isSet_Flow1_PreySubSubModelStock = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &TotPreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &TotPreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_Flow1_PreySubSubModelStock) {
		minus = minus + Flow1_PreySubSubModelStock;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out_port_TotPreySubSubModelStock, out_value);
		}

	return *this ;
}