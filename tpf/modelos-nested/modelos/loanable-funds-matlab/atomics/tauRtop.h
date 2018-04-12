#ifndef _tauRtop_H_
#define _tauRtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define TAURTOP "tauRtop"


class tauRtop : public Atomic {
  public:
    
    tauRtop(const string &name = TAURTOP );
    virtual string className() const {  return TAURTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_tauR;
    
    Port &out_port_tauR;
    
    double tauR;
    };

#endif