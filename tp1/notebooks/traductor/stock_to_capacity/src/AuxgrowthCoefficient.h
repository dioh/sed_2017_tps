#ifndef _AuxgrowthCoefficient_H_
#define _AuxgrowthCoefficient_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXGROWTHCOEFFICIENT "AuxgrowthCoefficient"


class AuxgrowthCoefficient : public Atomic {
  public:
    
    AuxgrowthCoefficient(const string &name = AUXGROWTHCOEFFICIENT );
    virtual string className() const {  return AUXGROWTHCOEFFICIENT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_effectofRatioofStocktoCapacityonGrowthCoefficient;
    // Output ports
    Port &out;

    // State variables
    double effectofRatioofStocktoCapacityonGrowthCoefficient;
    //
    // Check set of state variables
    bool isSet_effectofRatioofStocktoCapacityonGrowthCoefficient;
    //
};

#endif