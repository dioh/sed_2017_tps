#ifndef _TotDepConsDEVS_BASIC_COUPLED_DepCons_H_
#define _TotDepConsDEVS_BASIC_COUPLED_DepCons_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTDEPCONSDEVS_BASIC_COUPLED_DEPCONS "TotDepConsDEVS_BASIC_COUPLED_DepCons"

class TotDepConsDEVS_BASIC_COUPLED_DepCons : public Atomic {
  public:
    
    TotDepConsDEVS_BASIC_COUPLED_DepCons(const string &name = TOTDEPCONSDEVS_BASIC_COUPLED_DEPCONS );
    virtual string className() const {  return TOTDEPCONSDEVS_BASIC_COUPLED_DEPCONS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgDepCons_DepCons;
    
    Port &out_port_TotDepCons;

    double chgDepCons_DepCons;
    bool isSet_chgDepCons_DepCons;
    
    
};

#endif