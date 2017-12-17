#ifndef _{{name}}_H_
#define _{{name}}_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define {{nameUpper}} "{{name}}"


class {{name}} : public Atomic {
  public:
    
    {{name}}(const string &name = {{nameUpper}} );
    virtual string className() const {  return {{nameUpper}} ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    {% for inPort in aux_inPorts -%}
    const Port &{{inPort}};
    {% endfor -%}
    {% for outPort in aux_outPorts -%}
    Port &{{outPort}};
    {% endfor %}

    {% for val in values -%}
    double {{val}};
    {% endfor -%}

    {% for val in values -%}
    bool isSet_{{val}};
    {% endfor -%}
    //
};

#endif
