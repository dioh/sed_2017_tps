#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "FplusPrevOutptChgPrevOutpt.h"

using namespace std;

FplusPrevOutptChgPrevOutpt::FplusPrevOutptChgPrevOutpt(const string &name) :
	Atomic(name),
	in_output(addInputPort("in_output")),
	in_prevOutptIntegrator(addInputPort("in_prevOutptIntegrator")),
	in_twounitTimestep(addInputPort("in_twounitTimestep")),
	isSet_output(false),
	isSet_prevOutptIntegrator(false),
	isSet_twounitTimestep(false),
	out(addOutputPort("out"))
{
}


Model &FplusPrevOutptChgPrevOutpt::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &FplusPrevOutptChgPrevOutpt::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_output) {
		output = x;
		isSet_output = true;
	}
	if(msg.port() == in_prevOutptIntegrator) {
		prevOutptIntegrator = x;
		isSet_prevOutptIntegrator = true;
	}
	if(msg.port() == in_twounitTimestep) {
		twounitTimestep = x;
		isSet_twounitTimestep = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &FplusPrevOutptChgPrevOutpt::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &FplusPrevOutptChgPrevOutpt::outputFunction(const CollectMessage &msg)
{
	if( isSet_output & isSet_prevOutptIntegrator & isSet_twounitTimestep ) {
		double val = (output - prevOutptIntegrator) / twounitTimestep;
		Tuple<Real> out_value { val };
		sendOutput(msg.time(), out, out_value);
	}
	return *this ;
}