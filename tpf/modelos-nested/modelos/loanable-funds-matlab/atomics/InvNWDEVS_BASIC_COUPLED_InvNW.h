#ifndef _InvNWDEVS_BASIC_COUPLED_InvNW_H_
#define _InvNWDEVS_BASIC_COUPLED_InvNW_H_

#include <string> 

#include "atomic.h"

#define INVNWDEVS_BASIC_COUPLED_INVNW "InvNWDEVS_BASIC_COUPLED_InvNW"


class InvNWDEVS_BASIC_COUPLED_InvNW : public Atomic {
  public:
    
    InvNWDEVS_BASIC_COUPLED_InvNW(const string &name = INVNWDEVS_BASIC_COUPLED_INVNW );
    virtual string className() const {  return INVNWDEVS_BASIC_COUPLED_INVNW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotInvNW;
    Port &out_port_InvNW;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_InvNW;

    double get_param(const string &);

    VTime minposroot(double *coeff);

    double to_seconds(const VTime &);

};

#endif