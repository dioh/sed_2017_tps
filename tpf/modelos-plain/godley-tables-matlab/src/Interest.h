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
    const Port &DebtFirms;
    const Port &rateOfInterestOnLoans;
    Port &out;
    

    double val_DebtFirms;
    double val_rateOfInterestOnLoans;
    bool isSet_val_DebtFirms;
    bool isSet_val_rateOfInterestOnLoans;
    
};

#endif