#ifndef _Interest_H_
#define _Interest_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define INTEREST "Interest"


class Interest : public Atomic {
  public:
    
    Interest(const string &name = INTEREST );
    virtual string className() const {  return INTEREST ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &rateInterestOnLoans;
    const Port &Debt;
    Port &out;
    

    double val_rateInterestOnLoans;
    double val_Debt;
    bool isSet_val_rateInterestOnLoans;
    bool isSet_val_Debt;
    
};

#endif