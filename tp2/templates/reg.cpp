#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
{% for shock in shockNames -%}
#include "{{shock}}.h"
{% endfor -%} 
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos especificos del modelo
	{% for shock in shockNames -%}
	admin.registerAtomic(NewAtomicFunction<{{shock}}>(), {{shockNamesConstant[loop.index0]}});
	{% endfor %}
}
