#ifndef _{{model}}_H_
#define _{{model}}_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define {{modelUpper}} "{{model}}"

class {{model}} : public Atomic {
  public:
    
    {{model}}(const string &name = {{modelUpper}} );
    virtual string className() const {  return {{modelUpper}} ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    // Input ports
    {% for inPort in ports -%}
    const Port &{{inPort}};
    {% endfor -%}
    // Output ports
    Port &out;

    // State variables
    {% for var, port in params_ports.items() -%}
    double {{var}};
    {% endfor -%}
    //
    // Check set of state variables
    {% for var, port in params_ports.items() -%}
    bool isSet_{{var}};
    {% endfor -%}
    //
};

#endif
