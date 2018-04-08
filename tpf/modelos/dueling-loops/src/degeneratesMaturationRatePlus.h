#ifndef _degeneratesMaturationRatePlus_H_
#define _degeneratesMaturationRatePlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define DEGENERATESMATURATIONRATEPLUS "degeneratesMaturationRatePlus"


class degeneratesMaturationRatePlus : public Atomic {
  public:
    
    degeneratesMaturationRatePlus(const string &name = DEGENERATESMATURATIONRATEPLUS );
    virtual string className() const {  return DEGENERATESMATURATIONRATEPLUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Neutralists;
    const Port &degeneratesInfectivityRate;
    Port &out;
    

    double val_Neutralists;
    double val_degeneratesInfectivityRate;
    bool isSet_val_Neutralists;
    bool isSet_val_degeneratesInfectivityRate;
    
};

#endif