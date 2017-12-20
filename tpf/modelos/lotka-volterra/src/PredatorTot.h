#ifndef _PredatorTot_H_
#define _PredatorTot_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define PREDATORTOT "PredatorTot"

class PredatorTot : public Atomic {
  public:
    
    PredatorTot(const string &name = PREDATORTOT );
    virtual string className() const {  return PREDATORTOT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &PlusPredatorPlus;
    Port &out;
    

    double val_PlusPredatorPlus;
    bool isSet_val_PlusPredatorPlus;
    
    
};

#endif