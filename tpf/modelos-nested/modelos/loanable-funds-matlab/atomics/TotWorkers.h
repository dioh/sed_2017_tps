#ifndef _TotWorkers_H_
#define _TotWorkers_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTWORKERS "TotWorkers"

class TotWorkers : public Atomic {
  public:
    
    TotWorkers(const string &name = TOTWORKERS );
    virtual string className() const {  return TOTWORKERS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers;
    
    Port &out_port_TotWorkers;

    double chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers;
    bool isSet_chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers;
    
    
};

#endif