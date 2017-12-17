#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ft_Infectious.h"

using namespace std;

ft_Infectious::ft_Infectious(const string &name) :
	Atomic(name),
	inMinus_Recovering(addInputPort("inMinus_Recovering")),
	inPlus_Succumbing(addInputPort("inPlus_Succumbing")),
	isSet_val_inMinus_Recovering(false),
	isSet_val_inPlus_Succumbing(false),
	out(addOutputPort("out"))
{
}


Model &ft_Infectious::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ft_Infectious::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inMinus_Recovering) {
		val_inMinus_Recovering = x;
		isSet_val_inMinus_Recovering = true;
	}
	if(msg.port() == inPlus_Succumbing) {
		val_inPlus_Succumbing = x;
		isSet_val_inPlus_Succumbing = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ft_Infectious::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ft_Infectious::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inMinus_Recovering & isSet_val_inPlus_Succumbing ) {
		minus = minus + val_inMinus_Recovering;
		plus = plus + val_inPlus_Succumbing;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}