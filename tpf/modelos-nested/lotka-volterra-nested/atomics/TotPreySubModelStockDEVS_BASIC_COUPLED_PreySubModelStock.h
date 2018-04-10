#ifndef _TotPreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock_H_
#define _TotPreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTPREYSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBMODELSTOCK "TotPreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock"

class TotPreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock : public Atomic {
  public:
    
    TotPreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock(const string &name = TOTPREYSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBMODELSTOCK );
    virtual string className() const {  return TOTPREYSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBMODELSTOCK ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_minus_preySubFlow_PreySubModelStock;
    
    Port &out_port_TotPreySubModelStock;

    double preySubFlow_PreySubModelStock;
    
    bool isSet_preySubFlow_PreySubModelStock;
    
};

#endif