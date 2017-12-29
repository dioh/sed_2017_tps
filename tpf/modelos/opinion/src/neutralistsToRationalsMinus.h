#ifndef _neutralistsToRationalsMinus_H_
#define _neutralistsToRationalsMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define NEUTRALISTSTORATIONALSMINUS "neutralistsToRationalsMinus"


class neutralistsToRationalsMinus : public Atomic {
  public:
    
    neutralistsToRationalsMinus(const string &name = NEUTRALISTSTORATIONALSMINUS );
    virtual string className() const {  return NEUTRALISTSTORATIONALSMINUS ;}
  
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