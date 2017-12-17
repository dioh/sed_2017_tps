#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ft_Recovered.h"

using namespace std;

ft_Recovered::ft_Recovered(const string &name) :
	Atomic(name),
	inPlus_Recovering(addInputPort("inPlus_Recovering")),
	isSet_val_inPlus_Recovering(false),
	out(addOutputPort("out"))
{
}


Model &ft_Recovered::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ft_Recovered::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inPlus_Recovering) {
		val_inPlus_Recovering = x;
		isSet_val_inPlus_Recovering = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ft_Recovered::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ft_Recovered::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inPlus_Recovering ) {
		plus = plus + val_inPlus_Recovering;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}