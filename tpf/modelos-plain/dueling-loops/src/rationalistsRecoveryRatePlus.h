#ifndef _rationalistsRecoveryRatePlus_H_
#define _rationalistsRecoveryRatePlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define RATIONALISTSRECOVERYRATEPLUS "rationalistsRecoveryRatePlus"


class rationalistsRecoveryRatePlus : public Atomic {
  public:
    
    rationalistsRecoveryRatePlus(const string &name = RATIONALISTSRECOVERYRATEPLUS );
    virtual string className() const {  return RATIONALISTSRECOVERYRATEPLUS ;}
  
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