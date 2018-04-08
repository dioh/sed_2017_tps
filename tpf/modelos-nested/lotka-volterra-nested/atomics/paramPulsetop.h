#ifndef _paramPulsetop_H_
#define _paramPulsetop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PARAMPULSETOP "paramPulsetop"


class paramPulsetop : public Atomic {
  public:
    
    paramPulsetop(const string &name = PARAMPULSETOP );
    virtual string className() const {  return PARAMPULSETOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &paramPulse;
    
    Port &paramPulse;
    
    double paramPulse;
    };

#endif