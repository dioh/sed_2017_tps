#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "RationalSupportersTot.h"

using namespace std;

RationalSupportersTot::RationalSupportersTot(const string &name) :
	Atomic(name),
	neutralistsToRationalsPlus(addInputPort("neutralistsToRationalsPlus")),
	rationalsToNeutralistsMinus(addInputPort("rationalsToNeutralistsMinus")),
	isSet_val_neutralistsToRationalsPlus(false),
	isSet_val_rationalsToNeutralistsMinus(false),
	out(addOutputPort("out"))
{
}


Model &RationalSupportersTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &RationalSupportersTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == neutralistsToRationalsPlus) {
		val_neutralistsToRationalsPlus = x;
		isSet_val_neutralistsToRationalsPlus = true;
	}
	if(msg.port() == rationalsToNeutralistsMinus) {
		val_rationalsToNeutralistsMinus = x;
		isSet_val_rationalsToNeutralistsMinus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &RationalSupportersTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &RationalSupportersTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_neutralistsToRationalsPlus & isSet_val_rationalsToNeutralistsMinus) {
		plus = plus + val_neutralistsToRationalsPlus;
		minus = minus + val_rationalsToNeutralistsMinus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}