#ifndef _PredatorDEVS_BASIC_COUPLED_Predator_H_
#define _PredatorDEVS_BASIC_COUPLED_Predator_H_

#include <string> 

#include "atomic.h"

#define PREDATORDEVS_BASIC_COUPLED_PREDATOR "PredatorDEVS_BASIC_COUPLED_Predator"


class PredatorDEVS_BASIC_COUPLED_Predator : public Atomic {
  public:
    
    PredatorDEVS_BASIC_COUPLED_Predator(const string &name = PREDATORDEVS_BASIC_COUPLED_PREDATOR );
    virtual string className() const {  return PREDATORDEVS_BASIC_COUPLED_PREDATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotPredator;
    Port &out_port_Predator;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_Predator;

    double get_param(const string &);

    VTime minposroot(double *coeff);

    double to_seconds(const VTime &);

};

#endif