#ifndef _PreyTot_H_
#define _PreyTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define PREYTOT "PreyTot"

class PreyTot : public Atomic {
  public:
    
    PreyTot(const string &name = PREYTOT );
    virtual string className() const {  return PREYTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &PlusPreyPlus;
    
    const Port &MinusPreyMinus;
    Port &out;
    

    double val_PlusPreyPlus;
    double val_MinusPreyMinus;
    bool isSet_val_PlusPreyPlus;
    
    bool isSet_val_MinusPreyMinus;
    
};

#endif