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
    const Port &Workers;
    const Port &Firms;
    const Port &Bank;
    Port &out;
    

    double val_Workers;
    double val_Firms;
    double val_Bank;
    bool isSet_val_Workers;
    bool isSet_val_Firms;
    bool isSet_val_Bank;
    
};

#endif