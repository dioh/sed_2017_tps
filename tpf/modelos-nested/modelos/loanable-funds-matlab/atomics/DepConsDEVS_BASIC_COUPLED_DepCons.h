#ifndef _DepConsDEVS_BASIC_COUPLED_DepCons_H_
#define _DepConsDEVS_BASIC_COUPLED_DepCons_H_

#include <string> 

#include "atomic.h"

#define DEPCONSDEVS_BASIC_COUPLED_DEPCONS "DepConsDEVS_BASIC_COUPLED_DepCons"


class DepConsDEVS_BASIC_COUPLED_DepCons : public Atomic {
  public:
    
    DepConsDEVS_BASIC_COUPLED_DepCons(const string &name = DEPCONSDEVS_BASIC_COUPLED_DEPCONS );
    virtual string className() const {  return DEPCONSDEVS_BASIC_COUPLED_DEPCONS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotDepCons;
    Port &out_port_DepCons;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_DepCons;

    double get_param(const string &);

    VTime minposroot(double *coeff);

    double to_seconds(const VTime &);

};

#endif