#ifndef _FtotPreyIntegrator_H_
#define _FtotPreyIntegrator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FTOTPREYINTEGRATOR "FtotPreyIntegrator"

class FtotPreyIntegrator : public Atomic {
  public:
    
    FtotPreyIntegrator(const string &name = FTOTPREYINTEGRATOR );
    virtual string className() const {  return FTOTPREYINTEGRATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inMinus_MinusPrey;
    const Port &inPlus_PlusPrey;
    Port &out;
    

    double val_inMinus_MinusPrey;
    double val_inPlus_PlusPrey;
    bool isSet_val_inMinus_MinusPrey;
    bool isSet_val_inPlus_PlusPrey;
    
};

#endif