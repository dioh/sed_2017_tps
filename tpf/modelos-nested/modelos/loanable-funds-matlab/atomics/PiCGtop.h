#ifndef _PiCGtop_H_
#define _PiCGtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PICGTOP "PiCGtop"


class PiCGtop : public Atomic {
  public:
    
    PiCGtop(const string &name = PICGTOP );
    virtual string className() const {  return PICGTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_YCValue;
    const Port &in_port_WagesC;
    Port &out_port_PiCG;
    
    double YCValue;
    double WagesC;
    bool isSet_YCValue;
    bool isSet_WagesC;
};

#endif