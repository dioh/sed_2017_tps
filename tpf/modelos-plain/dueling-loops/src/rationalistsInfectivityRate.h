#ifndef _rationalistsInfectivityRate_H_
#define _rationalistsInfectivityRate_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define RATIONALISTSINFECTIVITYRATE "rationalistsInfectivityRate"


class rationalistsInfectivityRate : public Atomic {
  public:
    
    rationalistsInfectivityRate(const string &name = RATIONALISTSINFECTIVITYRATE );
    virtual string className() const {  return RATIONALISTSINFECTIVITYRATE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &trueMemes;
    const Port &memeticInfectivity;
    const Port &incubationTime;
    Port &out;
    

    double val_trueMemes;
    double val_memeticInfectivity;
    double val_incubationTime;
    bool isSet_val_trueMemes;
    bool isSet_val_memeticInfectivity;
    bool isSet_val_incubationTime;
    
};

#endif