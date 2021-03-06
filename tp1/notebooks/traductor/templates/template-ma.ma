[top]
components : {% for intName, attr in integradores_.iteritems() %}{{intName}}@{{attr['model']}} {% endfor -%} {% for ftName, attr in fts_.iteritems() %}{{ftName}}@{{attr['model']}} {% endfor -%}{% for fmName, attr in fms_.iteritems() %}{{fmName}}@{{attr['model']}} {% endfor %}{% for fpName, attr in fps_.iteritems() -%}{{fpName}}@{{attr['model']}} {% endfor -%}{% for cteName, attr in ctes_.iteritems() %}{{cteName}}@{{attr['model']}} {% endfor %}{% for auxName, attr in auxs_.iteritems() %} {{auxName}}@{{attr['model']}} {% endfor %}

% Puertos: Input de parametros. Output de variables de interes
in : {% for cteName, attr in ctes_.iteritems() -%}in_{{cteName}} {% endfor %}
out : {% for intName, attr in integradores_.iteritems() -%}out_{{intName}} {% endfor %}

% Links inputs a constantes (conexiones con el top model)
{% for cteName, attr in ctes_.iteritems() -%}
link : in_{{cteName}} inValue@{{cteName}}
{% endfor %}
% Links constantes a f's que las usan
{% for fmName, fmAttr in fms_.iteritems() -%} 
{% for param in fmAttr['function_params'] -%}
{% if param in ctes_.keys() -%}
link : out@{{param}} in_{{param}}@{{fmName}}
{% endif -%}
{% endfor -%}
{% endfor -%}
{% for fpName, fpAttr in fps_.iteritems() -%} 
{% for param in fpAttr['function_params'] -%}
{% if param in ctes_.keys() -%}
link : out@{{param}} in_{{param}}@{{fpName}}
{% endif -%}
{% endfor -%}
{% endfor %}
% Link constantes a Aux's que las usan
{% for auxName, auxAttr in auxs_.iteritems() -%} 
{% for param in auxAttr['function_params'] -%}
{% if param in ctes_.keys() -%}
link : out@{{param}} in_{{param}}@{{auxName}}
{% endif -%}
{% endfor -%}
{% endfor %}
% Link Aux's a Aux's que las usan
{% for auxName, auxAttr in auxs_.iteritems() -%} 
{% for param in auxAttr['function_params'] -%}
{% if param in auxs_.keys() -%}
link : out@{{param}} in_{{param}}@{{auxName}}
{% endif -%}
{% endfor -%}
{% endfor %}
% Link Aux's a funciones que las usan 
{% for fmName, fmAttr in fms_.iteritems() -%} 
{% for param in fmAttr['function_params'] -%}
{% if param in auxs_.keys() -%}
link : out@{{param}} in_{{param}}@{{fmName}}
{% endif -%}
{% endfor -%}
{% endfor -%}
{% for fpName, fpAttr in fps_.iteritems() -%} 
{% for param in fpAttr['function_params'] -%}
{% if param in auxs_.keys() -%}
link : out@{{param}} in_{{param}}@{{fpName}}
{% endif -%}
{% endfor -%}
{% endfor %}
% Links internos de los acoplados minimales (Ftot => Integrador)
{% for intName, intAttr in integradores_.iteritems() -%}
link : out@{{intAttr['ftName']}} in@{{intName}}
{% endfor %}
% Links internos de los acoplados minimales (Fms => Fts)
{% for fmName, fmAttr in fms_.iteritems() -%}
link : out@{{fmName}} inMinus_{{fmAttr['flowName']}}@{{fmAttr['coupledTot']}}Integrator
{% endfor %}
% Links internos de los acoplados minimales (Fps => Fts)
{% for fpName, fpAttr in fps_.iteritems() -%}
link : out@{{fpName}} inPlus_{{fpAttr['flowName']}}@{{fpAttr['coupledTot']}}Integrator
{% endfor %}
% Links importantes del modelo
{% for intName, intAttr in integradores_.iteritems() -%}
{% for fmName, fmAttr in fms_.iteritems() -%}
{% if intName in fmAttr['function_params'] -%}
link : out@{{intName}} in_{{intName}}@{{fmName}}
{% endif -%}
{% endfor -%}
{% for fpName, fpAttr in fps_.iteritems() -%}
{% if intName in fpAttr['function_params'] -%}
link : out@{{intName}} in_{{intName}}@{{fpName}}
{% endif -%}
{% endfor -%}
{% for auxName, auxAttr in auxs_.iteritems() -%}
{% if intName in auxAttr['function_params'] -%}
link : out@{{intName}} in_{{intName}}@{{auxName}}
{% endif -%}
{% endfor -%}
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