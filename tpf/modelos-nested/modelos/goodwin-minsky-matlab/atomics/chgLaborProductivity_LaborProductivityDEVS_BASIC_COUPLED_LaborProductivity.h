#ifndef _chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity_H_
#define _chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGLABORPRODUCTIVITY_LABORPRODUCTIVITYDEVS_BASIC_COUPLED_LABORPRODUCTIVITY "chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity"


class chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity : public Atomic {
  public:
    
    chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity(const string &name = CHGLABORPRODUCTIVITY_LABORPRODUCTIVITYDEVS_BASIC_COUPLED_LABORPRODUCTIVITY );
    virtual string className() const {  return CHGLABORPRODUCTIVITY_LABORPRODUCTIVITYDEVS_BASIC_COUPLED_LABORPRODUCTIVITY ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Alphaa;
    const Port &in_port_LaborProductivity;
    Port &out_port_chgLaborProductivity_LaborProductivity;
    
    double Alphaa;
    double LaborProductivity;
    bool isSet_Alphaa;
    bool isSet_LaborProductivity;
};

#endif