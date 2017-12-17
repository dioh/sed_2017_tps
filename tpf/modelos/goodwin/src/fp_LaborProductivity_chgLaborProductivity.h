#ifndef _fp_LaborProductivity_chgLaborProductivity_H_
#define _fp_LaborProductivity_chgLaborProductivity_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FP_LABORPRODUCTIVITY_CHGLABORPRODUCTIVITY "fp_LaborProductivity_chgLaborProductivity"

class fp_LaborProductivity_chgLaborProductivity : public Atomic {
  public:
    fp_LaborProductivity_chgLaborProductivity(const string &name = FP_LABORPRODUCTIVITY_CHGLABORPRODUCTIVITY );
    virtual string className() const {  return FP_LABORPRODUCTIVITY_CHGLABORPRODUCTIVITY ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_Alphaa;
    const Port &in_LaborProductivity;
    Port &out;
    

    double Alphaa;
    double LaborProductivity;
    bool isSet_Alphaa;
    bool isSet_LaborProductivity;
    //
};

#endif