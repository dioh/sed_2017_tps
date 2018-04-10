#ifndef _WorkersDEVS_BASIC_COUPLED_Workers_H_
#define _WorkersDEVS_BASIC_COUPLED_Workers_H_

#include <string> 

#include "atomic.h"

#define WORKERSDEVS_BASIC_COUPLED_WORKERS "WorkersDEVS_BASIC_COUPLED_Workers"


class WorkersDEVS_BASIC_COUPLED_Workers : public Atomic {
  public:
    
    WorkersDEVS_BASIC_COUPLED_Workers(const string &name = WORKERSDEVS_BASIC_COUPLED_WORKERS );
    virtual string className() const {  return WORKERSDEVS_BASIC_COUPLED_WORKERS ;}
  
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