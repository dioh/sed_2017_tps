#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "FtotSusceptibleIntegrator.h"
#include "FtotInfectiousIntegrator.h"
#include "FtotRecoveredIntegrator.h"
#include "FplusInfectiousSuccumbing.h"
#include "FplusRecoveredRecovering.h"
#include "FminusSusceptibleSuccumbing.h"
#include "FminusInfectiousRecovering.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<FtotSusceptibleIntegrator>(), FTOTSUSCEPTIBLEINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FtotInfectiousIntegrator>(), FTOTINFECTIOUSINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FtotRecoveredIntegrator>(), FTOTRECOVEREDINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FplusInfectiousSuccumbing>(), FPLUSINFECTIOUSSUCCUMBING);
	admin.registerAtomic(NewAtomicFunction<FplusRecoveredRecovering>(), FPLUSRECOVEREDRECOVERING);
	admin.registerAtomic(NewAtomicFunction<FminusSusceptibleSuccumbing>(), FMINUSSUSCEPTIBLESUCCUMBING);
	admin.registerAtomic(NewAtomicFunction<FminusInfectiousRecovering>(), FMINUSINFECTIOUSRECOVERING);
	//
}