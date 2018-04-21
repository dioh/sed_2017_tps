#ifndef _WagesI_H_
#define _WagesI_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define WAGESI "WagesI"


class WagesI : public Atomic {
  public:
    
    WagesI(const string &name = WAGESI );
    virtual string className() const {  return WAGESI ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &YIValue;
    const Port &wSValue;
    Port &out;
    

    double val_YIValue;
    double val_wSValue;
    bool isSet_val_YIValue;
    bool isSet_val_wSValue;
    
};

#endif