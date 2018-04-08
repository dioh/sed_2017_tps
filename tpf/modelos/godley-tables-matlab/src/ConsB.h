#ifndef _ConsB_H_
#define _ConsB_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CONSB "ConsB"


class ConsB : public Atomic {
  public:
    
    ConsB(const string &name = CONSB );
    virtual string className() const {  return CONSB ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Bank;
    const Port &tauBVal;
    Port &out;
    

    double val_Bank;
    double val_tauBVal;
    bool isSet_val_Bank;
    bool isSet_val_tauBVal;
    
};

#endif