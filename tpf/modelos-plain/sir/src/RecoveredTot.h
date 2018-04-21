#ifndef _RecoveredTot_H_
#define _RecoveredTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define RECOVEREDTOT "RecoveredTot"

class RecoveredTot : public Atomic {
  public:
    
    RecoveredTot(const string &name = RECOVEREDTOT );
    virtual string className() const {  return RECOVEREDTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &RecoveringPlus;
    Port &out;
    

    double val_RecoveringPlus;
    bool isSet_val_RecoveringPlus;
    
    
};

#endif