#ifndef _chgCapitalMinus_H_
#define _chgCapitalMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGCAPITALMINUS "chgCapitalMinus"


class chgCapitalMinus : public Atomic {
  public:
    
    chgCapitalMinus(const string &name = CHGCAPITALMINUS );
    virtual string className() const {  return CHGCAPITALMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &InvestmentNetReal;
    Port &out;
    

    double val_InvestmentNetReal;
    bool isSet_val_InvestmentNetReal;
    
};

#endif