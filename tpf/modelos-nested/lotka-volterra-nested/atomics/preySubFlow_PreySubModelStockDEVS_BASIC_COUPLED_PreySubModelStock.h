#ifndef _preySubFlow_PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock_H_
#define _preySubFlow_PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PREYSUBFLOW_PREYSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBMODELSTOCK "preySubFlow_PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock"


class preySubFlow_PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock : public Atomic {
  public:
    
    preySubFlow_PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock(const string &name = PREYSUBFLOW_PREYSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBMODELSTOCK );
    virtual string className() const {  return PREYSUBFLOW_PREYSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBMODELSTOCK ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &PreySubModelStock;
    const Port &PreySubSubModelStock;
    const Port &Prey;
    Port &preySubFlow_PreySubModelStock;
    
    double PreySubModelStock;
    double PreySubSubModelStock;
    double Prey;
    bool isSet_PreySubModelStock;
    bool isSet_PreySubSubModelStock;
    bool isSet_Prey;
};

#endif