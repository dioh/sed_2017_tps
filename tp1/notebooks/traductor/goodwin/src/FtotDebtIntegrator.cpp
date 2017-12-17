#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FtotDebtIntegrator.h"

using namespace std;

FtotDebtIntegrator::FtotDebtIntegrator(const string &name) :
	inPlus_chgDebt(addInputPort("inPlus_chgDebt")),
	out(addOutputPort("out")),
	val_inPlus_chgDebt(0),
	isSet_val_inPlus_chgDebt(false),
	Atomic(name)
{
}


Model &FtotDebtIntegrator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FtotDebtIntegrator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inPlus_chgDebt) {
		val_inPlus_chgDebt = x;
		isSet_val_inPlus_chgDebt = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FtotDebtIntegrator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FtotDebtIntegrator::outputFunction(const CollectMessage &msg)
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