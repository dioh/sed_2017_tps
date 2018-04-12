#ifndef _Betaatop_H_
#define _Betaatop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define BETAATOP "Betaatop"


class Betaatop : public Atomic {
  public:
    
    Betaatop(const string &name = BETAATOP );
    virtual string className() const {  return BETAATOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Betaa;
    
    Port &out_port_Betaa;
    
    double Betaa;
    };

#endif