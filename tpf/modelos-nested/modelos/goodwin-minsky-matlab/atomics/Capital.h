#ifndef _Capital_H_
#define _Capital_H_

#include <string> 

#include "atomic.h"

#define CAPITAL "Capital"


class Capital : public Atomic {
  public:
    
    Capital(const string &name = CAPITAL );
    virtual string className() const {  return CAPITAL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotCapital;
    Port &out_port_Capital;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_Capital;

    double get_param(const string &);

    VTime minposroot(double *coeff);

    double to_seconds(const VTime &);

};

#endif