#ifndef _TotLaborProductivity_H_
#define _TotLaborProductivity_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTLABORPRODUCTIVITY "TotLaborProductivity"

class TotLaborProductivity : public Atomic {
  public:
    
    TotLaborProductivity(const string &name = TOTLABORPRODUCTIVITY );
    virtual string className() const {  return TOTLABORPRODUCTIVITY ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity;
    
    Port &out_port_TotLaborProductivity;

    double chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity;
    bool isSet_chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity;
    
    
};

#endif