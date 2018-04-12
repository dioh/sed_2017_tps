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

% Inputs
% Outputs (por ahora sin programar)

% PortInTransition