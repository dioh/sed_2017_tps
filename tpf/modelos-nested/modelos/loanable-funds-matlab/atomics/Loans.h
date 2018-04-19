#ifndef _Loans_H_
#define _Loans_H_

#include <string> 

#include "atomic.h"

#define LOANS "Loans"


class Loans : public Atomic {
  public:
    
    Loans(const string &name = LOANS );
    virtual string className() const {  return LOANS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_TotLoans;
    Port &out_port_Loans;

    double dQ, dQMin, dQRel;
    double x[2], q;
    double gain;
    VTime sigma; // track last change

    bool log_output_Loans;

    double get_param(const string &);

    VTime minposroot(double *coeff);

    double to_seconds(const VTime &);

};

#endif