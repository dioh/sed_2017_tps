#ifndef _piStop_H_
#define _piStop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PISTOP "piStop"


class piStop : public Atomic {
  public:
    
    piStop(const string &name = PISTOP );
    virtual string className() const {  return PISTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_piS;
    
    Port &out_port_piS;
    
    double piS;
    };

#endif