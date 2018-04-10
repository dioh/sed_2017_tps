#ifndef _bfValuetop_H_
#define _bfValuetop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define BFVALUETOP "bfValuetop"


class bfValuetop : public Atomic {
  public:
    
    bfValuetop(const string &name = BFVALUETOP );
    virtual string className() const {  return BFVALUETOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_bfValue;
    
    Port &out_port_bfValue;
    
    double bfValue;
    };

#endif