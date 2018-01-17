#ifndef _NeutralistsTot_H_
#define _NeutralistsTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define NEUTRALISTSTOT "NeutralistsTot"

class NeutralistsTot : public Atomic {
  public:
    
    NeutralistsTot(const string &name = NEUTRALISTSTOT );
    virtual string className() const {  return NEUTRALISTSTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &rationalsToNeutralistsPlus;
    
    const Port &neutralistsToDegeneratesMinus;
    
    const Port &neutralistsToRationalsMinus;
    Port &out;
    

    double val_rationalsToNeutralistsPlus;
    double val_neutralistsToDegeneratesMinus;
    double val_neutralistsToRationalsMinus;
    bool isSet_val_rationalsToNeutralistsPlus;
    
    bool isSet_val_neutralistsToDegeneratesMinus;
    bool isSet_val_neutralistsToRationalsMinus;
    
};

#endif