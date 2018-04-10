#ifndef _paramCtop_H_
#define _paramCtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PARAMCTOP "paramCtop"


class paramCtop : public Atomic {
  public:
    
    paramCtop(const string &name = PARAMCTOP );
    virtual string className() const {  return PARAMCTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_paramC;
    
    Port &out_port_paramC;
    
    double paramC;
    };

#endif