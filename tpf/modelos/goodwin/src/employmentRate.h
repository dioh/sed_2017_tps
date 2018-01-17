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
    const Port &Labor;
    const Port &Population;
    Port &out;
    

    double val_Labor;
    double val_Population;
    bool isSet_val_Labor;
    bool isSet_val_Population;
    
};

#endif