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
    {% for inPort in ft_inPorts -%}
    const Port &{{inPort}};
    {% endfor -%}
    {% for outPort in ft_outPorts -%}
    Port &{{outPort}};
    {% endfor %}

    {% for inPort in ft_inPorts -%}
    double val_{{inPort}};
    {% endfor -%}

    {% for inPort in ft_inPorts -%}
    bool isSet_val_{{inPort}};
    {% endfor %}
};

#endif
