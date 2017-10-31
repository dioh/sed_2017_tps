#ifndef _FtotSusceptibleIntegrator_H_
#define _FtotSusceptibleIntegrator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FTOTSUSCEPTIBLEINTEGRATOR "FtotSusceptibleIntegrator"

class FtotSusceptibleIntegrator : public Atomic {
  public:
    
    FtotSusceptibleIntegrator(const string &name = FTOTSUSCEPTIBLEINTEGRATOR );
    virtual string className() const {  return FTOTSUSCEPTIBLEINTEGRATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inMinus_Succumbing;
    Port &out;
    

    double val_inMinus_Succumbing;
    bool isSet_val_inMinus_Succumbing;
    
};

#endif