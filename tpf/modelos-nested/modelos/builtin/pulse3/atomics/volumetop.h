#ifndef _volumetop_H_
#define _volumetop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define VOLUMETOP "volumetop"


class volumetop : public Atomic {
  public:
    
    volumetop(const string &name = VOLUMETOP );
    virtual string className() const {  return VOLUMETOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_volume;
    
    Port &out_port_volume;
    
    double volume;
    };

#endif