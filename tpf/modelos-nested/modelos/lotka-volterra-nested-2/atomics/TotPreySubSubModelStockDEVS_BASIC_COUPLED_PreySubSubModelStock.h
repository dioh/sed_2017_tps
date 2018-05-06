#ifndef _TotPreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock_H_
#define _TotPreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTPREYSUBSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBSUBMODELSTOCK "TotPreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock"

class TotPreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock : public Atomic {
  public:
    
    TotPreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock(const string &name = TOTPREYSUBSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBSUBMODELSTOCK );
    virtual string className() const {  return TOTPREYSUBSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBSUBMODELSTOCK ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_minus_port_Flow1_PreySubSubModelStock;
    
    Port &out_port_TotPreySubSubModelStock;

    double Flow1_PreySubSubModelStock;
    
    bool isSet_Flow1_PreySubSubModelStock;
    
};

#endif