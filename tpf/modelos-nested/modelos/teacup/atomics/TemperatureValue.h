#ifndef _TemperatureValue_H_
#define _TemperatureValue_H_

#include <string> 

#include "atomic.h"

#define TEMPERATUREVALUE "TemperatureValue"


class TemperatureValue : public Atomic {
  public:
    
    TemperatureValue(const string &name = TEMPERATUREVALUE );
    virtual string className() const {  return TEMPERATUREVALUE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotTemperatureValue;
    Port &out_port_TemperatureValue;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_TemperatureValue;

    double get_param(const string &);

    VTime minposroot(double *coeff);

    double to_seconds(const VTime &);

};

#endif