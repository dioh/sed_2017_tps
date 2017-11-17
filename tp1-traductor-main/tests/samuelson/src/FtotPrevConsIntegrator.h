#ifndef _FtotPrevConsIntegrator_H_
#define _FtotPrevConsIntegrator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FTOTPREVCONSINTEGRATOR "FtotPrevConsIntegrator"

class FtotPrevConsIntegrator : public Atomic {
  public:
    
    FtotPrevConsIntegrator(const string &name = FTOTPREVCONSINTEGRATOR );
    virtual string className() const {  return FTOTPREVCONSINTEGRATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inPlus_ChgPrevCons;
    Port &out;
    

    double val_inPlus_ChgPrevCons;
    bool isSet_val_inPlus_ChgPrevCons;
    
};

#endif