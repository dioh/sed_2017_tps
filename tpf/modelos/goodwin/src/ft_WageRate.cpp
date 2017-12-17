#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ft_WageRate.h"

using namespace std;

ft_WageRate::ft_WageRate(const string &name) :
	Atomic(name),
	inPlus_chgWageRate(addInputPort("inPlus_chgWageRate")),
	isSet_val_inPlus_chgWageRate(false),
	out(addOutputPort("out"))
{
}


Model &ft_WageRate::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ft_WageRate::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inPlus_chgWageRate) {
		val_inPlus_chgWageRate = x;
		isSet_val_inPlus_chgWageRate = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ft_WageRate::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ft_WageRate::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inPlus_chgWageRate ) {
		plus = plus + val_inPlus_chgWageRate;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}