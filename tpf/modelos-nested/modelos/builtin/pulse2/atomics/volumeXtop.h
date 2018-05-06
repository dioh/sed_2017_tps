#ifndef _volumeXtop_H_
#define _volumeXtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define VOLUMEXTOP "volumeXtop"


class volumeXtop : public Atomic {
  public:
    
    volumeXtop(const string &name = VOLUMEXTOP );
    virtual string className() const {  return VOLUMEXTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_volumeX;
    
    Port &out_port_volumeX;
    
    double volumeX;
    };

#endif