#ifndef _{{pulse_name_upper}}_H_
#define _{{pulse_name_upper}}_H_

#include <random>

#include "atomic.h"
#include "VTime.h"


#define {{pulse_name_upper}} "{{pulse_name_lower}}"


class {{pulse_name_lower}} : public Atomic {
  public:
    
    {{pulse_name_lower}}(const string &name = {{pulse_name_upper}} );
    virtual string className() const {  return {{pulse_name_upper}} ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    const Port &in_port_start;
    const Port &stop;
    Port &out;

    VTime frequency_time;
    bool on;

    std::uniform_int_distribution<int> dist;
    std::mt19937 rng;

    // Agregados
    const Port &in_port_volume;
    bool isSet_in_port_volume = false;
    float volume;
    {% for output_port_name in output_ports %}
    Port &out_port_{{output_port_name}};
    {% endfor -%}
};

#endif
