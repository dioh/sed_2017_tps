#ifndef _FtotPrevOutptIntegrator_H_
#define _FtotPrevOutptIntegrator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FTOTPREVOUTPTINTEGRATOR "FtotPrevOutptIntegrator"

class FtotPrevOutptIntegrator : public Atomic {
  public:
    
    FtotPrevOutptIntegrator(const string &name = FTOTPREVOUTPTINTEGRATOR );
    virtual string className() const {  return FTOTPREVOUTPTINTEGRATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inPlus_ChgPrevOutpt;
    Port &out;
    

    double val_inPlus_ChgPrevOutpt;
    bool isSet_val_inPlus_ChgPrevOutpt;
    
};

#endif