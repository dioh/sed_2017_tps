#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "Ftot.h"
#include "FminusInfected.h"
#include "FplusInfected.h"
#include "FminusSusceptible.h"
#include "FplusRecovered.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	admin.registerAtomic(NewAtomicFunction<Ftot>(), FTOT);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<FminusInfected>(), FMINUSINFECTED);
	admin.registerAtomic(NewAtomicFunction<FplusInfected>(), FPLUSINFECTED);
	admin.registerAtomic(NewAtomicFunction<FminusSusceptible>(), FMINUSSUSCEPTIBLE);
	admin.registerAtomic(NewAtomicFunction<FplusRecovered>(), FPLUSRECOVERED);
	//
}