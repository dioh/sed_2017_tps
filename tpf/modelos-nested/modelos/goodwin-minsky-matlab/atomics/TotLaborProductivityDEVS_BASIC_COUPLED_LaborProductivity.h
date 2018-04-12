#ifndef _TotLaborProductivityDEVS_BASIC_COUPLED_LaborProductivity_H_
#define _TotLaborProductivityDEVS_BASIC_COUPLED_LaborProductivity_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTLABORPRODUCTIVITYDEVS_BASIC_COUPLED_LABORPRODUCTIVITY "TotLaborProductivityDEVS_BASIC_COUPLED_LaborProductivity"

class TotLaborProductivityDEVS_BASIC_COUPLED_LaborProductivity : public Atomic {
  public:
    
    TotLaborProductivityDEVS_BASIC_COUPLED_LaborProductivity(const string &name = TOTLABORPRODUCTIVITYDEVS_BASIC_COUPLED_LABORPRODUCTIVITY );
    virtual string className() const {  return TOTLABORPRODUCTIVITYDEVS_BASIC_COUPLED_LABORPRODUCTIVITY ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgLaborProductivity_LaborProductivity;
    
    Port &out_port_TotLaborProductivity;

    double chgLaborProductivity_LaborProductivity;
    bool isSet_chgLaborProductivity_LaborProductivity;
    
    
};

#endif