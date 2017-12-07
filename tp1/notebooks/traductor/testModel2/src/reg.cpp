#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "FtotInvestmentIntegrator.h"
#include "FplusCapitalbiflow.h"
#include "FplusInvestmentinflow.h"
#include "FtotCapitalIntegrator.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<FtotInvestmentIntegrator>(), FTOTINVESTMENTINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FplusCapitalbiflow>(), FPLUSCAPITALBIFLOW);
	admin.registerAtomic(NewAtomicFunction<FplusInvestmentinflow>(), FPLUSINVESTMENTINFLOW);
	admin.registerAtomic(NewAtomicFunction<FtotCapitalIntegrator>(), FTOTCAPITALINTEGRATOR);
	//
}