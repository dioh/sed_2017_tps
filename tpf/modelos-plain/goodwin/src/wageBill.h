#ifndef _wageBill_H_
#define _wageBill_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define WAGEBILL "wageBill"


class wageBill : public Atomic {
  public:
    
    wageBill(const string &name = WAGEBILL );
    virtual string className() const {  return WAGEBILL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &wageRate;
    const Port &Labor;
    Port &out;
    

    double val_wageRate;
    double val_Labor;
    bool isSet_val_wageRate;
    bool isSet_val_Labor;
    
};

#endif