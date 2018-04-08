#ifndef _Repay_H_
#define _Repay_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define REPAY "Repay"


class Repay : public Atomic {
  public:
    
    Repay(const string &name = REPAY );
    virtual string className() const {  return REPAY ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Loans;
    const Port &tauR;
    Port &out;
    

    double val_Loans;
    double val_tauR;
    bool isSet_val_Loans;
    bool isSet_val_tauR;
    
};

#endif