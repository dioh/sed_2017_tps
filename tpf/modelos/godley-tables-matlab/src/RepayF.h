#ifndef _RepayF_H_
#define _RepayF_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define REPAYF "RepayF"


class RepayF : public Atomic {
  public:
    
    RepayF(const string &name = REPAYF );
    virtual string className() const {  return REPAYF ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &DebtFirms;
    const Port &tauR;
    Port &out;
    

    double val_DebtFirms;
    double val_tauR;
    bool isSet_val_DebtFirms;
    bool isSet_val_tauR;
    
};

#endif