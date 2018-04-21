#ifndef _chgCapitalPlus_H_
#define _chgCapitalPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGCAPITALPLUS "chgCapitalPlus"


class chgCapitalPlus : public Atomic {
  public:
    
    chgCapitalPlus(const string &name = CHGCAPITALPLUS );
    virtual string className() const {  return CHGCAPITALPLUS ;}
  
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