#ifndef _degeneratesRecoveryRatePlus_H_
#define _degeneratesRecoveryRatePlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define DEGENERATESRECOVERYRATEPLUS "degeneratesRecoveryRatePlus"


class degeneratesRecoveryRatePlus : public Atomic {
  public:
    
    degeneratesRecoveryRatePlus(const string &name = DEGENERATESRECOVERYRATEPLUS );
    virtual string className() const {  return DEGENERATESRECOVERYRATEPLUS ;}
  
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