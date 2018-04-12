#ifndef _TotWorkersDEVS_BASIC_COUPLED_Workers_H_
#define _TotWorkersDEVS_BASIC_COUPLED_Workers_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTWORKERSDEVS_BASIC_COUPLED_WORKERS "TotWorkersDEVS_BASIC_COUPLED_Workers"

class TotWorkersDEVS_BASIC_COUPLED_Workers : public Atomic {
  public:
    
    TotWorkersDEVS_BASIC_COUPLED_Workers(const string &name = TOTWORKERSDEVS_BASIC_COUPLED_WORKERS );
    virtual string className() const {  return TOTWORKERSDEVS_BASIC_COUPLED_WORKERS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgWorkers_Workers;
    
    Port &out_port_TotWorkers;

    double chgWorkers_Workers;
    bool isSet_chgWorkers_Workers;
    
    
};

#endif