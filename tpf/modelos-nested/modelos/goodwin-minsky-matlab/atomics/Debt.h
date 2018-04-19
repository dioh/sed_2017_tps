#ifndef _Debt_H_
#define _Debt_H_

#include <string> 

#include "atomic.h"

#define DEBT "Debt"


class Debt : public Atomic {
  public:
    
    Debt(const string &name = DEBT );
    virtual string className() const {  return DEBT ;}
  
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

};

#endif