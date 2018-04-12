#ifndef _employmentRateStabletop_H_
#define _employmentRateStabletop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define EMPLOYMENTRATESTABLETOP "employmentRateStabletop"


class employmentRateStabletop : public Atomic {
  public:
    
    employmentRateStabletop(const string &name = EMPLOYMENTRATESTABLETOP );
    virtual string className() const {  return EMPLOYMENTRATESTABLETOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_employmentRateStable;
    
    Port &out_port_employmentRateStable;
    
    double employmentRateStable;
    };

#endif