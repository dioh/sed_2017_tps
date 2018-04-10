#ifndef _deltaKRealtop_H_
#define _deltaKRealtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define DELTAKREALTOP "deltaKRealtop"


class deltaKRealtop : public Atomic {
  public:
    
    deltaKRealtop(const string &name = DELTAKREALTOP );
    virtual string className() const {  return DELTAKREALTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_deltaKReal;
    
    Port &out_port_deltaKReal;
    
    double deltaKReal;
    };

#endif