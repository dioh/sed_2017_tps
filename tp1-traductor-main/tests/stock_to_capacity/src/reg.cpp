#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "FplusPreviousConsumptionChgPreviousConsumption.h"
#include "FtotPreviousConsumptionIntegrator.h"
#include "FtotPreviousOutputIntegrator.h"
#include "FplusPreviousOutputChgPreviousOutput.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<FplusPreviousConsumptionChgPreviousConsumption>(), FPLUSPREVIOUSCONSUMPTIONCHGPREVIOUSCONSUMPTION);
	admin.registerAtomic(NewAtomicFunction<FtotPreviousConsumptionIntegrator>(), FTOTPREVIOUSCONSUMPTIONINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FtotPreviousOutputIntegrator>(), FTOTPREVIOUSOUTPUTINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FplusPreviousOutputChgPreviousOutput>(), FPLUSPREVIOUSOUTPUTCHGPREVIOUSOUTPUT);
	//
}