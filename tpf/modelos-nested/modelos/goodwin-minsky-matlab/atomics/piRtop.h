#ifndef _piRtop_H_
#define _piRtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PIRTOP "piRtop"


class piRtop : public Atomic {
  public:
    
    piRtop(const string &name = PIRTOP );
    virtual string className() const {  return PIRTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Capital;
    const Port &in_port_ProfitNet;
    Port &out_port_piR;
    
    double Capital;
    double ProfitNet;
    bool isSet_Capital;
    bool isSet_ProfitNet;
};

#endif