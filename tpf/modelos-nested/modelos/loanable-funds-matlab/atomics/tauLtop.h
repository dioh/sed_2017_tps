#ifndef _tauLtop_H_
#define _tauLtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define TAULTOP "tauLtop"


class tauLtop : public Atomic {
  public:
    
    tauLtop(const string &name = TAULTOP );
    virtual string className() const {  return TAULTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_tauL;
    
    Port &out_port_tauL;
    
    double tauL;
    };

#endif