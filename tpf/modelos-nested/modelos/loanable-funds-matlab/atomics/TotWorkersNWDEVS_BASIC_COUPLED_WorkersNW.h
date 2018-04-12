#ifndef _TotWorkersNWDEVS_BASIC_COUPLED_WorkersNW_H_
#define _TotWorkersNWDEVS_BASIC_COUPLED_WorkersNW_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTWORKERSNWDEVS_BASIC_COUPLED_WORKERSNW "TotWorkersNWDEVS_BASIC_COUPLED_WorkersNW"

class TotWorkersNWDEVS_BASIC_COUPLED_WorkersNW : public Atomic {
  public:
    
    TotWorkersNWDEVS_BASIC_COUPLED_WorkersNW(const string &name = TOTWORKERSNWDEVS_BASIC_COUPLED_WORKERSNW );
    virtual string className() const {  return TOTWORKERSNWDEVS_BASIC_COUPLED_WORKERSNW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgWorkersNW_WorkersNW;
    
    Port &out_port_TotWorkersNW;

    double chgWorkersNW_WorkersNW;
    bool isSet_chgWorkersNW_WorkersNW;
    
    
};

#endif