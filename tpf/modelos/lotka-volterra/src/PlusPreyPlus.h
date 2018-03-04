#ifndef _PlusPreyPlus_H_
#define _PlusPreyPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PLUSPREYPLUS "PlusPreyPlus"


class PlusPreyPlus : public Atomic {
  public:
    
    PlusPreyPlus(const string &name = PLUSPREYPLUS );
    virtual string className() const {  return PLUSPREYPLUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &paramA;
    const Port &Prey;
    Port &out;
    

    double val_paramA;
    double val_Prey;
    bool isSet_val_paramA;
    bool isSet_val_Prey;
    
};

#endif