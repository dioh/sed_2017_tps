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

    // Agregados (volume + iterval)
    // TODO : volume y interval tienen que venir con el nombre de la variable + a que variable corresponde (volume o interval)
    {% if volume_param != None -%}
    float volume = {{volume_param}};
    bool isSet_volume;
    {% endif -%}
    {% if interval_param != None -%}
    float interval = {{interval_param}};
    bool isSet_interval;
    {% endif -%}

    {% if volume_input != '' -%}
    const Port &in_port_{{volume_input}};
    float {{volume_input}};
    bool isSet_volume;
    {% endif -%}
    {% if interval_input != '' -%}
    const Port &in_port_{{interval_input}};
    float {{interval_input}};
    bool isSet_interval;
    {% endif -%}

    {% for output_port_name in output_ports %}
    Port &out_port_{{output_port_name}};
    {% endfor -%}
};

#endif
