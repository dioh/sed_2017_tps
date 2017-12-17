#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ft_Debt.h"

using namespace std;

ft_Debt::ft_Debt(const string &name) :
	Atomic(name),
	inPlus_chgDebt(addInputPort("inPlus_chgDebt")),
	isSet_val_inPlus_chgDebt(false),
	out(addOutputPort("out"))
{
}


Model &ft_Debt::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ft_Debt::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inPlus_chgDebt) {
		val_inPlus_chgDebt = x;
		isSet_val_inPlus_chgDebt = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ft_Debt::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ft_Debt::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inPlus_chgDebt ) {
		plus = plus + val_inPlus_chgDebt;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}