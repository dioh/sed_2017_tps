#ifndef _chgwageRatePlus_H_
#define _chgwageRatePlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGWAGERATEPLUS "chgwageRatePlus"


class chgwageRatePlus : public Atomic {
  public:
    
    chgwageRatePlus(const string &name = CHGWAGERATEPLUS );
    virtual string className() const {  return CHGWAGERATEPLUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &wageFunction;
    const Port &wageRate;
    Port &out;
    

    double val_wageFunction;
    double val_wageRate;
    bool isSet_val_wageFunction;
    bool isSet_val_wageRate;
    
};

#endif