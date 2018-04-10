#ifndef _WorkersNWDEVS_BASIC_COUPLED_WorkersNW_H_
#define _WorkersNWDEVS_BASIC_COUPLED_WorkersNW_H_

#include <string> 

#include "atomic.h"

#define WORKERSNWDEVS_BASIC_COUPLED_WORKERSNW "WorkersNWDEVS_BASIC_COUPLED_WorkersNW"


class WorkersNWDEVS_BASIC_COUPLED_WorkersNW : public Atomic {
  public:
    
    WorkersNWDEVS_BASIC_COUPLED_WorkersNW(const string &name = WORKERSNWDEVS_BASIC_COUPLED_WORKERSNW );
    virtual string className() const {  return WORKERSNWDEVS_BASIC_COUPLED_WORKERSNW ;}
  
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