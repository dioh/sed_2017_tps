#ifndef _TotConsNWDEVS_BASIC_COUPLED_ConsNW_H_
#define _TotConsNWDEVS_BASIC_COUPLED_ConsNW_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTCONSNWDEVS_BASIC_COUPLED_CONSNW "TotConsNWDEVS_BASIC_COUPLED_ConsNW"

class TotConsNWDEVS_BASIC_COUPLED_ConsNW : public Atomic {
  public:
    
    TotConsNWDEVS_BASIC_COUPLED_ConsNW(const string &name = TOTCONSNWDEVS_BASIC_COUPLED_CONSNW );
    virtual string className() const {  return TOTCONSNWDEVS_BASIC_COUPLED_CONSNW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgConsNW_ConsNW;
    
    Port &out_port_TotConsNW;

    double chgConsNW_ConsNW;
    bool isSet_chgConsNW_ConsNW;
    
    
};

#endif