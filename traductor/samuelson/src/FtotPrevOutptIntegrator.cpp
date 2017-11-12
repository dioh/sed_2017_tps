#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FtotPrevOutptIntegrator.h"

using namespace std;

FtotPrevOutptIntegrator::FtotPrevOutptIntegrator(const string &name) :
	inPlus_ChgPrevOutpt(addInputPort("inPlus_ChgPrevOutpt")),
	out(addOutputPort("out")),
	val_inPlus_ChgPrevOutpt(0),
	isSet_val_inPlus_ChgPrevOutpt(false),
	Atomic(name)
{
}


Model &FtotPrevOutptIntegrator::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FtotPrevOutptIntegrator::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == inPlus_ChgPrevOutpt) {
		val_inPlus_ChgPrevOutpt = x;
		isSet_val_inPlus_ChgPrevOutpt = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FtotPrevOutptIntegrator::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FtotPrevOutptIntegrator::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;
	if( isSet_val_inPlus_ChgPrevOutpt ) {
		plus = plus + val_inPlus_ChgPrevOutpt;
		double val = plus - minus;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}

	return *this ;
}