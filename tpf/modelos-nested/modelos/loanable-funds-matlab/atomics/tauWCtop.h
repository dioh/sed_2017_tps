#ifndef _tauWCtop_H_
#define _tauWCtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define TAUWCTOP "tauWCtop"


class tauWCtop : public Atomic {
  public:
    
    tauWCtop(const string &name = TAUWCTOP );
    virtual string className() const {  return TAUWCTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_tauWC;
    
    Port &out_port_tauWC;
    
    double tauWC;
    };

#endif