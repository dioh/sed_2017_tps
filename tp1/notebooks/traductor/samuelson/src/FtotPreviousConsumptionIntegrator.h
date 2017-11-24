#ifndef _FtotPreviousConsumptionIntegrator_H_
#define _FtotPreviousConsumptionIntegrator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FTOTPREVIOUSCONSUMPTIONINTEGRATOR "FtotPreviousConsumptionIntegrator"

class FtotPreviousConsumptionIntegrator : public Atomic {
  public:
    
    FtotPreviousConsumptionIntegrator(const string &name = FTOTPREVIOUSCONSUMPTIONINTEGRATOR );
    virtual string className() const {  return FTOTPREVIOUSCONSUMPTIONINTEGRATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inPlus_ChgPreviousConsumption;
    Port &out;
    

    double val_inPlus_ChgPreviousConsumption;
    bool isSet_val_inPlus_ChgPreviousConsumption;
    
};

#endif