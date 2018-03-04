#ifndef _chgwageRateMinus_H_
#define _chgwageRateMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGWAGERATEMINUS "chgwageRateMinus"


class chgwageRateMinus : public Atomic {
  public:
    
    chgwageRateMinus(const string &name = CHGWAGERATEMINUS );
    virtual string className() const {  return CHGWAGERATEMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &wageFunction;
    const Port &wageRate;
    Port &out;
    

    double val_wageFunction;
    double val_wageRate;
    bool isSet_val_wageFunction;
    bool isSet_val_wageRate;
    
};

#endif