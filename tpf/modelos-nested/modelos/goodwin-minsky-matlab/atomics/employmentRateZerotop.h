#ifndef _employmentRateZerotop_H_
#define _employmentRateZerotop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define EMPLOYMENTRATEZEROTOP "employmentRateZerotop"


class employmentRateZerotop : public Atomic {
  public:
    
    employmentRateZerotop(const string &name = EMPLOYMENTRATEZEROTOP );
    virtual string className() const {  return EMPLOYMENTRATEZEROTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_employmentRateZero;
    
    Port &out_port_employmentRateZero;
    
    double employmentRateZero;
    };

#endif