#ifndef _omega_H_
#define _omega_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define OMEGA "omega"


class omega : public Atomic {
  public:
    
    omega(const string &name = OMEGA );
    virtual string className() const {  return OMEGA ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Wages;
    const Port &Output;
    Port &out;
    

    double val_Wages;
    double val_Output;
    bool isSet_val_Wages;
    bool isSet_val_Output;
    
};

#endif