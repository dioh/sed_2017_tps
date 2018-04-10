#ifndef _IntFeetop_H_
#define _IntFeetop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define INTFEETOP "IntFeetop"


class IntFeetop : public Atomic {
  public:
    
    IntFeetop(const string &name = INTFEETOP );
    virtual string className() const {  return INTFEETOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_bfValue;
    const Port &in_port_Interest;
    Port &out_port_IntFee;
    
    double bfValue;
    double Interest;
    bool isSet_bfValue;
    bool isSet_Interest;
};

#endif