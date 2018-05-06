#ifndef _wageRateDEVS_BASIC_COUPLED_wageRate_H_
#define _wageRateDEVS_BASIC_COUPLED_wageRate_H_

#include <string> 

#include "atomic.h"

#define WAGERATEDEVS_BASIC_COUPLED_WAGERATE "wageRateDEVS_BASIC_COUPLED_wageRate"


class wageRateDEVS_BASIC_COUPLED_wageRate : public Atomic {
  public:
    
    wageRateDEVS_BASIC_COUPLED_wageRate(const string &name = WAGERATEDEVS_BASIC_COUPLED_WAGERATE );
    virtual string className() const {  return WAGERATEDEVS_BASIC_COUPLED_WAGERATE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotwageRate;
    Port &out_port_wageRate;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_wageRate;
    double get_param(const string &);
    VTime minposroot(double *coeff);
    double to_seconds(const VTime &);

    // Agregados
    bool non_negative;
    const Port &in_port_subtract;
    const Port &in_port_increment;

};

#endif