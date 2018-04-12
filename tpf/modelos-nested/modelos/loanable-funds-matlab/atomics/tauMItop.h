#ifndef _tauMItop_H_
#define _tauMItop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define TAUMITOP "tauMItop"


class tauMItop : public Atomic {
  public:
    
    tauMItop(const string &name = TAUMITOP );
    virtual string className() const {  return TAUMITOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_tauMI;
    
    Port &out_port_tauMI;
    
    double tauMI;
    };

#endif