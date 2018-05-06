#ifndef _flow3_stock1DEVS_BASIC_COUPLED_stock1_H_
#define _flow3_stock1DEVS_BASIC_COUPLED_stock1_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FLOW3_STOCK1DEVS_BASIC_COUPLED_STOCK1 "flow3_stock1DEVS_BASIC_COUPLED_stock1"


class flow3_stock1DEVS_BASIC_COUPLED_stock1 : public Atomic {
  public:
    
    flow3_stock1DEVS_BASIC_COUPLED_stock1(const string &name = FLOW3_STOCK1DEVS_BASIC_COUPLED_STOCK1 );
    virtual string className() const {  return FLOW3_STOCK1DEVS_BASIC_COUPLED_STOCK1 ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_exra;
    Port &out_port_flow3_stock1;
    
    double exra;
    bool isSet_exra;
};

#endif