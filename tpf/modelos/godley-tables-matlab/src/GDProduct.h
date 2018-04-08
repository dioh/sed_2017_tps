#ifndef _GDProduct_H_
#define _GDProduct_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define GDPRODUCT "GDProduct"


class GDProduct : public Atomic {
  public:
    
    GDProduct(const string &name = GDPRODUCT );
    virtual string className() const {  return GDPRODUCT ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &Firms;
    const Port &tauT;
    Port &out;
    

    double val_Firms;
    double val_tauT;
    bool isSet_val_Firms;
    bool isSet_val_tauT;
    
};

#endif