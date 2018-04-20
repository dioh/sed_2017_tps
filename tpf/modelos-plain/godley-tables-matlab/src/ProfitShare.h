#ifndef _ProfitShare_H_
#define _ProfitShare_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PROFITSHARE "ProfitShare"


class ProfitShare : public Atomic {
  public:
    
    ProfitShare(const string &name = PROFITSHARE );
    virtual string className() const {  return PROFITSHARE ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &ProfitNet;
    const Port &GDProduct;
    Port &out;
    

    double val_ProfitNet;
    double val_GDProduct;
    bool isSet_val_ProfitNet;
    bool isSet_val_GDProduct;
    
};

#endif