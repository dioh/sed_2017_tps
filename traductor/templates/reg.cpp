#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "Ftot.h"
{% for f in stockNames -%}
#include "{{f}}.h"
{% endfor -%} 
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	admin.registerAtomic(NewAtomicFunction<Ftot>(), FTOT);
	
	// Atomicos especificos del modelo
	{% for f in stockNames -%}
	admin.registerAtomic(NewAtomicFunction<{{f}}>(), {{stockNamesConstant[loop.index0]}});
	{% endfor -%}
	//
}
