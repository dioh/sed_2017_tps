#ifndef _WagesC_H_
#define _WagesC_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define WAGESC "WagesC"


class WagesC : public Atomic {
  public:
    
    WagesC(const string &name = WAGESC );
    virtual string className() const {  return WAGESC ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &YCValue;
    const Port &wSValue;
    Port &out;
    

    double val_YCValue;
    double val_wSValue;
    bool isSet_val_YCValue;
    bool isSet_val_wSValue;
    
};

#endif