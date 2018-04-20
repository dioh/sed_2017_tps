#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
{% for atomic in atomics -%}
#include "{{atomic}}.h"
{% endfor -%}

// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	{% for atomic in atomics -%}
	admin.registerAtomic(NewAtomicFunction<{{atomic}}>(), {{atomic.upper()}});
	{% endfor -%}
	//
}
