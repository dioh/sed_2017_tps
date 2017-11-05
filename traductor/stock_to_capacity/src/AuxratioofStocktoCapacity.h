#ifndef _AuxratioofStocktoCapacity_H_
#define _AuxratioofStocktoCapacity_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXRATIOOFSTOCKTOCAPACITY "AuxratioofStocktoCapacity"


class AuxratioofStocktoCapacity : public Atomic {
  public:
    
    AuxratioofStocktoCapacity(const string &name = AUXRATIOOFSTOCKTOCAPACITY );
    virtual string className() const {  return AUXRATIOOFSTOCKTOCAPACITY ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_stock1Integrator;
    const Port &in_maximumCapacityofStock;
    // Output ports
    Port &out;

    // State variables
    double maximumCapacityofStock;
    double stock1Integrator;
    //
    // Check set of state variables
    bool isSet_maximumCapacityofStock;
    bool isSet_stock1Integrator;
    //
};

#endif