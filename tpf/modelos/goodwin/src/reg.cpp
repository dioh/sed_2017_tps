#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "wageFunction.h"
#include "InvestmentGross.h"
#include "InvestmentNetReal.h"
#include "Profit.h"
#include "wageBill.h"
#include "Output.h"
#include "Labor.h"
#include "omega.h"
#include "employmentRate.h"
#include "chgLaborProductivityPlus.h"
#include "chgLaborProductivityMinus.h"
#include "chgPopulationPlus.h"
#include "chgPopulationMinus.h"
#include "chgWageRatePlus.h"
#include "chgWageRateMinus.h"
#include "chgCapitalPlus.h"
#include "chgCapitalMinus.h"
#include "LaborProductivityTot.h"
#include "wageRateTot.h"
#include "PopulationTot.h"
#include "CapitalTot.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<wageFunction>(), WAGEFUNCTION);
	admin.registerAtomic(NewAtomicFunction<InvestmentGross>(), INVESTMENTGROSS);
	admin.registerAtomic(NewAtomicFunction<InvestmentNetReal>(), INVESTMENTNETREAL);
	admin.registerAtomic(NewAtomicFunction<Profit>(), PROFIT);
	admin.registerAtomic(NewAtomicFunction<wageBill>(), WAGEBILL);
	admin.registerAtomic(NewAtomicFunction<Output>(), OUTPUT);
	admin.registerAtomic(NewAtomicFunction<Labor>(), LABOR);
	admin.registerAtomic(NewAtomicFunction<omega>(), OMEGA);
	admin.registerAtomic(NewAtomicFunction<employmentRate>(), EMPLOYMENTRATE);
	admin.registerAtomic(NewAtomicFunction<chgLaborProductivityPlus>(), CHGLABORPRODUCTIVITYPLUS);
	admin.registerAtomic(NewAtomicFunction<chgLaborProductivityMinus>(), CHGLABORPRODUCTIVITYMINUS);
	admin.registerAtomic(NewAtomicFunction<chgPopulationPlus>(), CHGPOPULATIONPLUS);
	admin.registerAtomic(NewAtomicFunction<chgPopulationMinus>(), CHGPOPULATIONMINUS);
	admin.registerAtomic(NewAtomicFunction<chgWageRatePlus>(), CHGWAGERATEPLUS);
	admin.registerAtomic(NewAtomicFunction<chgWageRateMinus>(), CHGWAGERATEMINUS);
	admin.registerAtomic(NewAtomicFunction<chgCapitalPlus>(), CHGCAPITALPLUS);
	admin.registerAtomic(NewAtomicFunction<chgCapitalMinus>(), CHGCAPITALMINUS);
	admin.registerAtomic(NewAtomicFunction<LaborProductivityTot>(), LABORPRODUCTIVITYTOT);
	admin.registerAtomic(NewAtomicFunction<wageRateTot>(), WAGERATETOT);
	admin.registerAtomic(NewAtomicFunction<PopulationTot>(), POPULATIONTOT);
	admin.registerAtomic(NewAtomicFunction<CapitalTot>(), CAPITALTOT);
	//
}