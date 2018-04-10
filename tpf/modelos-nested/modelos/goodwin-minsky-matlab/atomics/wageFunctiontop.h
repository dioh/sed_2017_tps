#ifndef _wageFunctiontop_H_
#define _wageFunctiontop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define WAGEFUNCTIONTOP "wageFunctiontop"


class wageFunctiontop : public Atomic {
  public:
    
    wageFunctiontop(const string &name = WAGEFUNCTIONTOP );
    virtual string className() const {  return WAGEFUNCTIONTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_employmentRateStable;
    const Port &in_port_employmentRateZero;
    const Port &in_port_employmentRateValue;
    Port &out_port_wageFunction;
    
    double employmentRateStable;
    double employmentRateZero;
    double employmentRateValue;
    bool isSet_employmentRateStable;
    bool isSet_employmentRateZero;
    bool isSet_employmentRateValue;
};

#endif