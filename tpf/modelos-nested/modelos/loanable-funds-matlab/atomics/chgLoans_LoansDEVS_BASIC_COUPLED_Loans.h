#ifndef _chgLoans_LoansDEVS_BASIC_COUPLED_Loans_H_
#define _chgLoans_LoansDEVS_BASIC_COUPLED_Loans_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGLOANS_LOANSDEVS_BASIC_COUPLED_LOANS "chgLoans_LoansDEVS_BASIC_COUPLED_Loans"


class chgLoans_LoansDEVS_BASIC_COUPLED_Loans : public Atomic {
  public:
    
    chgLoans_LoansDEVS_BASIC_COUPLED_Loans(const string &name = CHGLOANS_LOANSDEVS_BASIC_COUPLED_LOANS );
    virtual string className() const {  return CHGLOANS_LOANSDEVS_BASIC_COUPLED_LOANS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Repay;
    const Port &in_port_Lend;
    Port &out_port_chgLoans_Loans;
    
    double Repay;
    double Lend;
    bool isSet_Repay;
    bool isSet_Lend;
};

#endif