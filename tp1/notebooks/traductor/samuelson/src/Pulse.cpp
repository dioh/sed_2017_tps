
#include <string>
#include "Pulse.h"
#include "message.h"
#include "parsimu.h"

using namespace std;

Pulse::Pulse(const string &name) : 
  Atomic(name),
  start(addInputPort("start")),
	stop(addInputPort("stop")),
  in_value(addInputPort("in_value")),
  in_hours(addInputPort("in_hours")),
  in_minutes(addInputPort("in_minutes")),
  in_seconds(addInputPort("in_seconds")),
  in_milliseconds(addInputPort("in_milliseconds")),
  out(addOutputPort("out")),
  on(true),
  isSetHours(false),
  isSetMinutes(false),
  isSetSeconds(false),
  isSetMilliseconds(false),
  value(0) 
  {
  }

Model &Pulse::initFunction() { 

  // Pulso inicial
  holdIn(AtomicState::active, VTime(0,0,0,1)); // por que necesito darle valor > 0 ?
  return *this; 
}

Model &Pulse::externalFunction( const ExternalMessage &msg ) {

  double x = Tuple<Real>::from_value(msg.value())[0].value();
  //cout << "me llega: " << x << endl;
  
  if (msg.port() == start) {
    this->on = true;
    holdIn( AtomicState::active, this->frequency_time );
  } else if (msg.port() == stop) {
    this->on = false;
    passivate();
  
  } else if (msg.port() == in_value) {
    this->value = x;
  
  } else if (msg.port() == in_hours) {
    this->hours = x;
    isSetHours = true;
  } else if (msg.port() == in_minutes) {
    this->minutes = x;
    isSetMinutes = true;
  } else if (msg.port() == in_seconds) {
    this->seconds = x;
    isSetSeconds = true;
  } else if (msg.port() == in_milliseconds) {
    this->milliseconds = x;
    isSetMilliseconds = true;
  }

  //cout << "entro external 1" << endl;
  if (this->on && isSetHours && isSetMinutes && isSetSeconds && isSetMilliseconds) {
    //cout << "entro external 2" << endl;
    this->frequency_time = VTime(hours, minutes, seconds, milliseconds);
  }

  return *this;
}

Model &Pulse::internalFunction( const InternalMessage & ) {

  //cout << "entro internal 1" << endl;
  if (this->on && isSetHours && isSetMinutes && isSetSeconds && isSetMilliseconds) {
    //cout << "entro internal 2" << endl;
    holdIn(AtomicState::active, this->frequency_time);
  } else {
   passivate();
  }

  return *this ;
}

Model &Pulse::outputFunction( const CollectMessage &msg ) {

  //cout << "output" << endl;
  sendOutput( msg.time(), out, value);
	return *this ;
}