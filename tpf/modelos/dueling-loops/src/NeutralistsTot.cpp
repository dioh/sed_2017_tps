#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "NeutralistsTot.h"

using namespace std;

NeutralistsTot::NeutralistsTot(const string &name) :
	Atomic(name),
	rationalsToNeutralistsPlus(addInputPort("rationalsToNeutralistsPlus")),
	neutralistsToDegeneratesMinus(addInputPort("neutralistsToDegeneratesMinus")),
	neutralistsToRationalsMinus(addInputPort("neutralistsToRationalsMinus")),
	isSet_val_rationalsToNeutralistsPlus(false),
	isSet_val_neutralistsToDegeneratesMinus(false),
	isSet_val_neutralistsToRationalsMinus(false),
	out(addOutputPort("out"))
{
}


Model &NeutralistsTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &NeutralistsTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == rationalsToNeutralistsPlus) {
		val_rationalsToNeutralistsPlus = x;
		isSet_val_rationalsToNeutralistsPlus = true;
	}
	if(msg.port() == neutralistsToDegeneratesMinus) {
		val_neutralistsToDegeneratesMinus = x;
		isSet_val_neutralistsToDegeneratesMinus = true;
	}
	if(msg.port() == neutralistsToRationalsMinus) {
		val_neutralistsToRationalsMinus = x;
		isSet_val_neutralistsToRationalsMinus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &NeutralistsTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &NeutralistsTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_rationalsToNeutralistsPlus & isSet_val_neutralistsToDegeneratesMinus & isSet_val_neutralistsToRationalsMinus) {
		plus = plus + val_rationalsToNeutralistsPlus;
		minus = minus + val_neutralistsToDegeneratesMinus;
		minus = minus + val_neutralistsToRationalsMinus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}