#ifndef _employmentRateValuetop_H_
#define _employmentRateValuetop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define EMPLOYMENTRATEVALUETOP "employmentRateValuetop"


class employmentRateValuetop : public Atomic {
  public:
    
    employmentRateValuetop(const string &name = EMPLOYMENTRATEVALUETOP );
    virtual string className() const {  return EMPLOYMENTRATEVALUETOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Labor;
    const Port &in_port_Population;
    Port &out_port_employmentRateValue;
    
    double Labor;
    double Population;
    bool isSet_Labor;
    bool isSet_Population;
};

#endif