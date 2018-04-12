#ifndef _rLValuetop_H_
#define _rLValuetop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define RLVALUETOP "rLValuetop"


class rLValuetop : public Atomic {
  public:
    
    rLValuetop(const string &name = RLVALUETOP );
    virtual string className() const {  return RLVALUETOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_rLValue;
    
    Port &out_port_rLValue;
    
    double rLValue;
    };

#endif