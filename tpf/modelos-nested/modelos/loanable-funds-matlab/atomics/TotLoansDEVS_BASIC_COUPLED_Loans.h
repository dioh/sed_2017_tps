#ifndef _TotLoansDEVS_BASIC_COUPLED_Loans_H_
#define _TotLoansDEVS_BASIC_COUPLED_Loans_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define TOTLOANSDEVS_BASIC_COUPLED_LOANS "TotLoansDEVS_BASIC_COUPLED_Loans"

class TotLoansDEVS_BASIC_COUPLED_Loans : public Atomic {
  public:
    
    TotLoansDEVS_BASIC_COUPLED_Loans(const string &name = TOTLOANSDEVS_BASIC_COUPLED_LOANS );
    virtual string className() const {  return TOTLOANSDEVS_BASIC_COUPLED_LOANS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_plus_port_chgLoans_Loans;
    
    Port &out_port_TotLoans;

    double chgLoans_Loans;
    bool isSet_chgLoans_Loans;
    
    
};

#endif