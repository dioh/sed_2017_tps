#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "LoansTot.h"

using namespace std;

LoansTot::LoansTot(const string &name) :
	Atomic(name),
	chgLoansPlus(addInputPort("chgLoansPlus")),
	isSet_val_chgLoansPlus(false),
	out(addOutputPort("out"))
{
}


Model &LoansTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &LoansTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == chgLoansPlus) {
		val_chgLoansPlus = x;
		isSet_val_chgLoansPlus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &LoansTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &LoansTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_chgLoansPlus) {
		plus = plus + val_chgLoansPlus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}