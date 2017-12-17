#ifndef _FtotInvestmentIntegrator_H_
#define _FtotInvestmentIntegrator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FTOTINVESTMENTINTEGRATOR "FtotInvestmentIntegrator"

class FtotInvestmentIntegrator : public Atomic {
  public:
    
    FtotInvestmentIntegrator(const string &name = FTOTINVESTMENTINTEGRATOR );
    virtual string className() const {  return FTOTINVESTMENTINTEGRATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inPlus_inflow;
    Port &out;
    

    double val_inPlus_inflow;
    bool isSet_val_inPlus_inflow;
    
};

#endif