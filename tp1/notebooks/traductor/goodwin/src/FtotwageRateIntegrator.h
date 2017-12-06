#ifndef _FtotwageRateIntegrator_H_
#define _FtotwageRateIntegrator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FTOTWAGERATEINTEGRATOR "FtotwageRateIntegrator"

class FtotwageRateIntegrator : public Atomic {
  public:
    
    FtotwageRateIntegrator(const string &name = FTOTWAGERATEINTEGRATOR );
    virtual string className() const {  return FTOTWAGERATEINTEGRATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inPlus_chgWageRate;
    Port &out;
    

    double val_inPlus_chgWageRate;
    bool isSet_val_inPlus_chgWageRate;
    
};

#endif