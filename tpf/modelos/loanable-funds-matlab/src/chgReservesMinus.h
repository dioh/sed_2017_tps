#ifndef _chgReservesMinus_H_
#define _chgReservesMinus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGRESERVESMINUS "chgReservesMinus"


class chgReservesMinus : public Atomic {
  public:
    
    chgReservesMinus(const string &name = CHGRESERVESMINUS );
    virtual string className() const {  return CHGRESERVESMINUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    Port &out;
    

    
};

#endif