#ifndef _AuxinvestmentNetReal_H_
#define _AuxinvestmentNetReal_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXINVESTMENTNETREAL "AuxinvestmentNetReal"


class AuxinvestmentNetReal : public Atomic {
  public:
    
    AuxinvestmentNetReal(const string &name = AUXINVESTMENTNETREAL );
    virtual string className() const {  return AUXINVESTMENTNETREAL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_investmentGross;
    const Port &in_capitalIntegrator;
    const Port &in_rateOfAppreciation;
    // Output ports
    Port &out;

    // State variables
    double investmentGross;
    double rateOfAppreciation;
    double capitalIntegrator;
    //
    // Check set of state variables
    bool isSet_investmentGross;
    bool isSet_rateOfAppreciation;
    bool isSet_capitalIntegrator;
    //
};

#endif