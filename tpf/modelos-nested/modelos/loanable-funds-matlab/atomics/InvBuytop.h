#ifndef _InvBuytop_H_
#define _InvBuytop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define INVBUYTOP "InvBuytop"


class InvBuytop : public Atomic {
  public:
    
    InvBuytop(const string &name = INVBUYTOP );
    virtual string className() const {  return INVBUYTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_IPCValue;
    const Port &in_port_PiIG;
    Port &out_port_InvBuy;
    
    double IPCValue;
    double PiIG;
    bool isSet_IPCValue;
    bool isSet_PiIG;
};

#endif