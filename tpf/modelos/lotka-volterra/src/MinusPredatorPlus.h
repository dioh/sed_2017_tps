#ifndef _MinusPredatorPlus_H_
#define _MinusPredatorPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define MINUSPREDATORPLUS "MinusPredatorPlus"


class MinusPredatorPlus : public Atomic {
  public:
    
    MinusPredatorPlus(const string &name = MINUSPREDATORPLUS );
    virtual string className() const {  return MINUSPREDATORPLUS ;}
  
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