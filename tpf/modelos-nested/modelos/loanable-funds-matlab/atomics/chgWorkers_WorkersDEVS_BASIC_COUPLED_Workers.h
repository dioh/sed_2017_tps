#ifndef _chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers_H_
#define _chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGWORKERS_WORKERSDEVS_BASIC_COUPLED_WORKERS "chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers"


class chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers : public Atomic {
  public:
    
    chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers(const string &name = CHGWORKERS_WORKERSDEVS_BASIC_COUPLED_WORKERS );
    virtual string className() const {  return CHGWORKERS_WORKERSDEVS_BASIC_COUPLED_WORKERS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_ConsW;
    const Port &in_port_WagesC;
    const Port &in_port_WagesI;
    Port &out_port_chgWorkers_Workers;
    
    double ConsW;
    double WagesC;
    double WagesI;
    bool isSet_ConsW;
    bool isSet_WagesC;
    bool isSet_WagesI;
};

#endif