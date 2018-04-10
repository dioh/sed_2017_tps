#ifndef _paramBtop_H_
#define _paramBtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PARAMBTOP "paramBtop"


class paramBtop : public Atomic {
  public:
    
    paramBtop(const string &name = PARAMBTOP );
    virtual string className() const {  return PARAMBTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_paramB;
    
    Port &out_port_paramB;
    
    double paramB;
    };

#endif