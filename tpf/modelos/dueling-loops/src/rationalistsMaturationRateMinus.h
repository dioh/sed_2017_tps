#ifndef _rationalistsMaturationRateMinus_H_
#define _rationalistsMaturationRateMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define RATIONALISTSMATURATIONRATEMINUS "rationalistsMaturationRateMinus"


class rationalistsMaturationRateMinus : public Atomic {
  public:
    
    rationalistsMaturationRateMinus(const string &name = RATIONALISTSMATURATIONRATEMINUS );
    virtual string className() const {  return RATIONALISTSMATURATIONRATEMINUS ;}
  
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