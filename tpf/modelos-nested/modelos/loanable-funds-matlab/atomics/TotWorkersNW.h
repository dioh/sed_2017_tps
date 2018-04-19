#ifndef _TotWorkersNW_H_
#define _TotWorkersNW_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTWORKERSNW "TotWorkersNW"

class TotWorkersNW : public Atomic {
  public:
    
    TotWorkersNW(const string &name = TOTWORKERSNW );
    virtual string className() const {  return TOTWORKERSNW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW;
    
    Port &out_port_TotWorkersNW;

    double chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW;
    bool isSet_chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW;
    
    
};

#endif