[top]
components : {% for name, attr in integradores_.iteritems() -%}{{attr['name_lower']}}@QSS1 {% endfor -%} {% for name, _ in fts_.iteritems() -%}{{name}}@Ftot {% endfor -%} {% for name, _ in fps_.iteritems() -%} {{name}}@Fplus{{name[2:]}} {% endfor -%} {% for name, _ in fms_.iteritems() -%}{{name}}@Fminus{{name[2:]}} {% endfor -%} {% for name, attr in ctes_.iteritems() %}{{attr['name_lower']}}@Cte {% endfor %}

% Puertos: Input de parametros. Output de variables de interes
{% if inputPorts_ != {} -%}
in : {% for _, inPort in inputPorts_.iteritems() -%} {{inPort}} {% endfor %}
{% endif %}
{% if outputPorts_ != {} -%}
out : {% for name, _ in outputPorts_.iteritems() -%} {{name}} {% endfor %}
{% endif %}
% Links inputs a constantes (conexiones con el top model)
{% for cteName, attr in ctes_.iteritems() -%}
link : {{inputPorts_[cteName]}} inValue@{{attr['name_lower']}}
{% endfor %}
% Links constantes a f's que las usan
{% for cteName, elems in links_internal_ctes.iteritems() -%}
{% for elem in elems -%}
link : {{elem['port_from']}}@{{elem['component_from']}} {{elem['port_to']}}@{{elem['component_to']}}
{% endfor -%}
{% endfor %}
{% for intName, elems in links_internal_acoplado_minimal.iteritems() -%}
% Links acoplado minimal integrador {{intName}}
{% for elem in elems -%}
link : {{elem['port_from']}}@{{elem['component_from']}} {{elem['port_to']}}@{{elem['component_to']}}
{% endfor -%}
{% endfor %}
% Links modelo
{% for elem in links_internal_modelo_ -%}
link : {{elem['port_from']}}@{{elem['component_from']}} {{elem['port_to']}}@{{elem['component_to']}}
{% endfor %}
% Liks output variables de interes
{% if outputPorts_ != {} -%}
{% for outPort, _ in outputPorts_.iteritems() -%} 
{% for integradorName, attr in integradores_.iteritems() -%}
{% if outPort[3:] in integradorName -%}
link : out@{{attr['name_lower']}} {{outPort}} 
{% endif -%}
{% endfor -%}
{% endfor -%}
{% endif %}
% Integradores
{% for name, attr in integradores_.iteritems() -%}
[{{attr['name_lower']}}]
x0 : {{attr['x0']}}
dQRel : {{attr['dQRel']}}
dQMin : {{attr['dQMin']}}

{% endfor -%}