#ifndef _rationalsToNeutralistsMinus_H_
#define _rationalsToNeutralistsMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define RATIONALSTONEUTRALISTSMINUS "rationalsToNeutralistsMinus"


class rationalsToNeutralistsMinus : public Atomic {
  public:
    
    rationalsToNeutralistsMinus(const string &name = RATIONALSTONEUTRALISTSMINUS );
    virtual string className() const {  return RATIONALSTONEUTRALISTSMINUS ;}
  
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