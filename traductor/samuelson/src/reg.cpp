#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "FplusPreviousOutputChgPreviousOutput.h"
#include "AuxgovernmentSpending.h"
#include "FplusPreviousConsumptionChgPreviousConsumption.h"
#include "Auxinvestment.h"
#include "Auxoutput.h"
#include "FtotPreviousConsumptionIntegrator.h"
#include "FtotPreviousOutputIntegrator.h"
#include "Auxconsumption.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<FplusPreviousOutputChgPreviousOutput>(), FPLUSPREVIOUSOUTPUTCHGPREVIOUSOUTPUT);
	admin.registerAtomic(NewAtomicFunction<AuxgovernmentSpending>(), AUXGOVERNMENTSPENDING);
	admin.registerAtomic(NewAtomicFunction<FplusPreviousConsumptionChgPreviousConsumption>(), FPLUSPREVIOUSCONSUMPTIONCHGPREVIOUSCONSUMPTION);
	admin.registerAtomic(NewAtomicFunction<Auxinvestment>(), AUXINVESTMENT);
	admin.registerAtomic(NewAtomicFunction<Auxoutput>(), AUXOUTPUT);
	admin.registerAtomic(NewAtomicFunction<FtotPreviousConsumptionIntegrator>(), FTOTPREVIOUSCONSUMPTIONINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FtotPreviousOutputIntegrator>(), FTOTPREVIOUSOUTPUTINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<Auxconsumption>(), AUXCONSUMPTION);
	//
}