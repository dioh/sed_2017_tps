#ifndef _DepCons_H_
#define _DepCons_H_

#include <string> 

#include "atomic.h"

#define DEPCONS "DepCons"


class DepCons : public Atomic {
  public:
    
    DepCons(const string &name = DEPCONS );
    virtual string className() const {  return DEPCONS ;}
  
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