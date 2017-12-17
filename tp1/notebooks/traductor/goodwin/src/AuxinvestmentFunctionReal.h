#ifndef _AuxinvestmentFunctionReal_H_
#define _AuxinvestmentFunctionReal_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXINVESTMENTFUNCTIONREAL "AuxinvestmentFunctionReal"


class AuxinvestmentFunctionReal : public Atomic {
  public:
    
    AuxinvestmentFunctionReal(const string &name = AUXINVESTMENTFUNCTIONREAL );
    virtual string className() const {  return AUXINVESTMENTFUNCTIONREAL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_piR;
    const Port &in_piZ;
    const Port &in_piS;
    // Output ports
    Port &out;

    // State variables
    double piR;
    double piS;
    double piZ;
    //
    // Check set of state variables
    bool isSet_piR;
    bool isSet_piS;
    bool isSet_piZ;
    //
};

#endif