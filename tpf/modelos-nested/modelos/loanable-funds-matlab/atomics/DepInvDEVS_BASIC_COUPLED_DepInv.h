#ifndef _DepInvDEVS_BASIC_COUPLED_DepInv_H_
#define _DepInvDEVS_BASIC_COUPLED_DepInv_H_

#include <string> 

#include "atomic.h"

#define DEPINVDEVS_BASIC_COUPLED_DEPINV "DepInvDEVS_BASIC_COUPLED_DepInv"


class DepInvDEVS_BASIC_COUPLED_DepInv : public Atomic {
  public:
    
    DepInvDEVS_BASIC_COUPLED_DepInv(const string &name = DEPINVDEVS_BASIC_COUPLED_DEPINV );
    virtual string className() const {  return DEPINVDEVS_BASIC_COUPLED_DEPINV ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotDepInv;
    Port &out_port_DepInv;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_DepInv;

    double get_param(const string &);

    VTime minposroot(double *coeff);

    double to_seconds(const VTime &);

};

#endif