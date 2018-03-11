#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "ReservesTot.h"

using namespace std;

ReservesTot::ReservesTot(const string &name) :
	Atomic(name),
	chgReservesPlus(addInputPort("chgReservesPlus")),
	isSet_val_chgReservesPlus(false),
	out(addOutputPort("out"))
{
}


Model &ReservesTot::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &ReservesTot::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == chgReservesPlus) {
		val_chgReservesPlus = x;
		isSet_val_chgReservesPlus = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &ReservesTot::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &ReservesTot::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if(isSet_val_chgReservesPlus) {
		plus = plus + val_chgReservesPlus;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}