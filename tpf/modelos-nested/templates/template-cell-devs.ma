#include({{macro}})

[{{name}}]
type : {{type}}
dim : {{dim}}
delay : {{transport}}
defaultDelayTime : {{default_delay_time}}
border : {{border_type}}
{%- for neighbor in neighbors %}
neighbors : {{neighbor}}
{%- endfor %}
initialvalue : {{initial_value}}
localtransition : {{local_transition}}

{% for transition_name, transition_name_rules in rules.iteritems() -%}
[{{transition_name}}]
{%- for rule_value in transition_name_rules %}
rule : {{rule_value}}
{% endfor -%}
{% endfor -%}

% Input ports
in:{% for input_port_name in input_ports -%} input_port_name{% endfor -%}
% Output ports (por ahora sin programar)
out:{% for output_port_name in output_ports -%} output_port_name{% endfor -%}

% PortInTransition