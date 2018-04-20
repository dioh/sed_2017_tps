#ifndef _degeneratesInfectivityRate_H_
#define _degeneratesInfectivityRate_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define DEGENERATESINFECTIVITYRATE "degeneratesInfectivityRate"


class degeneratesInfectivityRate : public Atomic {
  public:
    
    degeneratesInfectivityRate(const string &name = DEGENERATESINFECTIVITYRATE );
    virtual string className() const {  return DEGENERATESINFECTIVITYRATE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &falseMemes;
    const Port &memeticInfectivity;
    const Port &incubationTime;
    Port &out;
    

    double val_falseMemes;
    double val_memeticInfectivity;
    double val_incubationTime;
    bool isSet_val_falseMemes;
    bool isSet_val_memeticInfectivity;
    bool isSet_val_incubationTime;
    
};

#endif