#ifndef _wageRate_H_
#define _wageRate_H_

#include <string> 

#include "atomic.h"

#define WAGERATE "wageRate"


class wageRate : public Atomic {
  public:
    
    wageRate(const string &name = WAGERATE );
    virtual string className() const {  return WAGERATE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotwageRate;
    Port &out_port_wageRate;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_wageRate;

    double get_param(const string &);

    VTime minposroot(double *coeff);

    double to_seconds(const VTime &);

};

#endif