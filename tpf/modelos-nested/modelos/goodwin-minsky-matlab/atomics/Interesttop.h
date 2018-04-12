#ifndef _Interesttop_H_
#define _Interesttop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define INTERESTTOP "Interesttop"


class Interesttop : public Atomic {
  public:
    
    Interesttop(const string &name = INTERESTTOP );
    virtual string className() const {  return INTERESTTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Debt;
    const Port &in_port_rateInterestOnLoans;
    Port &out_port_Interest;
    
    double Debt;
    double rateInterestOnLoans;
    bool isSet_Debt;
    bool isSet_rateInterestOnLoans;
};

#endif