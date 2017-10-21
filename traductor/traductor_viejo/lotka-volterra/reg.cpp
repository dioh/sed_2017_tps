#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "Ftot.h"
#include "FminusLynx.h"
#include "FplusLynx.h"
#include "FminusHares.h"
#include "FplusHares.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	admin.registerAtomic(NewAtomicFunction<Ftot>(), FTOT);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<FminusLynx>(), FMINUSLYNX);
	admin.registerAtomic(NewAtomicFunction<FplusLynx>(), FPLUSLYNX);
	admin.registerAtomic(NewAtomicFunction<FminusHares>(), FMINUSHARES);
	admin.registerAtomic(NewAtomicFunction<FplusHares>(), FPLUSHARES);
	//
}