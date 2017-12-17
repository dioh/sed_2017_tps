#ifndef _ProfitGrossReal_H_
#define _ProfitGrossReal_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PROFITGROSSREAL "ProfitGrossReal"


class ProfitGrossReal : public Atomic {
  public:
    
    ProfitGrossReal(const string &name = PROFITGROSSREAL );
    virtual string className() const {  return PROFITGROSSREAL ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_Output;
    const Port &in_Wages;
    Port &out;
    

    double Output;
    double Wages;
    bool isSet_Output;
    bool isSet_Wages;
    //
};

#endif