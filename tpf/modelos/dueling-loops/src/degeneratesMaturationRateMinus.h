#ifndef _degeneratesMaturationRateMinus_H_
#define _degeneratesMaturationRateMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define DEGENERATESMATURATIONRATEMINUS "degeneratesMaturationRateMinus"


class degeneratesMaturationRateMinus : public Atomic {
  public:
    
    degeneratesMaturationRateMinus(const string &name = DEGENERATESMATURATIONRATEMINUS );
    virtual string className() const {  return DEGENERATESMATURATIONRATEMINUS ;}
  
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