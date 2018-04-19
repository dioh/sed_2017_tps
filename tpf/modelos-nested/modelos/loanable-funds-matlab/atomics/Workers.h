#ifndef _Workers_H_
#define _Workers_H_

#include <string> 

#include "atomic.h"

#define WORKERS "Workers"


class Workers : public Atomic {
  public:
    
    Workers(const string &name = WORKERS );
    virtual string className() const {  return WORKERS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotWorkers;
    Port &out_port_Workers;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_Workers;

    double get_param(const string &);

    VTime minposroot(double *coeff);

    double to_seconds(const VTime &);

};

#endif