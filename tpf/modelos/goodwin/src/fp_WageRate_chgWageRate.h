#ifndef _fp_WageRate_chgWageRate_H_
#define _fp_WageRate_chgWageRate_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define FP_WAGERATE_CHGWAGERATE "fp_WageRate_chgWageRate"

class fp_WageRate_chgWageRate : public Atomic {
  public:
    fp_WageRate_chgWageRate(const string &name = FP_WAGERATE_CHGWAGERATE );
    virtual string className() const {  return FP_WAGERATE_CHGWAGERATE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_wageFunction;
    const Port &in_WageRate;
    Port &out;
    

    double wageFunction;
    double WageRate;
    bool isSet_wageFunction;
    bool isSet_WageRate;
    //
};

#endif