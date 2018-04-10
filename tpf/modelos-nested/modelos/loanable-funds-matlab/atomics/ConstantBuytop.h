#ifndef _ConstantBuytop_H_
#define _ConstantBuytop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CONSTANTBUYTOP "ConstantBuytop"


class ConstantBuytop : public Atomic {
  public:
    
    ConstantBuytop(const string &name = CONSTANTBUYTOP );
    virtual string className() const {  return CONSTANTBUYTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_PiCG;
    const Port &in_port_CPIValue;
    Port &out_port_ConstantBuy;
    
    double PiCG;
    double CPIValue;
    bool isSet_PiCG;
    bool isSet_CPIValue;
};

#endif