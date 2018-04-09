#ifndef _paramDtop_H_
#define _paramDtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PARAMDTOP "paramDtop"


class paramDtop : public Atomic {
  public:
    
    paramDtop(const string &name = PARAMDTOP );
    virtual string className() const {  return PARAMDTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &paramD;
    
    Port &paramD;
    
    double paramD;
    };

#endif