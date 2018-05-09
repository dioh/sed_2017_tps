#ifndef _TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue_H_
#define _TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue_H_

#include <string> 

#include "atomic.h"

#define TEMPERATUREVALUEDEVS_BASIC_COUPLED_TEMPERATUREVALUE "TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue"


class TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue : public Atomic {
  public:
    
    TemperatureValueDEVS_BASIC_COUPLED_TemperatureValue(const string &name = TEMPERATUREVALUEDEVS_BASIC_COUPLED_TEMPERATUREVALUE );
    virtual string className() const {  return TEMPERATUREVALUEDEVS_BASIC_COUPLED_TEMPERATUREVALUE ;}
  
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

    // Agregados
    bool non_negative;
    const Port &in_port_subtract;
    const Port &in_port_increment;

};

#endif