#ifndef _employmentRate_H_
#define _employmentRate_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define EMPLOYMENTRATE "employmentRate"


class employmentRate : public Atomic {
  public:
    
    employmentRate(const string &name = EMPLOYMENTRATE );
    virtual string className() const {  return EMPLOYMENTRATE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_Labor;
    const Port &in_Population;
    Port &out;
    

    double Labor;
    double Population;
    bool isSet_Labor;
    bool isSet_Population;
    //
};

#endif