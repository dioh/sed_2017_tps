#ifndef _LoansTot_H_
#define _LoansTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define LOANSTOT "LoansTot"

class LoansTot : public Atomic {
  public:
    
    LoansTot(const string &name = LOANSTOT );
    virtual string className() const {  return LOANSTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &chgLoansPlus;
    Port &out;
    

    double val_chgLoansPlus;
    bool isSet_val_chgLoansPlus;
    
    
};

#endif