#ifndef _InvBuy_H_
#define _InvBuy_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define INVBUY "InvBuy"


class InvBuy : public Atomic {
  public:
    
    InvBuy(const string &name = INVBUY );
    virtual string className() const {  return INVBUY ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &PiIG;
    const Port &IPCValue;
    Port &out;
    

    double val_PiIG;
    double val_IPCValue;
    bool isSet_val_PiIG;
    bool isSet_val_IPCValue;
    
};

#endif