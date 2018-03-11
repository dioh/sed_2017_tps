#ifndef _chgReservesPlus_H_
#define _chgReservesPlus_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CHGRESERVESPLUS "chgReservesPlus"


class chgReservesPlus : public Atomic {
  public:
    
    chgReservesPlus(const string &name = CHGRESERVESPLUS );
    virtual string className() const {  return CHGRESERVESPLUS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    Port &out;
    

    
};

#endif