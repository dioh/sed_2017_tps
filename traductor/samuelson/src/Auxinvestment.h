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
    const Port &in_Investmentproportionalityrelationbeta;
    const Port &in_consumption;
    const Port &in_previousconsumptionIntegrator;
    // Output ports
    Port &out;

    // State variables
    double previousconsumptionIntegrator;
    double Investmentproportionalityrelationbeta;
    double consumption;
    //
    // Check set of state variables
    bool isSet_previousconsumptionIntegrator;
    bool isSet_Investmentproportionalityrelationbeta;
    bool isSet_consumption;
    //
};

#endif