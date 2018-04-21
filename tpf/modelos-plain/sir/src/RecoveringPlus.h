#ifndef _RecoveringPlus_H_
#define _RecoveringPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define RECOVERINGPLUS "RecoveringPlus"


class RecoveringPlus : public Atomic {
  public:
    
    RecoveringPlus(const string &name = RECOVERINGPLUS );
    virtual string className() const {  return RECOVERINGPLUS ;}
  
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