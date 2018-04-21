#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "RepayF.h"

using namespace std;

RepayF::RepayF(const string &name) :
	Atomic(name),
	DebtFirms(addInputPort("DebtFirms")),
	tauR(addInputPort("tauR")),
	isSet_val_DebtFirms(false),
	isSet_val_tauR(false),
	out(addOutputPort("out"))
{
}


Model &RepayF::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &RepayF::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == DebtFirms) {
		val_DebtFirms = x;
		isSet_val_DebtFirms = true;
	}
	if(msg.port() == tauR) {
		val_tauR = x;
		isSet_val_tauR = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &RepayF::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &RepayF::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_DebtFirms & isSet_val_tauR ) {
		double val = (val_DebtFirms/val_tauR);
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}