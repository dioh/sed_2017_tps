#ifndef _debtRate_H_
#define _debtRate_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define DEBTRATE "debtRate"


class debtRate : public Atomic {
  public:
    
    debtRate(const string &name = DEBTRATE );
    virtual string className() const {  return DEBTRATE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_Debt;
    const Port &in_Output;
    Port &out;
    

    double Debt;
    double Output;
    bool isSet_Debt;
    bool isSet_Output;
    //
};

#endif