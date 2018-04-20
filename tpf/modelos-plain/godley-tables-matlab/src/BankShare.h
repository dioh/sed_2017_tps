#ifndef _BankShare_H_
#define _BankShare_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define BANKSHARE "BankShare"


class BankShare : public Atomic {
  public:
    
    BankShare(const string &name = BANKSHARE );
    virtual string className() const {  return BANKSHARE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Interest;
    const Port &GDProduct;
    Port &out;
    

    double val_Interest;
    double val_GDProduct;
    bool isSet_val_Interest;
    bool isSet_val_GDProduct;
    
};

#endif