#ifndef _chgLoansMinus_H_
#define _chgLoansMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGLOANSMINUS "chgLoansMinus"


class chgLoansMinus : public Atomic {
  public:
    
    chgLoansMinus(const string &name = CHGLOANSMINUS );
    virtual string className() const {  return CHGLOANSMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Lend;
    const Port &Repay;
    Port &out;
    

    double val_Lend;
    double val_Repay;
    bool isSet_val_Lend;
    bool isSet_val_Repay;
    
};

#endif