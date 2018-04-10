#ifndef _WagesCtop_H_
#define _WagesCtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define WAGESCTOP "WagesCtop"


class WagesCtop : public Atomic {
  public:
    
    WagesCtop(const string &name = WAGESCTOP );
    virtual string className() const {  return WAGESCTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_wSValue;
    const Port &in_port_YCValue;
    Port &out_port_WagesC;
    
    double wSValue;
    double YCValue;
    bool isSet_wSValue;
    bool isSet_YCValue;
};

#endif