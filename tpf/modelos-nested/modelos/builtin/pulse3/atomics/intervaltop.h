#ifndef _intervaltop_H_
#define _intervaltop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define INTERVALTOP "intervaltop"


class intervaltop : public Atomic {
  public:
    
    intervaltop(const string &name = INTERVALTOP );
    virtual string className() const {  return INTERVALTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_interval;
    
    Port &out_port_interval;
    
    double interval;
    };

#endif