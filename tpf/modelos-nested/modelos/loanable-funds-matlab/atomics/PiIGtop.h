#ifndef _PiIGtop_H_
#define _PiIGtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PIIGTOP "PiIGtop"


class PiIGtop : public Atomic {
  public:
    
    PiIGtop(const string &name = PIIGTOP );
    virtual string className() const {  return PIIGTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_YIValue;
    const Port &in_port_WagesI;
    Port &out_port_PiIG;
    
    double YIValue;
    double WagesI;
    bool isSet_YIValue;
    bool isSet_WagesI;
};

#endif