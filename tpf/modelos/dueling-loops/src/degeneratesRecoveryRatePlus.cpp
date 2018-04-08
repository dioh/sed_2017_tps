#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "degeneratesRecoveryRatePlus.h"

using namespace std;

degeneratesRecoveryRatePlus::degeneratesRecoveryRatePlus(const string &name) :
	Atomic(name),
	Degenerates(addInputPort("Degenerates")),
	infectionLifetime(addInputPort("infectionLifetime")),
	isSet_val_Degenerates(false),
	isSet_val_infectionLifetime(false),
	out(addOutputPort("out"))
{
}


Model &degeneratesRecoveryRatePlus::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &degeneratesRecoveryRatePlus::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == Degenerates) {
		val_Degenerates = x;
		isSet_val_Degenerates = true;
	}
	if(msg.port() == infectionLifetime) {
		val_infectionLifetime = x;
		isSet_val_infectionLifetime = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &degeneratesRecoveryRatePlus::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &degeneratesRecoveryRatePlus::outputFunction(const CollectMessage &msg)
{
	if( isSet_val_Degenerates & isSet_val_infectionLifetime ) {
		double val = val_Degenerates / val_infectionLifetime;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}