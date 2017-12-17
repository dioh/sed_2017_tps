#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "AuxratioofStocktoCapacity.h"

using namespace std;

AuxratioofStocktoCapacity::AuxratioofStocktoCapacity(const string &name) :
	Atomic(name),
	in_maximumCapacityofStock(addInputPort("in_maximumCapacityofStock")),
	in_stock1Integrator(addInputPort("in_stock1Integrator")),
	isSet_maximumCapacityofStock(false),
	isSet_stock1Integrator(false),
	out(addOutputPort("out"))
{
}


Model &AuxratioofStocktoCapacity::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &AuxratioofStocktoCapacity::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_maximumCapacityofStock) {
		maximumCapacityofStock = x;
		isSet_maximumCapacityofStock = true;
	}
	if(msg.port() == in_stock1Integrator) {
		stock1Integrator = x;
		isSet_stock1Integrator = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &AuxratioofStocktoCapacity::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &AuxratioofStocktoCapacity::outputFunction(const CollectMessage &msg)
{
	if( isSet_maximumCapacityofStock & isSet_stock1Integrator ) {
		double val = stock1Integrator / maximumCapacityofStock;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}