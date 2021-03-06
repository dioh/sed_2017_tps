#ifndef _CapitalTot_H_
#define _CapitalTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define CAPITALTOT "CapitalTot"

class CapitalTot : public Atomic {
  public:
    
    CapitalTot(const string &name = CAPITALTOT );
    virtual string className() const {  return CAPITALTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &chgCapitalPlus;
    Port &out;
    

    double val_chgCapitalPlus;
    bool isSet_val_chgCapitalPlus;
    
    
};

#endif