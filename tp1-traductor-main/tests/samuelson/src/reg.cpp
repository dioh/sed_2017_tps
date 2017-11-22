#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "FtotPrevOutptIntegrator.h"
#include "FtotPrevConsIntegrator.h"
#include "FplusPrevOutptChgPrevOutpt.h"
#include "FplusPrevConsChgPrevCons.h"
#include "Auxconsumption.h"
#include "Auxoutput.h"
#include "Auxinvestment.h"
#include "AuxgovernmentSpending.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<FtotPrevOutptIntegrator>(), FTOTPREVOUTPTINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FtotPrevConsIntegrator>(), FTOTPREVCONSINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FplusPrevOutptChgPrevOutpt>(), FPLUSPREVOUTPTCHGPREVOUTPT);
	admin.registerAtomic(NewAtomicFunction<FplusPrevConsChgPrevCons>(), FPLUSPREVCONSCHGPREVCONS);
	admin.registerAtomic(NewAtomicFunction<Auxconsumption>(), AUXCONSUMPTION);
	admin.registerAtomic(NewAtomicFunction<Auxoutput>(), AUXOUTPUT);
	admin.registerAtomic(NewAtomicFunction<Auxinvestment>(), AUXINVESTMENT);
	admin.registerAtomic(NewAtomicFunction<AuxgovernmentSpending>(), AUXGOVERNMENTSPENDING);
	//
}