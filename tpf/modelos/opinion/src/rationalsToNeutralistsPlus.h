#ifndef _rationalsToNeutralistsPlus_H_
#define _rationalsToNeutralistsPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define RATIONALSTONEUTRALISTSPLUS "rationalsToNeutralistsPlus"


class rationalsToNeutralistsPlus : public Atomic {
  public:
    
    rationalsToNeutralistsPlus(const string &name = RATIONALSTONEUTRALISTSPLUS );
    virtual string className() const {  return RATIONALSTONEUTRALISTSPLUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &RationalSupporters;
    Port &out;
    

    double val_RationalSupporters;
    bool isSet_val_RationalSupporters;
    
};

#endif