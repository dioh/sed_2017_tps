#ifndef _wSValuetop_H_
#define _wSValuetop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define WSVALUETOP "wSValuetop"


class wSValuetop : public Atomic {
  public:
    
    wSValuetop(const string &name = WSVALUETOP );
    virtual string className() const {  return WSVALUETOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_wSValue;
    
    Port &out_port_wSValue;
    
    double wSValue;
    };

#endif