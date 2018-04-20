#ifndef _WagesShare_H_
#define _WagesShare_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define WAGESSHARE "WagesShare"


class WagesShare : public Atomic {
  public:
    
    WagesShare(const string &name = WAGESSHARE );
    virtual string className() const {  return WAGESSHARE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Wages;
    const Port &GDProduct;
    Port &out;
    

    double val_Wages;
    double val_GDProduct;
    bool isSet_val_Wages;
    bool isSet_val_GDProduct;
    
};

#endif