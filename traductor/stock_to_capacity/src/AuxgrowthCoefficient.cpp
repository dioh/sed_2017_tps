#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "AuxgrowthCoefficient.h"

using namespace std;

AuxgrowthCoefficient::AuxgrowthCoefficient(const string &name) :
	Atomic(name),
	in_effectofRatioofStocktoCapacityonGrowthCoefficient(addInputPort("in_effectofRatioofStocktoCapacityonGrowthCoefficient")),
	isSet_effectofRatioofStocktoCapacityonGrowthCoefficient(false),
	out(addOutputPort("out"))
{
}


Model &AuxgrowthCoefficient::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &AuxgrowthCoefficient::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_effectofRatioofStocktoCapacityonGrowthCoefficient) {
		effectofRatioofStocktoCapacityonGrowthCoefficient = x;
		isSet_effectofRatioofStocktoCapacityonGrowthCoefficient = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &AuxgrowthCoefficient::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &AuxgrowthCoefficient::outputFunction(const CollectMessage &msg)
{
	if( isSet_effectofRatioofStocktoCapacityonGrowthCoefficient ) {
		double val = 0.5 * effectofRatioofStocktoCapacityonGrowthCoefficient;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}