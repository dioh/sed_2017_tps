#ifndef _wageFunction_H_
#define _wageFunction_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define WAGEFUNCTION "wageFunction"


class wageFunction : public Atomic {
  public:
    
    wageFunction(const string &name = WAGEFUNCTION );
    virtual string className() const {  return WAGEFUNCTION ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &employmentRateValue;
    const Port &employmentRateZero;
    const Port &employmentRateStable;
    Port &out;
    

    double val_employmentRateValue;
    double val_employmentRateZero;
    double val_employmentRateStable;
    bool isSet_val_employmentRateValue;
    bool isSet_val_employmentRateZero;
    bool isSet_val_employmentRateStable;
    
};

#endif