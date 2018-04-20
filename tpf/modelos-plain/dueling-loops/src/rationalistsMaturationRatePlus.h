#ifndef _rationalistsMaturationRatePlus_H_
#define _rationalistsMaturationRatePlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define RATIONALISTSMATURATIONRATEPLUS "rationalistsMaturationRatePlus"


class rationalistsMaturationRatePlus : public Atomic {
  public:
    
    rationalistsMaturationRatePlus(const string &name = RATIONALISTSMATURATIONRATEPLUS );
    virtual string className() const {  return RATIONALISTSMATURATIONRATEPLUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Neutralists;
    const Port &rationalistsInfectivityRate;
    Port &out;
    

    double val_Neutralists;
    double val_rationalistsInfectivityRate;
    bool isSet_val_Neutralists;
    bool isSet_val_rationalistsInfectivityRate;
    
};

#endif