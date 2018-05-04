#ifndef _firstPulsetop_H_
#define _firstPulsetop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FIRSTPULSETOP "firstPulsetop"


class firstPulsetop : public Atomic {
  public:
    
    firstPulsetop(const string &name = FIRSTPULSETOP );
    virtual string className() const {  return FIRSTPULSETOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_firstPulse;
    
    Port &out_port_firstPulse;
    
    double firstPulse;
    };

#endif