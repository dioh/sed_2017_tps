#ifndef _AuxeffectofRatioofStocktoCapacityonGrowthCoefficient_H_
#define _AuxeffectofRatioofStocktoCapacityonGrowthCoefficient_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXEFFECTOFRATIOOFSTOCKTOCAPACITYONGROWTHCOEFFICIENT "AuxeffectofRatioofStocktoCapacityonGrowthCoefficient"


class AuxeffectofRatioofStocktoCapacityonGrowthCoefficient : public Atomic {
  public:
    
    AuxeffectofRatioofStocktoCapacityonGrowthCoefficient(const string &name = AUXEFFECTOFRATIOOFSTOCKTOCAPACITYONGROWTHCOEFFICIENT );
    virtual string className() const {  return AUXEFFECTOFRATIOOFSTOCKTOCAPACITYONGROWTHCOEFFICIENT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_ratioofStocktoCapacity;
    // Output ports
    Port &out;

    // State variables
    double ratioofStocktoCapacity;
    //
    // Check set of state variables
    bool isSet_ratioofStocktoCapacity;
    //
};

#endif