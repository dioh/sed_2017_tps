#ifndef _Wagestop_H_
#define _Wagestop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define WAGESTOP "Wagestop"


class Wagestop : public Atomic {
  public:
    
    Wagestop(const string &name = WAGESTOP );
    virtual string className() const {  return WAGESTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Labor;
    const Port &in_port_wageRate;
    Port &out_port_Wages;
    
    double Labor;
    double wageRate;
    bool isSet_Labor;
    bool isSet_wageRate;
};

#endif