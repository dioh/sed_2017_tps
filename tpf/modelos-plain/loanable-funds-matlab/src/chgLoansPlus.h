#ifndef _chgLoansPlus_H_
#define _chgLoansPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGLOANSPLUS "chgLoansPlus"


class chgLoansPlus : public Atomic {
  public:
    
    chgLoansPlus(const string &name = CHGLOANSPLUS );
    virtual string className() const {  return CHGLOANSPLUS ;}
  
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