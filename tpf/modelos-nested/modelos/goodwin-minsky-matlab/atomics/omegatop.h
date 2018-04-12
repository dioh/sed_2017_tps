#ifndef _omegatop_H_
#define _omegatop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define OMEGATOP "omegatop"


class omegatop : public Atomic {
  public:
    
    omegatop(const string &name = OMEGATOP );
    virtual string className() const {  return OMEGATOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_Wages;
    const Port &in_port_Output;
    Port &out_port_omega;
    
    double Wages;
    double Output;
    bool isSet_Wages;
    bool isSet_Output;
};

#endif