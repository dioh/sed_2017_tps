#ifndef _chgBankersNWMinus_H_
#define _chgBankersNWMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGBANKERSNWMINUS "chgBankersNWMinus"


class chgBankersNWMinus : public Atomic {
  public:
    
    chgBankersNWMinus(const string &name = CHGBANKERSNWMINUS );
    virtual string className() const {  return CHGBANKERSNWMINUS ;}
  
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