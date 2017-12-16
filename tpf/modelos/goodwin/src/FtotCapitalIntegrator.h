#ifndef _FtotCapitalIntegrator_H_
#define _FtotCapitalIntegrator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FTOTCAPITALINTEGRATOR "FtotCapitalIntegrator"

class FtotCapitalIntegrator : public Atomic {
  public:
    
    FtotCapitalIntegrator(const string &name = FTOTCAPITALINTEGRATOR );
    virtual string className() const {  return FTOTCAPITALINTEGRATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inPlus_chgCapital;
    Port &out;
    

    double val_inPlus_chgCapital;
    bool isSet_val_inPlus_chgCapital;
    
};

#endif