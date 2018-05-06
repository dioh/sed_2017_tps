#ifndef _PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock_H_
#define _PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock_H_

#include <string> 

#include "atomic.h"

#define PREYSUBSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBSUBMODELSTOCK "PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock"


class PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock : public Atomic {
  public:
    
    PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock(const string &name = PREYSUBSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBSUBMODELSTOCK );
    virtual string className() const {  return PREYSUBSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBSUBMODELSTOCK ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotPreySubSubModelStock;
    Port &out_port_PreySubSubModelStock;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_PreySubSubModelStock;
    double get_param(const string &);
    VTime minposroot(double *coeff);
    double to_seconds(const VTime &);

    // Agregados
    bool non_negative;
    const Port &in_port_subtract;
    const Port &in_port_increment;

};

#endif