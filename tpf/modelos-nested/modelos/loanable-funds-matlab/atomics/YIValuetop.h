#ifndef _YIValuetop_H_
#define _YIValuetop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define YIVALUETOP "YIValuetop"


class YIValuetop : public Atomic {
  public:
    
    YIValuetop(const string &name = YIVALUETOP );
    virtual string className() const {  return YIVALUETOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_tauMI;
    const Port &in_port_DepInv;
    Port &out_port_YIValue;
    
    double tauMI;
    double DepInv;
    bool isSet_tauMI;
    bool isSet_DepInv;
};

#endif