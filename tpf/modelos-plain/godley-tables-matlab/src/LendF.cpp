#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "LendF.h"

using namespace std;

LendF::LendF(const string &name) :
	Atomic(name),
	DebtFirms(addInputPort("DebtFirms")),
	tauL(addInputPort("tauL")),
	isSet_val_DebtFirms(false),
	isSet_val_tauL(false),
	out(addOutputPort("out"))
{
}


Model &LendF::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &LendF::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == DebtFirms) {
		val_DebtFirms = x;
		isSet_val_DebtFirms = true;
	}
	if(msg.port() == tauL) {
		val_tauL = x;
		isSet_val_tauL = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &LendF::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &LendF::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_DebtFirms & isSet_val_tauL ) {
		double val = (val_DebtFirms/val_tauL);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}