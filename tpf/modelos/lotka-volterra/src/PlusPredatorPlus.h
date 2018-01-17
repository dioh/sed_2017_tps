#ifndef _PlusPredatorPlus_H_
#define _PlusPredatorPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PLUSPREDATORPLUS "PlusPredatorPlus"


class PlusPredatorPlus : public Atomic {
  public:
    
    PlusPredatorPlus(const string &name = PLUSPREDATORPLUS );
    virtual string className() const {  return PLUSPREDATORPLUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &paramD;
    const Port &Prey;
    const Port &Predator;
    Port &out;
    

    double val_paramD;
    double val_Prey;
    double val_Predator;
    bool isSet_val_paramD;
    bool isSet_val_Prey;
    bool isSet_val_Predator;
    
};

#endif