#ifndef _FtotPreviousOutputIntegrator_H_
#define _FtotPreviousOutputIntegrator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FTOTPREVIOUSOUTPUTINTEGRATOR "FtotPreviousOutputIntegrator"

class FtotPreviousOutputIntegrator : public Atomic {
  public:
    
    FtotPreviousOutputIntegrator(const string &name = FTOTPREVIOUSOUTPUTINTEGRATOR );
    virtual string className() const {  return FTOTPREVIOUSOUTPUTINTEGRATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inPlus_ChgPreviousOutput;
    Port &out;
    

    double val_inPlus_ChgPreviousOutput;
    bool isSet_val_inPlus_ChgPreviousOutput;
    
};

#endif