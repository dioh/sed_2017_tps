#ifndef _LendF_H_
#define _LendF_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define LENDF "LendF"


class LendF : public Atomic {
  public:
    
    LendF(const string &name = LENDF );
    virtual string className() const {  return LENDF ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &DebtFirms;
    const Port &tauL;
    Port &out;
    

    double val_DebtFirms;
    double val_tauL;
    bool isSet_val_DebtFirms;
    bool isSet_val_tauL;
    
};

#endif