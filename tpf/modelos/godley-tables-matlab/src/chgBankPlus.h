#ifndef _chgBankPlus_H_
#define _chgBankPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGBANKPLUS "chgBankPlus"


class chgBankPlus : public Atomic {
  public:
    
    chgBankPlus(const string &name = CHGBANKPLUS );
    virtual string className() const {  return CHGBANKPLUS ;}
  
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