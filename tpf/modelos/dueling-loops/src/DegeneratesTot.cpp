#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "DegeneratesTot.h"

using namespace std;

DegeneratesTot::DegeneratesTot(const string &name) :
	Atomic(name),
	neutralistsToDegeneratesPlus(addInputPort("neutralistsToDegeneratesPlus")),
	outDegeneratesRightMinus(addInputPort("outDegeneratesRightMinus")),
	outDegeneratesLeftMinus(addInputPort("outDegeneratesLeftMinus")),
	isSet_val_neutralistsToDegeneratesPlus(false),
	isSet_val_outDegeneratesRightMinus(false),
	isSet_val_outDegeneratesLeftMinus(false),
	out(addOutputPort("out"))
{
}


Model &DegeneratesTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &DegeneratesTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == neutralistsToDegeneratesPlus) {
		val_neutralistsToDegeneratesPlus = x;
		isSet_val_neutralistsToDegeneratesPlus = true;
	}
	if(msg.port() == outDegeneratesRightMinus) {
		val_outDegeneratesRightMinus = x;
		isSet_val_outDegeneratesRightMinus = true;
	}
	if(msg.port() == outDegeneratesLeftMinus) {
		val_outDegeneratesLeftMinus = x;
		isSet_val_outDegeneratesLeftMinus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &DegeneratesTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &DegeneratesTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_neutralistsToDegeneratesPlus & isSet_val_outDegeneratesRightMinus & isSet_val_outDegeneratesLeftMinus) {
		plus = plus + val_neutralistsToDegeneratesPlus;
		minus = minus + val_outDegeneratesRightMinus;
		minus = minus + val_outDegeneratesLeftMinus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}