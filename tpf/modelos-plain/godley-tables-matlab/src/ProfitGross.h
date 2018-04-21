#ifndef _ProfitGross_H_
#define _ProfitGross_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PROFITGROSS "ProfitGross"


class ProfitGross : public Atomic {
  public:
    
    ProfitGross(const string &name = PROFITGROSS );
    virtual string className() const {  return PROFITGROSS ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &GDProduct;
    const Port &Wages;
    Port &out;
    

    double val_GDProduct;
    double val_Wages;
    bool isSet_val_GDProduct;
    bool isSet_val_Wages;
    
};

#endif