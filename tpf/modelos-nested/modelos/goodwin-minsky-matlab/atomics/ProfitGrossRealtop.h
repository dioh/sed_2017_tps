#ifndef _ProfitGrossRealtop_H_
#define _ProfitGrossRealtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PROFITGROSSREALTOP "ProfitGrossRealtop"


class ProfitGrossRealtop : public Atomic {
  public:
    
    ProfitGrossRealtop(const string &name = PROFITGROSSREALTOP );
    virtual string className() const {  return PROFITGROSSREALTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Wages;
    const Port &in_port_Output;
    Port &out_port_ProfitGrossReal;
    
    double Wages;
    double Output;
    bool isSet_Wages;
    bool isSet_Output;
};

#endif