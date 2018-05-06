#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"

#include "Totstock1DEVS_BASIC_COUPLED_stock1.h"

using namespace std;

Totstock1DEVS_BASIC_COUPLED_stock1::Totstock1DEVS_BASIC_COUPLED_stock1(const string &name) :
	Atomic(name),
	in_minus_port_flow1_stock1(addInputPort("in_minus_port_flow1_stock1")),
	in_minus_port_flow2_stock1(addInputPort("in_minus_port_flow2_stock1")),
	isSet_flow1_stock1(false),
	isSet_flow2_stock1(false),
	out_port_Totstock1(addOutputPort("out_port_Totstock1"))
	{
}


Model &Totstock1DEVS_BASIC_COUPLED_stock1::initFunction()
{
	holdIn(AtomicState::passive, VTime::Inf);
	return *this;
}


Model &Totstock1DEVS_BASIC_COUPLED_stock1::externalFunction(const ExternalMessage &msg)
{
	double x = Tuple<Real>::from_value(msg.value())[0].value();

	if(msg.port() == in_minus_port_flow1_stock1) {
		flow1_stock1 = x;
		isSet_flow1_stock1 = true;
	}
	if(msg.port() == in_minus_port_flow2_stock1) {
		flow2_stock1 = x;
		isSet_flow2_stock1 = true;
	}
	holdIn(AtomicState::active, VTime::Zero);
	return *this;
}


Model &Totstock1DEVS_BASIC_COUPLED_stock1::internalFunction(const InternalMessage &)
{
	passivate();
	return *this ;
}


Model &Totstock1DEVS_BASIC_COUPLED_stock1::outputFunction(const CollectMessage &msg)
{
	double plus = 0;
	double minus = 0;if(isSet_flow1_stock1) { minus = minus + flow1_stock1; }if(isSet_flow2_stock1) { minus = minus + flow2_stock1; }double val = plus - minus;
	Tuple<Real> out_value { val };
	sendOutput(msg.time(), out_port_Totstock1, out_value);
	return *this ;
}