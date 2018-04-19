#ifndef _TotConsNW_H_
#define _TotConsNW_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTCONSNW "TotConsNW"

class TotConsNW : public Atomic {
  public:
    
    TotConsNW(const string &name = TOTCONSNW );
    virtual string className() const {  return TOTCONSNW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW;
    
    Port &out_port_TotConsNW;

    double chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW;
    bool isSet_chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW;
    
    
};

#endif