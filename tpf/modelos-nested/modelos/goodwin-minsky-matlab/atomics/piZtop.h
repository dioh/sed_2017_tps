#ifndef _piZtop_H_
#define _piZtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PIZTOP "piZtop"


class piZtop : public Atomic {
  public:
    
    piZtop(const string &name = PIZTOP );
    virtual string className() const {  return PIZTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_piZ;
    
    Port &out_port_piZ;
    
    double piZ;
    };

#endif