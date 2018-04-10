#ifndef _CPIValuetop_H_
#define _CPIValuetop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CPIVALUETOP "CPIValuetop"


class CPIValuetop : public Atomic {
  public:
    
    CPIValuetop(const string &name = CPIVALUETOP );
    virtual string className() const {  return CPIVALUETOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_CPIValue;
    
    Port &out_port_CPIValue;
    
    double CPIValue;
    };

#endif