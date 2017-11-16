#ifndef _FtotRecoveredIntegrator_H_
#define _FtotRecoveredIntegrator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FTOTRECOVEREDINTEGRATOR "FtotRecoveredIntegrator"

class FtotRecoveredIntegrator : public Atomic {
  public:
    
    FtotRecoveredIntegrator(const string &name = FTOTRECOVEREDINTEGRATOR );
    virtual string className() const {  return FTOTRECOVEREDINTEGRATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inPlus_Recovering;
    Port &out;
    

    double val_inPlus_Recovering;
    bool isSet_val_inPlus_Recovering;
    
};

#endif