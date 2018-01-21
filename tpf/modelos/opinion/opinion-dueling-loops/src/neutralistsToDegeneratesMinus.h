#ifndef _neutralistsToDegeneratesMinus_H_
#define _neutralistsToDegeneratesMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define NEUTRALISTSTODEGENERATESMINUS "neutralistsToDegeneratesMinus"


class neutralistsToDegeneratesMinus : public Atomic {
  public:
    
    neutralistsToDegeneratesMinus(const string &name = NEUTRALISTSTODEGENERATESMINUS );
    virtual string className() const {  return NEUTRALISTSTODEGENERATESMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Neutralists;
    Port &out;
    

    double val_Neutralists;
    bool isSet_val_Neutralists;
    
};

#endif