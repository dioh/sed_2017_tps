#ifndef _velocityOfMoneytop_H_
#define _velocityOfMoneytop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define VELOCITYOFMONEYTOP "velocityOfMoneytop"


class velocityOfMoneytop : public Atomic {
  public:
    
    velocityOfMoneytop(const string &name = VELOCITYOFMONEYTOP );
    virtual string className() const {  return VELOCITYOFMONEYTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Money;
    const Port &in_port_Output;
    Port &out_port_velocityOfMoney;
    
    double Money;
    double Output;
    bool isSet_Money;
    bool isSet_Output;
};

#endif