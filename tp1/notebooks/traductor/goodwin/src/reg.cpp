#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "FtotwageRateIntegrator.h"
#include "FtotPopulationIntegrator.h"
#include "FtotCapitalIntegrator.h"
#include "FplusPopulationchgPopulation.h"
#include "AuxemploymentRate.h"
#include "FtotLaborProductivityIntegrator.h"
#include "FpluswageRatechgWageRate.h"
#include "Auxprofit.h"
#include "Auxoutput.h"
#include "FplusCapitalchgCapital.h"
#include "AuxwageFunction.h"
#include "Auxomega.h"
#include "FplusLaborProductivitychgLaborProductivity.h"
#include "Auxlabor.h"
#include "AuxwageBill.h"
#include "AuxinvestmentGross.h"
#include "AuxinvestmentNetReal.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<FtotwageRateIntegrator>(), FTOTWAGERATEINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FtotPopulationIntegrator>(), FTOTPOPULATIONINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FtotCapitalIntegrator>(), FTOTCAPITALINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FplusPopulationchgPopulation>(), FPLUSPOPULATIONCHGPOPULATION);
	admin.registerAtomic(NewAtomicFunction<AuxemploymentRate>(), AUXEMPLOYMENTRATE);
	admin.registerAtomic(NewAtomicFunction<FtotLaborProductivityIntegrator>(), FTOTLABORPRODUCTIVITYINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FpluswageRatechgWageRate>(), FPLUSWAGERATECHGWAGERATE);
	admin.registerAtomic(NewAtomicFunction<Auxprofit>(), AUXPROFIT);
	admin.registerAtomic(NewAtomicFunction<Auxoutput>(), AUXOUTPUT);
	admin.registerAtomic(NewAtomicFunction<FplusCapitalchgCapital>(), FPLUSCAPITALCHGCAPITAL);
	admin.registerAtomic(NewAtomicFunction<AuxwageFunction>(), AUXWAGEFUNCTION);
	admin.registerAtomic(NewAtomicFunction<Auxomega>(), AUXOMEGA);
	admin.registerAtomic(NewAtomicFunction<FplusLaborProductivitychgLaborProductivity>(), FPLUSLABORPRODUCTIVITYCHGLABORPRODUCTIVITY);
	admin.registerAtomic(NewAtomicFunction<Auxlabor>(), AUXLABOR);
	admin.registerAtomic(NewAtomicFunction<AuxwageBill>(), AUXWAGEBILL);
	admin.registerAtomic(NewAtomicFunction<AuxinvestmentGross>(), AUXINVESTMENTGROSS);
	admin.registerAtomic(NewAtomicFunction<AuxinvestmentNetReal>(), AUXINVESTMENTNETREAL);
	//
}