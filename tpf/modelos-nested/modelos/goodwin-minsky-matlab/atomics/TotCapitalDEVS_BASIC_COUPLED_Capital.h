#ifndef _TotCapitalDEVS_BASIC_COUPLED_Capital_H_
#define _TotCapitalDEVS_BASIC_COUPLED_Capital_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTCAPITALDEVS_BASIC_COUPLED_CAPITAL "TotCapitalDEVS_BASIC_COUPLED_Capital"

class TotCapitalDEVS_BASIC_COUPLED_Capital : public Atomic {
  public:
    
    TotCapitalDEVS_BASIC_COUPLED_Capital(const string &name = TOTCAPITALDEVS_BASIC_COUPLED_CAPITAL );
    virtual string className() const {  return TOTCAPITALDEVS_BASIC_COUPLED_CAPITAL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgCapital_Capital;
    
    Port &out_port_TotCapital;

    double chgCapital_Capital;
    bool isSet_chgCapital_Capital;
    
    
};

#endif