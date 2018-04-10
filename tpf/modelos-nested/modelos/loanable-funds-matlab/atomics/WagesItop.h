#ifndef _WagesItop_H_
#define _WagesItop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define WAGESITOP "WagesItop"


class WagesItop : public Atomic {
  public:
    
    WagesItop(const string &name = WAGESITOP );
    virtual string className() const {  return WAGESITOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_wSValue;
    const Port &in_port_YIValue;
    Port &out_port_WagesI;
    
    double wSValue;
    double YIValue;
    bool isSet_wSValue;
    bool isSet_YIValue;
};

#endif