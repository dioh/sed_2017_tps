#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ft_Capital.h"

using namespace std;

ft_Capital::ft_Capital(const string &name) :
	Atomic(name),
	inPlus_chgCapital(addInputPort("inPlus_chgCapital")),
	isSet_val_inPlus_chgCapital(false),
	out(addOutputPort("out"))
{
}


Model &ft_Capital::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ft_Capital::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inPlus_chgCapital) {
		val_inPlus_chgCapital = x;
		isSet_val_inPlus_chgCapital = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ft_Capital::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ft_Capital::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inPlus_chgCapital ) {
		plus = plus + val_inPlus_chgCapital;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}