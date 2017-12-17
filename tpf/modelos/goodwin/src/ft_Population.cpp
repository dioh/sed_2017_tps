#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ft_Population.h"

using namespace std;

ft_Population::ft_Population(const string &name) :
	Atomic(name),
	inPlus_chgPopulation(addInputPort("inPlus_chgPopulation")),
	isSet_val_inPlus_chgPopulation(false),
	out(addOutputPort("out"))
{
}


Model &ft_Population::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ft_Population::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inPlus_chgPopulation) {
		val_inPlus_chgPopulation = x;
		isSet_val_inPlus_chgPopulation = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ft_Population::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ft_Population::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inPlus_chgPopulation ) {
		plus = plus + val_inPlus_chgPopulation;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}