#ifndef _Debt_H_
#define _Debt_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define DEBT "Debt"


class Debt : public Atomic {
  public:
    
    Debt(const string &name = DEBT );
    virtual string className() const {  return DEBT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Loans;
    Port &out;
    

    double val_Loans;
    bool isSet_val_Loans;
    
};

#endif