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
    const Port &in_employmentRate;
    const Port &in_employmentRateZero;
    const Port &in_employmentRateStable;
    Port &out;
    

    double employmentRate;
    double employmentRateZero;
    double employmentRateStable;
    bool isSet_employmentRate;
    bool isSet_employmentRateZero;
    bool isSet_employmentRateStable;
    //
};

#endif