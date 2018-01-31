#ifndef _chgWageRateMinus_H_
#define _chgWageRateMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGWAGERATEMINUS "chgWageRateMinus"


class chgWageRateMinus : public Atomic {
  public:
    
    chgWageRateMinus(const string &name = CHGWAGERATEMINUS );
    virtual string className() const {  return CHGWAGERATEMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &wageFunction;
    const Port &WageRate;
    Port &out;
    

    double val_wageFunction;
    double val_WageRate;
    bool isSet_val_wageFunction;
    bool isSet_val_WageRate;
    
};

#endif