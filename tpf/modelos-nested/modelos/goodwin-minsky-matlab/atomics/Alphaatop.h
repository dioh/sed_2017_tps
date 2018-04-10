#ifndef _Alphaatop_H_
#define _Alphaatop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define ALPHAATOP "Alphaatop"


class Alphaatop : public Atomic {
  public:
    
    Alphaatop(const string &name = ALPHAATOP );
    virtual string className() const {  return ALPHAATOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Alphaa;
    
    Port &out_port_Alphaa;
    
    double Alphaa;
    };

#endif