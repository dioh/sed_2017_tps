#ifndef _firstPulseXtop_H_
#define _firstPulseXtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FIRSTPULSEXTOP "firstPulseXtop"


class firstPulseXtop : public Atomic {
  public:
    
    firstPulseXtop(const string &name = FIRSTPULSEXTOP );
    virtual string className() const {  return FIRSTPULSEXTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_firstPulseX;
    
    Port &out_port_firstPulseX;
    
    double firstPulseX;
    };

#endif