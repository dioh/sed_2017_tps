#ifndef _PlusPredatorMinus_H_
#define _PlusPredatorMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PLUSPREDATORMINUS "PlusPredatorMinus"


class PlusPredatorMinus : public Atomic {
  public:
    
    PlusPredatorMinus(const string &name = PLUSPREDATORMINUS );
    virtual string className() const {  return PLUSPREDATORMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &paramD;
    const Port &Prey;
    const Port &Predator;
    Port &out;
    

    double val_paramD;
    double val_Prey;
    double val_Predator;
    bool isSet_val_paramD;
    bool isSet_val_Prey;
    bool isSet_val_Predator;
    
};

#endif