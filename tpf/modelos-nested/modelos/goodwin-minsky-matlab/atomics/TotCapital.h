#ifndef _TotCapital_H_
#define _TotCapital_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTCAPITAL "TotCapital"

class TotCapital : public Atomic {
  public:
    
    TotCapital(const string &name = TOTCAPITAL );
    virtual string className() const {  return TOTCAPITAL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgCapital_CapitalDEVS_BASIC_COUPLED_Capital;
    
    Port &out_port_TotCapital;

    double chgCapital_CapitalDEVS_BASIC_COUPLED_Capital;
    bool isSet_chgCapital_CapitalDEVS_BASIC_COUPLED_Capital;
    
    
};

#endif