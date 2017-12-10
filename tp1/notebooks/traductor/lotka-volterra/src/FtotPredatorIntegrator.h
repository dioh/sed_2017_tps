#ifndef _FtotPredatorIntegrator_H_
#define _FtotPredatorIntegrator_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FTOTPREDATORINTEGRATOR "FtotPredatorIntegrator"

class FtotPredatorIntegrator : public Atomic {
  public:
    
    FtotPredatorIntegrator(const string &name = FTOTPREDATORINTEGRATOR );
    virtual string className() const {  return FTOTPREDATORINTEGRATOR ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &inMinus_MinusPredator;
    const Port &inPlus_PlusPredator;
    Port &out;
    

    double val_inMinus_MinusPredator;
    double val_inPlus_PlusPredator;
    bool isSet_val_inMinus_MinusPredator;
    bool isSet_val_inPlus_PlusPredator;
    
};

#endif