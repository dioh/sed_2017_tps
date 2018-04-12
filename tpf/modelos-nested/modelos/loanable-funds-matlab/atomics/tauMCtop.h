#ifndef _tauMCtop_H_
#define _tauMCtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define TAUMCTOP "tauMCtop"


class tauMCtop : public Atomic {
  public:
    
    tauMCtop(const string &name = TAUMCTOP );
    virtual string className() const {  return TAUMCTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_tauMC;
    
    Port &out_port_tauMC;
    
    double tauMC;
    };

#endif