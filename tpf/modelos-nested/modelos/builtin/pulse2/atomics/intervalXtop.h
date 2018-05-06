#ifndef _intervalXtop_H_
#define _intervalXtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define INTERVALXTOP "intervalXtop"


class intervalXtop : public Atomic {
  public:
    
    intervalXtop(const string &name = INTERVALXTOP );
    virtual string className() const {  return INTERVALXTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_intervalX;
    
    Port &out_port_intervalX;
    
    double intervalX;
    };

#endif