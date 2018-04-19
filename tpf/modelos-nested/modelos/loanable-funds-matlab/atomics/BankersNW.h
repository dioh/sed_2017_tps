#ifndef _BankersNW_H_
#define _BankersNW_H_

#include <string> 

#include "atomic.h"

#define BANKERSNW "BankersNW"


class BankersNW : public Atomic {
  public:
    
    BankersNW(const string &name = BANKERSNW );
    virtual string className() const {  return BANKERSNW ;}
  
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