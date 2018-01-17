#ifndef _chgWageRatePlus_H_
#define _chgWageRatePlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGWAGERATEPLUS "chgWageRatePlus"


class chgWageRatePlus : public Atomic {
  public:
    
    chgWageRatePlus(const string &name = CHGWAGERATEPLUS );
    virtual string className() const {  return CHGWAGERATEPLUS ;}
  
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