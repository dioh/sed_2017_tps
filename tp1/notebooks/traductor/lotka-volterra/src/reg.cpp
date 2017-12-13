#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "FplusPredatorPlusPredator.h"
#include "FminusPredatorMinusPredator.h"
#include "FminusPreyMinusPrey.h"
#include "FplusPreyPlusPrey.h"
#include "FtotPreyIntegrator.h"
#include "FtotPredatorIntegrator.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<FplusPredatorPlusPredator>(), FPLUSPREDATORPLUSPREDATOR);
	admin.registerAtomic(NewAtomicFunction<FminusPredatorMinusPredator>(), FMINUSPREDATORMINUSPREDATOR);
	admin.registerAtomic(NewAtomicFunction<FminusPreyMinusPrey>(), FMINUSPREYMINUSPREY);
	admin.registerAtomic(NewAtomicFunction<FplusPreyPlusPrey>(), FPLUSPREYPLUSPREY);
	admin.registerAtomic(NewAtomicFunction<FtotPreyIntegrator>(), FTOTPREYINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FtotPredatorIntegrator>(), FTOTPREDATORINTEGRATOR);
	//
}