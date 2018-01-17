#ifndef _RecoveringMinus_H_
#define _RecoveringMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define RECOVERINGMINUS "RecoveringMinus"


class RecoveringMinus : public Atomic {
  public:
    
    RecoveringMinus(const string &name = RECOVERINGMINUS );
    virtual string className() const {  return RECOVERINGMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Infected;
    const Port &Duration;
    Port &out;
    

    double val_Infected;
    double val_Duration;
    bool isSet_val_Infected;
    bool isSet_val_Duration;
    
};

#endif