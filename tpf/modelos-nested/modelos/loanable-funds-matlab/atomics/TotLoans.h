#ifndef _TotLoans_H_
#define _TotLoans_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTLOANS "TotLoans"

class TotLoans : public Atomic {
  public:
    
    TotLoans(const string &name = TOTLOANS );
    virtual string className() const {  return TOTLOANS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgLoans_LoansDEVS_BASIC_COUPLED_Loans;
    
    Port &out_port_TotLoans;

    double chgLoans_LoansDEVS_BASIC_COUPLED_Loans;
    bool isSet_chgLoans_LoansDEVS_BASIC_COUPLED_Loans;
    
    
};

#endif