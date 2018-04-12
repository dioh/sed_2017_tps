#ifndef _paramEtop_H_
#define _paramEtop_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define PARAMETOP "paramEtop"


class paramEtop : public Atomic {
  public:
    
    paramEtop(const string &name = PARAMETOP );
    virtual string className() const {  return PARAMETOP ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    
    const Port &in_port_paramB;
    const Port &in_port_PULSE_V_1_FP_1_I_1;
    const Port &in_port_paramA;
    Port &out_port_paramE;
    
    double paramB;
    double PULSE_V_1_FP_1_I_1;
    double paramA;
    bool isSet_paramB;
    bool isSet_PULSE_V_1_FP_1_I_1;
    bool isSet_paramA;
};

#endif