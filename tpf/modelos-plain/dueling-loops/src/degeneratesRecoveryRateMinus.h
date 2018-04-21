#ifndef _degeneratesRecoveryRateMinus_H_
#define _degeneratesRecoveryRateMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define DEGENERATESRECOVERYRATEMINUS "degeneratesRecoveryRateMinus"


class degeneratesRecoveryRateMinus : public Atomic {
  public:
    
    degeneratesRecoveryRateMinus(const string &name = DEGENERATESRECOVERYRATEMINUS );
    virtual string className() const {  return DEGENERATESRECOVERYRATEMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Degenerates;
    const Port &infectionLifetime;
    Port &out;
    

    double val_Degenerates;
    double val_infectionLifetime;
    bool isSet_val_Degenerates;
    bool isSet_val_infectionLifetime;
    
};

#endif