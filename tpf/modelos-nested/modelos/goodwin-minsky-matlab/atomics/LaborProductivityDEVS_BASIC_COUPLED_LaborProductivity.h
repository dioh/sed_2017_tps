#ifndef _LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity_H_
#define _LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity_H_

#include <string> 

#include "atomic.h"

#define LABORPRODUCTIVITYDEVS_BASIC_COUPLED_LABORPRODUCTIVITY "LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity"


class LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity : public Atomic {
  public:
    
    LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity(const string &name = LABORPRODUCTIVITYDEVS_BASIC_COUPLED_LABORPRODUCTIVITY );
    virtual string className() const {  return LABORPRODUCTIVITYDEVS_BASIC_COUPLED_LABORPRODUCTIVITY ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotLaborProductivity;
    Port &out_port_LaborProductivity;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_LaborProductivity;

    double get_param(const string &);

    VTime minposroot(double *coeff);

    double to_seconds(const VTime &);

};

#endif