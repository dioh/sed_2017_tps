#ifndef _{{atomicClass}}_H_
#define _{{atomicClass}}_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define {{atomicClassConstant}} "{{atomicClass}}"

class {{atomicClass}} : public Atomic {
  public:
    
    {{atomicClass}}(const string &name = {{atomicClassConstant}} );
    virtual string className() const {  return {{atomicClassConstant}} ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    const Port &in;
    // Output ports
    Port {% for outPort in outPorts -%}
    {% if loop.index0 < outPorts|length - 1 -%}&{{outPort}}, {% else -%}&{{outPort}};{% endif -%}
    {% endfor %}

    // State variables
    double numberOfOutputPorts;
    double numberOfChosenOutputPorts;
    double outValue;
};

#endif
