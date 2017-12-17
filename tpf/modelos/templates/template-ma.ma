[top]
components : {% for intName, attr in integradores_.iteritems() %}{{intName}}@{{attr['model']}} {% endfor -%} {% for ftName, attr in fts_.iteritems() %}{{ftName}}@{{attr['name']}} {% endfor -%}{% for fmName, attr in fms_.iteritems() %}{{fmName}}@{{attr['name']}} {% endfor %}{% for fpName, attr in fps_.iteritems() -%}{{fpName}}@{{attr['name']}} {% endfor -%}{% for cteName, attr in ctes_.iteritems() %}{{cteName}}@{{attr['model']}} {% endfor %}{% for auxName, attr in auxs_.iteritems() %}{{auxName}}@{{attr['name']}} {% endfor %}

% Puertos: Input de parametros. Output de variables de interes
in : {% for port_name in input_ports %}in_{{port_name}} {% endfor %}
out : {% for port_name in output_ports %}out_{{port_name}} {% endfor %}

% Links inputs a constantes (conexiones con el top model)
{% for conn in external_connections -%}
{% if conn['component_from'] == 'top' -%} 
link : {{conn['port_from']}}_{{conn['component_to']}} {{conn['port_to']}}@{{conn['component_to']}} 
{% endif -%} 
{% endfor %}

% Link entre Stocks, Cte's, Aux's y f's
{% for conn in internal_connections -%}
link : {{conn['port_from']}}@{{conn['component_from']}} {{conn['port_to']}}@{{conn['component_to']}} 
{% endfor %}

% Liks output variables de interes
{% for intName, attr in integradores_.iteritems() -%} 
link : out@{{intName}} out_{{intName}}
{% endfor %}

% Integradores
{% for intName, attr in integradores_.iteritems() -%}
[{{intName}}]
x0 : {{attr['x0']}}
dQRel : 1e-4
dQMin : ee-4

{% endfor -%}