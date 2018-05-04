#ifndef _Totstock1DEVS_BASIC_COUPLED_stock1_H_
#define _Totstock1DEVS_BASIC_COUPLED_stock1_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTSTOCK1DEVS_BASIC_COUPLED_STOCK1 "Totstock1DEVS_BASIC_COUPLED_stock1"

class Totstock1DEVS_BASIC_COUPLED_stock1 : public Atomic {
  public:
    
    Totstock1DEVS_BASIC_COUPLED_stock1(const string &name = TOTSTOCK1DEVS_BASIC_COUPLED_STOCK1 );
    virtual string className() const {  return TOTSTOCK1DEVS_BASIC_COUPLED_STOCK1 ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_flow2_stock1;
    const Port &in_minus_port_flow1_stock1;
    
    Port &out_port_Totstock1;

    double flow2_stock1;
    double flow1_stock1;
    bool isSet_flow2_stock1;
    
    bool isSet_flow1_stock1;
    
};

#endif