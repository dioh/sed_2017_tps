#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ft_Susceptible.h"

using namespace std;

ft_Susceptible::ft_Susceptible(const string &name) :
	Atomic(name),
	inMinus_Succumbing(addInputPort("inMinus_Succumbing")),
	isSet_val_inMinus_Succumbing(false),
	out(addOutputPort("out"))
{
}


Model &ft_Susceptible::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ft_Susceptible::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inMinus_Succumbing) {
		val_inMinus_Succumbing = x;
		isSet_val_inMinus_Succumbing = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ft_Susceptible::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ft_Susceptible::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inMinus_Succumbing ) {
		minus = minus + val_inMinus_Succumbing;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}