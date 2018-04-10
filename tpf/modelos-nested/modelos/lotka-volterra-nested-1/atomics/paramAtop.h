#ifndef _paramAtop_H_
#define _paramAtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PARAMATOP "paramAtop"


class paramAtop : public Atomic {
  public:
    
    paramAtop(const string &name = PARAMATOP );
    virtual string className() const {  return PARAMATOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_paramA;
    
    Port &out_port_paramA;
    
    double paramA;
    };

#endif