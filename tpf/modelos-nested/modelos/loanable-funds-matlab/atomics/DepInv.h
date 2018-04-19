#ifndef _DepInv_H_
#define _DepInv_H_

#include <string> 

#include "atomic.h"

#define DEPINV "DepInv"


class DepInv : public Atomic {
  public:
    
    DepInv(const string &name = DEPINV );
    virtual string className() const {  return DEPINV ;}
  
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