#ifndef _BankersNWDEVS_BASIC_COUPLED_BankersNW_H_
#define _BankersNWDEVS_BASIC_COUPLED_BankersNW_H_

#include <string> 

#include "atomic.h"

#define BANKERSNWDEVS_BASIC_COUPLED_BANKERSNW "BankersNWDEVS_BASIC_COUPLED_BankersNW"


class BankersNWDEVS_BASIC_COUPLED_BankersNW : public Atomic {
  public:
    
    BankersNWDEVS_BASIC_COUPLED_BankersNW(const string &name = BANKERSNWDEVS_BASIC_COUPLED_BANKERSNW );
    virtual string className() const {  return BANKERSNWDEVS_BASIC_COUPLED_BANKERSNW ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotBankersNW;
    Port &out_port_BankersNW;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_BankersNW;

    double get_param(const string &);

    VTime minposroot(double *coeff);

    double to_seconds(const VTime &);

};

#endif