#ifndef _Outputtop_H_
#define _Outputtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define OUTPUTTOP "Outputtop"


class Outputtop : public Atomic {
  public:
    
    Outputtop(const string &name = OUTPUTTOP );
    virtual string className() const {  return OUTPUTTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Capital;
    const Port &in_port_velocityOfMoney;
    Port &out_port_Output;
    
    double Capital;
    double velocityOfMoney;
    bool isSet_Capital;
    bool isSet_velocityOfMoney;
};

#endif