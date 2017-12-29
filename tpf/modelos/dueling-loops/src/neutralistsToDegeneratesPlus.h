#ifndef _neutralistsToDegeneratesPlus_H_
#define _neutralistsToDegeneratesPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define NEUTRALISTSTODEGENERATESPLUS "neutralistsToDegeneratesPlus"


class neutralistsToDegeneratesPlus : public Atomic {
  public:
    
    neutralistsToDegeneratesPlus(const string &name = NEUTRALISTSTODEGENERATESPLUS );
    virtual string className() const {  return NEUTRALISTSTODEGENERATESPLUS ;}
  
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