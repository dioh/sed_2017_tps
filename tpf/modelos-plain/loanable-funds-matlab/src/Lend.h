#ifndef _Lend_H_
#define _Lend_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define LEND "Lend"


class Lend : public Atomic {
  public:
    
    Lend(const string &name = LEND );
    virtual string className() const {  return LEND ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &DepCons;
    const Port &tauL;
    Port &out;
    

    double val_DepCons;
    double val_tauL;
    bool isSet_val_DepCons;
    bool isSet_val_tauL;
    
};

#endif