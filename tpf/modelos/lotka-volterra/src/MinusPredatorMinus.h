#ifndef _MinusPredatorMinus_H_
#define _MinusPredatorMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define MINUSPREDATORMINUS "MinusPredatorMinus"


class MinusPredatorMinus : public Atomic {
  public:
    
    MinusPredatorMinus(const string &name = MINUSPREDATORMINUS );
    virtual string className() const {  return MINUSPREDATORMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &paramC;
    const Port &Predator;
    Port &out;
    

    double val_paramC;
    double val_Predator;
    bool isSet_val_paramC;
    bool isSet_val_Predator;
    
};

#endif