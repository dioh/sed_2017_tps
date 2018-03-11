#ifndef _rationalistsRecoveryRateMinus_H_
#define _rationalistsRecoveryRateMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define RATIONALISTSRECOVERYRATEMINUS "rationalistsRecoveryRateMinus"


class rationalistsRecoveryRateMinus : public Atomic {
  public:
    
    rationalistsRecoveryRateMinus(const string &name = RATIONALISTSRECOVERYRATEMINUS );
    virtual string className() const {  return RATIONALISTSRECOVERYRATEMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &RationalSupporters;
    const Port &infectionLifetime;
    Port &out;
    

    double val_RationalSupporters;
    double val_infectionLifetime;
    bool isSet_val_RationalSupporters;
    bool isSet_val_infectionLifetime;
    
};

#endif