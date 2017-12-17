#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "AuxeffectofRatioofStocktoCapacityonGrowthCoefficient.h"

using namespace std;

AuxeffectofRatioofStocktoCapacityonGrowthCoefficient::AuxeffectofRatioofStocktoCapacityonGrowthCoefficient(const string &name) :
	Atomic(name),
	in_ratioofStocktoCapacity(addInputPort("in_ratioofStocktoCapacity")),
	isSet_ratioofStocktoCapacity(false),
	out(addOutputPort("out"))
{
}


Model &AuxeffectofRatioofStocktoCapacityonGrowthCoefficient::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &AuxeffectofRatioofStocktoCapacityonGrowthCoefficient::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_ratioofStocktoCapacity) {
		ratioofStocktoCapacity = x;
		isSet_ratioofStocktoCapacity = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &AuxeffectofRatioofStocktoCapacityonGrowthCoefficient::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &AuxeffectofRatioofStocktoCapacityonGrowthCoefficient::outputFunction(const CollectMessage &msg)
{
	if( isSet_ratioofStocktoCapacity ) {
		double val = 1 - ratioofStocktoCapacity;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}