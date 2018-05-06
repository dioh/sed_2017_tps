#ifndef _CapitalDEVS_BASIC_COUPLED_Capital_H_
#define _CapitalDEVS_BASIC_COUPLED_Capital_H_

#include <string> 

#include "atomic.h"

#define CAPITALDEVS_BASIC_COUPLED_CAPITAL "CapitalDEVS_BASIC_COUPLED_Capital"


class CapitalDEVS_BASIC_COUPLED_Capital : public Atomic {
  public:
    
    CapitalDEVS_BASIC_COUPLED_Capital(const string &name = CAPITALDEVS_BASIC_COUPLED_CAPITAL );
    virtual string className() const {  return CAPITALDEVS_BASIC_COUPLED_CAPITAL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotCapital;
    Port &out_port_Capital;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_Capital;
    double get_param(const string &);
    VTime minposroot(double *coeff);
    double to_seconds(const VTime &);

    // Agregados
    bool non_negative;
    const Port &in_port_subtract;
    const Port &in_port_increment;

};

#endif