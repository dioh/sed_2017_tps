#ifndef _AuxwageFunction_H_
#define _AuxwageFunction_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define AUXWAGEFUNCTION "AuxwageFunction"


class AuxwageFunction : public Atomic {
  public:
    
    AuxwageFunction(const string &name = AUXWAGEFUNCTION );
    virtual string className() const {  return AUXWAGEFUNCTION ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in_employmentRate;
    const Port &in_constantEmploymentRate;
    const Port &in_effectOfEmploymentRateInWages;
    // Output ports
    Port &out;

    // State variables
    double effectOfEmploymentRateInWages;
    double constantEmploymentRate;
    double employmentRate;
    //
    // Check set of state variables
    bool isSet_effectOfEmploymentRateInWages;
    bool isSet_constantEmploymentRate;
    bool isSet_employmentRate;
    //
};

#endif