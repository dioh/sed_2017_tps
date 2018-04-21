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
    const Port &employmentRate;
    const Port &constantEmploymentRate;
    Port &out;
    

    double val_employmentRate;
    double val_constantEmploymentRate;
    bool isSet_val_employmentRate;
    bool isSet_val_constantEmploymentRate;
    
};

#endif