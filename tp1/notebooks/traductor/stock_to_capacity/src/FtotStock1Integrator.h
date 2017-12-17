#ifndef _FtotStock1Integrator_H_
#define _FtotStock1Integrator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FTOTSTOCK1INTEGRATOR "FtotStock1Integrator"

class FtotStock1Integrator : public Atomic {
  public:
    
    FtotStock1Integrator(const string &name = FTOTSTOCK1INTEGRATOR );
    virtual string className() const {  return FTOTSTOCK1INTEGRATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inPlus_Flow1;
    Port &out;
    

    double val_inPlus_Flow1;
    bool isSet_val_inPlus_Flow1;
    
};

#endif