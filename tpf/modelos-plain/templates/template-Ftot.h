#ifndef _{{name}}_H_
#define _{{name}}_H_

#include <random>

#include "atomic.h"
#include "VTime.h"

#define {{name.upper()}} "{{name}}"

class {{name}} : public Atomic {
  public:
    
    {{name}}(const string &name = {{name.upper()}} );
    virtual string className() const {  return {{name.upper()}} ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    {% for in_port in in_ports_plus -%}
    {% if in_port['type'] == 'in_plus' %}
    const Port &{{in_port['name']}};
    {% endif -%}
    {% endfor -%}
    {% for in_port in in_ports_minus -%}
    {% if in_port['type'] == 'in_minus' %}
    const Port &{{in_port['name']}};
    {% endif -%}
    {% endfor -%}

    {% for out_port in out_ports -%}
    Port &{{out_port['name']}};
    {% endfor %}

    {% for in_port in in_ports_plus -%}
    double val_{{in_port['name']}};
    {% endfor -%}
    {% for in_port in in_ports_minus -%}
    double val_{{in_port['name']}};
    {% endfor -%}

    {% for in_port in in_ports_plus -%}
    bool isSet_val_{{in_port['name']}};
    {% endfor %}
    {% for in_port in in_ports_minus -%}
    bool isSet_val_{{in_port['name']}};
    {% endfor %}
};

#endif
