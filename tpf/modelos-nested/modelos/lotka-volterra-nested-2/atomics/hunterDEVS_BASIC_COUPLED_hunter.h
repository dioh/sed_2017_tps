#ifndef _hunterDEVS_BASIC_COUPLED_hunter_H_
#define _hunterDEVS_BASIC_COUPLED_hunter_H_

#include <string> 

#include "atomic.h"

#define HUNTERDEVS_BASIC_COUPLED_HUNTER "hunterDEVS_BASIC_COUPLED_hunter"


class hunterDEVS_BASIC_COUPLED_hunter : public Atomic {
  public:
    
    hunterDEVS_BASIC_COUPLED_hunter(const string &name = HUNTERDEVS_BASIC_COUPLED_HUNTER );
    virtual string className() const {  return HUNTERDEVS_BASIC_COUPLED_HUNTER ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_Tothunter;
    Port &out_port_hunter;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_hunter;
    double get_param(const string &);
    VTime minposroot(double *coeff);
    double to_seconds(const VTime &);

    // Agregados
    bool non_negative;
    const Port &in_port_subtract;
    const Port &in_port_increment;

};

#endif