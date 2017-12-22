#ifndef _InfectedTot_H_
#define _InfectedTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define INFECTEDTOT "InfectedTot"

class InfectedTot : public Atomic {
  public:
    
    InfectedTot(const string &name = INFECTEDTOT );
    virtual string className() const {  return INFECTEDTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &SuccumbingPlus;
    
    const Port &RecoveringMinus;
    Port &out;
    

    double val_SuccumbingPlus;
    double val_RecoveringMinus;
    bool isSet_val_SuccumbingPlus;
    
    bool isSet_val_RecoveringMinus;
    
};

#endif