#ifndef _chgBankMinus_H_
#define _chgBankMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGBANKMINUS "chgBankMinus"


class chgBankMinus : public Atomic {
  public:
    
    chgBankMinus(const string &name = CHGBANKMINUS );
    virtual string className() const {  return CHGBANKMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Interest;
    const Port &ConsB;
    Port &out;
    

    double val_Interest;
    double val_ConsB;
    bool isSet_val_Interest;
    bool isSet_val_ConsB;
    
};

#endif