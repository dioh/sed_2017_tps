#ifndef _YCValuetop_H_
#define _YCValuetop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define YCVALUETOP "YCValuetop"


class YCValuetop : public Atomic {
  public:
    
    YCValuetop(const string &name = YCVALUETOP );
    virtual string className() const {  return YCVALUETOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_DepCons;
    const Port &in_port_tauMC;
    Port &out_port_YCValue;
    
    double DepCons;
    double tauMC;
    bool isSet_DepCons;
    bool isSet_tauMC;
};

#endif