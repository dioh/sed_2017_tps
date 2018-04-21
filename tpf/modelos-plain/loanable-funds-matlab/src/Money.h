#ifndef _Money_H_
#define _Money_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define MONEY "Money"


class Money : public Atomic {
  public:
    
    Money(const string &name = MONEY );
    virtual string className() const {  return MONEY ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &DepCons;
    const Port &DepInv;
    const Port &Workers;
    const Port &BankersNW;
    Port &out;
    

    double val_DepCons;
    double val_DepInv;
    double val_Workers;
    double val_BankersNW;
    bool isSet_val_DepCons;
    bool isSet_val_DepInv;
    bool isSet_val_Workers;
    bool isSet_val_BankersNW;
    
};

#endif