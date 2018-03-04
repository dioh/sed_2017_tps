#ifndef _RationalSupportersTot_H_
#define _RationalSupportersTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define RATIONALSUPPORTERSTOT "RationalSupportersTot"

class RationalSupportersTot : public Atomic {
  public:
    
    RationalSupportersTot(const string &name = RATIONALSUPPORTERSTOT );
    virtual string className() const {  return RATIONALSUPPORTERSTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &neutralistsToRationalsPlus;
    
    const Port &rationalsToNeutralistsMinus;
    Port &out;
    

    double val_neutralistsToRationalsPlus;
    double val_rationalsToNeutralistsMinus;
    bool isSet_val_neutralistsToRationalsPlus;
    
    bool isSet_val_rationalsToNeutralistsMinus;
    
};

#endif