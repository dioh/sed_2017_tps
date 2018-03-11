#ifndef _IntFee_H_
#define _IntFee_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define INTFEE "IntFee"


class IntFee : public Atomic {
  public:
    
    IntFee(const string &name = INTFEE );
    virtual string className() const {  return INTFEE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Interest;
    const Port &bfValue;
    Port &out;
    

    double val_Interest;
    double val_bfValue;
    bool isSet_val_Interest;
    bool isSet_val_bfValue;
    
};

#endif