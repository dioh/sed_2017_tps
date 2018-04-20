[top]
components : {% for atomic in atomics %}{{atomic['name']}}@{{atomic['class']}} {% endfor %}

% External Input Ports
in : {% for input in inputs %}{{input}} {% endfor %}
% External Output Ports
out : {% for output in outputs %}{{output}} {% endfor %}

% Links internos (input ports => atomicos tipo 'Cte')
{%- for connection in external_input_connections %}
link : {{connection['port_from']}} {{connection['port_to']}}@{{connection['component_to']}}
{%- endfor %}

% Internal I/O Connections
{%- for connection in internal_connections %}
link : {{connection['port_from']}}@{{connection['component_from']}} {{connection['port_to']}}@{{connection['component_to']}}
{%- endfor %}

% Links internos (variables de interes => output ports)
{%- for connection in external_output_connections %}
link : {{connection['port_from']}}@{{connection['component_from']}} {{connection['port_to']}}
{%- endfor %}

% Integradores
{%- for atomic in atomics %}
{%- if atomic['model'] == 'QSS1' %}
[{{atomic['name']}}]
{%- for param in atomic['parameters'] %}
{{param['name']}} : {{param['function']}}

{%- endfor %}
{%- endif %}
{%- endfor %}