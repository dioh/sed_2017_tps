#ifndef _ConsWtop_H_
#define _ConsWtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define CONSWTOP "ConsWtop"


class ConsWtop : public Atomic {
  public:
    
    ConsWtop(const string &name = CONSWTOP );
    virtual string className() const {  return CONSWTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Workers;
    const Port &in_port_tauWC;
    Port &out_port_ConsW;
    
    double Workers;
    double tauWC;
    bool isSet_Workers;
    bool isSet_tauWC;
};

#endif