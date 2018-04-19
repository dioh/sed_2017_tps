#ifndef _InvNW_H_
#define _InvNW_H_

#include <string> 

#include "atomic.h"

#define INVNW "InvNW"


class InvNW : public Atomic {
  public:
    
    InvNW(const string &name = INVNW );
    virtual string className() const {  return INVNW ;}
  
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