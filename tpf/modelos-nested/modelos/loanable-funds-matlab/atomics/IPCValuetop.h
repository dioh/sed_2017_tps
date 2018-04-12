#ifndef _IPCValuetop_H_
#define _IPCValuetop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define IPCVALUETOP "IPCValuetop"


class IPCValuetop : public Atomic {
  public:
    
    IPCValuetop(const string &name = IPCVALUETOP );
    virtual string className() const {  return IPCVALUETOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_IPCValue;
    
    Port &out_port_IPCValue;
    
    double IPCValue;
    };

#endif