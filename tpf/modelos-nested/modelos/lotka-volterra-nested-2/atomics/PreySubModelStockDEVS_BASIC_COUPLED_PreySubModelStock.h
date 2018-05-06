#ifndef _PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock_H_
#define _PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock_H_

#include <string> 

#include "atomic.h"

#define PREYSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBMODELSTOCK "PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock"


class PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock : public Atomic {
  public:
    
    PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock(const string &name = PREYSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBMODELSTOCK );
    virtual string className() const {  return PREYSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBMODELSTOCK ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotPreySubModelStock;
    Port &out_port_PreySubModelStock;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_PreySubModelStock;
    double get_param(const string &);
    VTime minposroot(double *coeff);
    double to_seconds(const VTime &);

    // Agregados
    bool non_negative;
    const Port &in_port_subtract;
    const Port &in_port_increment;

};

#endif