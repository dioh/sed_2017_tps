#ifndef _ProfitNettop_H_
#define _ProfitNettop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PROFITNETTOP "ProfitNettop"


class ProfitNettop : public Atomic {
  public:
    
    ProfitNettop(const string &name = PROFITNETTOP );
    virtual string className() const {  return PROFITNETTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_ProfitGrossReal;
    const Port &in_port_Interest;
    Port &out_port_ProfitNet;
    
    double ProfitGrossReal;
    double Interest;
    bool isSet_ProfitGrossReal;
    bool isSet_Interest;
};

#endif