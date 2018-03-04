#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
{% for modelName, modelAttr in models.items() -%}
#include "{{modelName}}.h"
{% endfor -%} 
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	{% for modelName, modelAttr in models.items() -%}
	admin.registerAtomic(NewAtomicFunction<{{modelName}}>(), {{modelAttr['modelUpper']}});
	{% endfor -%}
	//
}
