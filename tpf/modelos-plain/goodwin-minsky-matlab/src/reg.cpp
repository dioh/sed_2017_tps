#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "wageFunction.h"
#include "employmentRateValue.h"
#include "Labor.h"
#include "Interest.h"
#include "Output.h"
#include "omega.h"
#include "Wages.h"
#include "InvestmentGross.h"
#include "ProfitNet.h"
#include "ProfitGrossReal.h"
#include "piR.h"
#include "InvestmentFunctionReal.h"
#include "InvestmentNetReal.h"
#include "chgPopulationPlus.h"
#include "chgPopulationMinus.h"
#include "chgLaborProductivityPlus.h"
#include "chgLaborProductivityMinus.h"
#include "chgDebtPlus.h"
#include "chgDebtMinus.h"
#include "chgwageRatePlus.h"
#include "chgwageRateMinus.h"
#include "chgCapitalPlus.h"
#include "chgCapitalMinus.h"
#include "DebtTot.h"
#include "wageRateTot.h"
#include "LaborProductivityTot.h"
#include "CapitalTot.h"
#include "PopulationTot.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<wageFunction>(), WAGEFUNCTION);
	admin.registerAtomic(NewAtomicFunction<employmentRateValue>(), EMPLOYMENTRATEVALUE);
	admin.registerAtomic(NewAtomicFunction<Labor>(), LABOR);
	admin.registerAtomic(NewAtomicFunction<Interest>(), INTEREST);
	admin.registerAtomic(NewAtomicFunction<Output>(), OUTPUT);
	admin.registerAtomic(NewAtomicFunction<omega>(), OMEGA);
	admin.registerAtomic(NewAtomicFunction<Wages>(), WAGES);
	admin.registerAtomic(NewAtomicFunction<InvestmentGross>(), INVESTMENTGROSS);
	admin.registerAtomic(NewAtomicFunction<ProfitNet>(), PROFITNET);
	admin.registerAtomic(NewAtomicFunction<ProfitGrossReal>(), PROFITGROSSREAL);
	admin.registerAtomic(NewAtomicFunction<piR>(), PIR);
	admin.registerAtomic(NewAtomicFunction<InvestmentFunctionReal>(), INVESTMENTFUNCTIONREAL);
	admin.registerAtomic(NewAtomicFunction<InvestmentNetReal>(), INVESTMENTNETREAL);
	admin.registerAtomic(NewAtomicFunction<chgPopulationPlus>(), CHGPOPULATIONPLUS);
	admin.registerAtomic(NewAtomicFunction<chgPopulationMinus>(), CHGPOPULATIONMINUS);
	admin.registerAtomic(NewAtomicFunction<chgLaborProductivityPlus>(), CHGLABORPRODUCTIVITYPLUS);
	admin.registerAtomic(NewAtomicFunction<chgLaborProductivityMinus>(), CHGLABORPRODUCTIVITYMINUS);
	admin.registerAtomic(NewAtomicFunction<chgDebtPlus>(), CHGDEBTPLUS);
	admin.registerAtomic(NewAtomicFunction<chgDebtMinus>(), CHGDEBTMINUS);
	admin.registerAtomic(NewAtomicFunction<chgwageRatePlus>(), CHGWAGERATEPLUS);
	admin.registerAtomic(NewAtomicFunction<chgwageRateMinus>(), CHGWAGERATEMINUS);
	admin.registerAtomic(NewAtomicFunction<chgCapitalPlus>(), CHGCAPITALPLUS);
	admin.registerAtomic(NewAtomicFunction<chgCapitalMinus>(), CHGCAPITALMINUS);
	admin.registerAtomic(NewAtomicFunction<DebtTot>(), DEBTTOT);
	admin.registerAtomic(NewAtomicFunction<wageRateTot>(), WAGERATETOT);
	admin.registerAtomic(NewAtomicFunction<LaborProductivityTot>(), LABORPRODUCTIVITYTOT);
	admin.registerAtomic(NewAtomicFunction<CapitalTot>(), CAPITALTOT);
	admin.registerAtomic(NewAtomicFunction<PopulationTot>(), POPULATIONTOT);
	//
}