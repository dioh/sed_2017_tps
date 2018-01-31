#ifndef _employmentRateValue_H_
#define _employmentRateValue_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define EMPLOYMENTRATEVALUE "employmentRateValue"


class employmentRateValue : public Atomic {
  public:
    
    employmentRateValue(const string &name = EMPLOYMENTRATEVALUE );
    virtual string className() const {  return EMPLOYMENTRATEVALUE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Labor;
    const Port &Population;
    Port &out;
    

    double val_Labor;
    double val_Population;
    bool isSet_val_Labor;
    bool isSet_val_Population;
    
};

#endif