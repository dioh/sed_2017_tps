#ifndef _chgBankersNWPlus_H_
#define _chgBankersNWPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGBANKERSNWPLUS "chgBankersNWPlus"


class chgBankersNWPlus : public Atomic {
  public:
    
    chgBankersNWPlus(const string &name = CHGBANKERSNWPLUS );
    virtual string className() const {  return CHGBANKERSNWPLUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &IntFee;
    const Port &ConsB;
    Port &out;
    

    double val_IntFee;
    double val_ConsB;
    bool isSet_val_IntFee;
    bool isSet_val_ConsB;
    
};

#endif