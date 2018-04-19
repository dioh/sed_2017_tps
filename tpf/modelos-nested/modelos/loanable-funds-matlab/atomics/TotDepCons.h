#ifndef _TotDepCons_H_
#define _TotDepCons_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTDEPCONS "TotDepCons"

class TotDepCons : public Atomic {
  public:
    
    TotDepCons(const string &name = TOTDEPCONS );
    virtual string className() const {  return TOTDEPCONS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons;
    
    Port &out_port_TotDepCons;

    double chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons;
    bool isSet_chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons;
    
    
};

#endif