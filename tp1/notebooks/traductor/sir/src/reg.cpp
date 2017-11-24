#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "FminusSusceptibleSuccumbing.h"
#include "FtotInfectiousIntegrator.h"
#include "FminusInfectiousRecovering.h"
#include "FplusRecoveredRecovering.h"
#include "FtotSusceptibleIntegrator.h"
#include "FplusInfectiousSuccumbing.h"
#include "FtotRecoveredIntegrator.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<FminusSusceptibleSuccumbing>(), FMINUSSUSCEPTIBLESUCCUMBING);
	admin.registerAtomic(NewAtomicFunction<FtotInfectiousIntegrator>(), FTOTINFECTIOUSINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FminusInfectiousRecovering>(), FMINUSINFECTIOUSRECOVERING);
	admin.registerAtomic(NewAtomicFunction<FplusRecoveredRecovering>(), FPLUSRECOVEREDRECOVERING);
	admin.registerAtomic(NewAtomicFunction<FtotSusceptibleIntegrator>(), FTOTSUSCEPTIBLEINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FplusInfectiousSuccumbing>(), FPLUSINFECTIOUSSUCCUMBING);
	admin.registerAtomic(NewAtomicFunction<FtotRecoveredIntegrator>(), FTOTRECOVEREDINTEGRATOR);
	//
}