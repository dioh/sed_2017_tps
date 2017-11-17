#ifndef _Auxinvestment_H_
#define _Auxinvestment_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXINVESTMENT "Auxinvestment"


class Auxinvestment : public Atomic {
  public:
    
    Auxinvestment(const string &name = AUXINVESTMENT );
    virtual string className() const {  return AUXINVESTMENT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_investmentproportionalityrelationbeta;
    const Port &in_consumption;
    const Port &in_prevConsIntegrator;
    // Output ports
    Port &out;

    // State variables
    double investmentproportionalityrelationbeta;
    double consumption;
    double prevConsIntegrator;
    //
    // Check set of state variables
    bool isSet_investmentproportionalityrelationbeta;
    bool isSet_consumption;
    bool isSet_prevConsIntegrator;
    //
};

#endif