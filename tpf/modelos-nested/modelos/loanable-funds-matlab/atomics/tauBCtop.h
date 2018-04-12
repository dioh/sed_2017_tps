#ifndef _tauBCtop_H_
#define _tauBCtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define TAUBCTOP "tauBCtop"


class tauBCtop : public Atomic {
  public:
    
    tauBCtop(const string &name = TAUBCTOP );
    virtual string className() const {  return TAUBCTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_tauBC;
    
    Port &out_port_tauBC;
    
    double tauBC;
    };

#endif