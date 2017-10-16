#include "pmodeladm.h"
#include "register.h"

#include "{{atomicClass}}.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<{{atomicClass}}>(), {{atomicClassConstant}});
}
