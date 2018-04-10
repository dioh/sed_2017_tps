#ifndef _specialParamCtop_H_
#define _specialParamCtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define SPECIALPARAMCTOP "specialParamCtop"


class specialParamCtop : public Atomic {
  public:
    
    specialParamCtop(const string &name = SPECIALPARAMCTOP );
    virtual string className() const {  return SPECIALPARAMCTOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_PULSE_V_2_FP_2_I_2;
    Port &out_port_specialParamC;
    
    double PULSE_V_2_FP_2_I_2;
    bool isSet_PULSE_V_2_FP_2_I_2;
};

#endif