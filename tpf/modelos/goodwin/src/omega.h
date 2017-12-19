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
    const Port &wageBill;
    const Port &Output;
    Port &out;
    

    double val_wageBill;
    double val_Output;
    bool isSet_val_wageBill;
    bool isSet_val_Output;
    
};

#endif