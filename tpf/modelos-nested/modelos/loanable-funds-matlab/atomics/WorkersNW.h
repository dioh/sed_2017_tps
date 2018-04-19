#ifndef _WorkersNW_H_
#define _WorkersNW_H_

#include <string> 

#include "atomic.h"

#define WORKERSNW "WorkersNW"


class WorkersNW : public Atomic {
  public:
    
    WorkersNW(const string &name = WORKERSNW );
    virtual string className() const {  return WORKERSNW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotWorkersNW;
    Port &out_port_WorkersNW;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_WorkersNW;

    double get_param(const string &);

    VTime minposroot(double *coeff);

    double to_seconds(const VTime &);

};

#endif