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
    const Port &BankersNW;
    const Port &tauBC;
    Port &out;
    

    double val_BankersNW;
    double val_tauBC;
    bool isSet_val_BankersNW;
    bool isSet_val_tauBC;
    
};

#endif