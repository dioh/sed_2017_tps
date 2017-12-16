#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "FtotWageRateIntegrator.h"
#include "AuxinvestmentFunctionReal.h"
#include "FplusDebtchgDebt.h"
#include "Auxwages.h"
#include "AuxwageFunction.h"
#include "FtotDebtIntegrator.h"
#include "FplusPopulationchgPopulation.h"
#include "AuxprofitNet.h"
#include "AuxdebtRate.h"
#include "AuxemploymentRate.h"
#include "FtotLaborProductivityIntegrator.h"
#include "FplusCapitalchgCapital.h"
#include "FtotPopulationIntegrator.h"
#include "FplusWageRatechgWageRate.h"
#include "AuxinterestPayments.h"
#include "AuxinvestmentGross.h"
#include "FtotCapitalIntegrator.h"
#include "Auxlabor.h"
#include "AuxprofitGrossReal.h"
#include "AuxpiR.h"
#include "Auxoutput.h"
#include "Auxomega.h"
#include "FplusLaborProductivitychgLaborProductivity.h"
#include "AuxinvestmentNetReal.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<FtotWageRateIntegrator>(), FTOTWAGERATEINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<AuxinvestmentFunctionReal>(), AUXINVESTMENTFUNCTIONREAL);
	admin.registerAtomic(NewAtomicFunction<FplusDebtchgDebt>(), FPLUSDEBTCHGDEBT);
	admin.registerAtomic(NewAtomicFunction<Auxwages>(), AUXWAGES);
	admin.registerAtomic(NewAtomicFunction<AuxwageFunction>(), AUXWAGEFUNCTION);
	admin.registerAtomic(NewAtomicFunction<FtotDebtIntegrator>(), FTOTDEBTINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FplusPopulationchgPopulation>(), FPLUSPOPULATIONCHGPOPULATION);
	admin.registerAtomic(NewAtomicFunction<AuxprofitNet>(), AUXPROFITNET);
	admin.registerAtomic(NewAtomicFunction<AuxdebtRate>(), AUXDEBTRATE);
	admin.registerAtomic(NewAtomicFunction<AuxemploymentRate>(), AUXEMPLOYMENTRATE);
	admin.registerAtomic(NewAtomicFunction<FtotLaborProductivityIntegrator>(), FTOTLABORPRODUCTIVITYINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FplusCapitalchgCapital>(), FPLUSCAPITALCHGCAPITAL);
	admin.registerAtomic(NewAtomicFunction<FtotPopulationIntegrator>(), FTOTPOPULATIONINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FplusWageRatechgWageRate>(), FPLUSWAGERATECHGWAGERATE);
	admin.registerAtomic(NewAtomicFunction<AuxinterestPayments>(), AUXINTERESTPAYMENTS);
	admin.registerAtomic(NewAtomicFunction<AuxinvestmentGross>(), AUXINVESTMENTGROSS);
	admin.registerAtomic(NewAtomicFunction<FtotCapitalIntegrator>(), FTOTCAPITALINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<Auxlabor>(), AUXLABOR);
	admin.registerAtomic(NewAtomicFunction<AuxprofitGrossReal>(), AUXPROFITGROSSREAL);
	admin.registerAtomic(NewAtomicFunction<AuxpiR>(), AUXPIR);
	admin.registerAtomic(NewAtomicFunction<Auxoutput>(), AUXOUTPUT);
	admin.registerAtomic(NewAtomicFunction<Auxomega>(), AUXOMEGA);
	admin.registerAtomic(NewAtomicFunction<FplusLaborProductivitychgLaborProductivity>(), FPLUSLABORPRODUCTIVITYCHGLABORPRODUCTIVITY);
	admin.registerAtomic(NewAtomicFunction<AuxinvestmentNetReal>(), AUXINVESTMENTNETREAL);
	//
}