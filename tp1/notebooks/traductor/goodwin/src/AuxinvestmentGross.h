#ifndef _AuxinvestmentGross_H_
#define _AuxinvestmentGross_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXINVESTMENTGROSS "AuxinvestmentGross"


class AuxinvestmentGross : public Atomic {
  public:
    
    AuxinvestmentGross(const string &name = AUXINVESTMENTGROSS );
    virtual string className() const {  return AUXINVESTMENTGROSS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_profit;
    // Output ports
    Port &out;

    // State variables
    double profit;
    //
    // Check set of state variables
    bool isSet_profit;
    //
};

#endif