#ifndef _Profit_H_
#define _Profit_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PROFIT "Profit"


class Profit : public Atomic {
  public:
    
    Profit(const string &name = PROFIT );
    virtual string className() const {  return PROFIT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Output;
    const Port &wageBill;
    Port &out;
    

    double val_Output;
    double val_wageBill;
    bool isSet_val_Output;
    bool isSet_val_wageBill;
    
};

#endif