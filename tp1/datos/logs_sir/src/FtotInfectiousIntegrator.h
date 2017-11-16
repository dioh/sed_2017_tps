#ifndef _FtotInfectiousIntegrator_H_
#define _FtotInfectiousIntegrator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FTOTINFECTIOUSINTEGRATOR "FtotInfectiousIntegrator"

class FtotInfectiousIntegrator : public Atomic {
  public:
    
    FtotInfectiousIntegrator(const string &name = FTOTINFECTIOUSINTEGRATOR );
    virtual string className() const {  return FTOTINFECTIOUSINTEGRATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inMinus_Recovering;
    const Port &inPlus_Succumbing;
    Port &out;
    

    double val_inMinus_Recovering;
    double val_inPlus_Succumbing;
    bool isSet_val_inMinus_Recovering;
    bool isSet_val_inPlus_Succumbing;
    
};

#endif