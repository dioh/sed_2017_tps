#ifndef _Flow1_PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock_H_
#define _Flow1_PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define FLOW1_PREYSUBSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBSUBMODELSTOCK "Flow1_PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock"


class Flow1_PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock : public Atomic {
  public:
    
    Flow1_PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock(const string &name = FLOW1_PREYSUBSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBSUBMODELSTOCK );
    virtual string className() const {  return FLOW1_PREYSUBSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBSUBMODELSTOCK ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_PreySubSubModelStock;
    const Port &in_port_PULSE_V_combiner_FP_10_I_50_Flow1;
    Port &out_port_Flow1_PreySubSubModelStock;
    
    double PreySubSubModelStock;
    double PULSE_V_combiner_FP_10_I_50_Flow1;
    bool isSet_PreySubSubModelStock;
    bool isSet_PULSE_V_combiner_FP_10_I_50_Flow1;
};

#endif