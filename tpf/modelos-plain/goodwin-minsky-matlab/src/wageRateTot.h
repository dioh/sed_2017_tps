#ifndef _wageRateTot_H_
#define _wageRateTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define WAGERATETOT "wageRateTot"

class wageRateTot : public Atomic {
  public:
    
    wageRateTot(const string &name = WAGERATETOT );
    virtual string className() const {  return WAGERATETOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &chgwageRatePlus;
    Port &out;
    

    double val_chgwageRatePlus;
    bool isSet_val_chgwageRatePlus;
    
    
};

#endif