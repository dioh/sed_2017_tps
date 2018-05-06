#ifndef _exratop_H_
#define _exratop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define EXRATOP "exratop"


class exratop : public Atomic {
  public:
    
    exratop(const string &name = EXRATOP );
    virtual string className() const {  return EXRATOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_exra;
    
    Port &out_port_exra;
    
    double exra;
    };

#endif