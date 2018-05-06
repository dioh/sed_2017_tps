#ifndef _DebtDEVS_BASIC_COUPLED_Debt_H_
#define _DebtDEVS_BASIC_COUPLED_Debt_H_

#include <string> 

#include "atomic.h"

#define DEBTDEVS_BASIC_COUPLED_DEBT "DebtDEVS_BASIC_COUPLED_Debt"


class DebtDEVS_BASIC_COUPLED_Debt : public Atomic {
  public:
    
    DebtDEVS_BASIC_COUPLED_Debt(const string &name = DEBTDEVS_BASIC_COUPLED_DEBT );
    virtual string className() const {  return DEBTDEVS_BASIC_COUPLED_DEBT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotDebt;
    Port &out_port_Debt;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_Debt;
    double get_param(const string &);
    VTime minposroot(double *coeff);
    double to_seconds(const VTime &);

    // Agregados
    bool non_negative;
    const Port &in_port_subtract;
    const Port &in_port_increment;

};

#endif