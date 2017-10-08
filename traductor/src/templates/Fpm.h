#ifndef _{{stockName}}_H_
#define _{{stockName}}_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define {{stockNameConstant}} "{{stockName}}"

class {{stockName}} : public Atomic {
  public:
    
    {{stockName}}(const string &name = {{stockNameConstant}} );
    virtual string className() const {  return {{stockNameConstant}} ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    {% for inPort in inPorts -%}
    const Port &{{inPort}};
    {% endfor -%}
    // Output ports
    Port &out;

    // State variables
    {% for var in variables -%}
    double {{var}};
    {% endfor -%}
    //
    // Check set of state variables
    {% for setVar in setVariables -%}
    bool {{setVar}};
    {% endfor -%}
    //
};

#endif
