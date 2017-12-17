#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "wageFunction.h"
#include "fp_Capital_chgCapital.h"
#include "ft_Population.h"
#include "InvestmentNetReal.h"
#include "Labor.h"
#include "ft_WageRate.h"
#include "Output.h"
#include "piR.h"
#include "fp_LaborProductivity_chgLaborProductivity.h"
#include "ft_Debt.h"
#include "InvestmentGross.h"
#include "InterestPayments.h"
#include "debtRate.h"
#include "ProfitNet.h"
#include "fp_WageRate_chgWageRate.h"
#include "fp_Population_chgPopulation.h"
#include "ft_LaborProductivity.h"
#include "fp_Debt_chgDebt.h"
#include "ProfitGrossReal.h"
#include "Wages.h"
#include "Omega.h"
#include "InvestmentFunctionReal.h"
#include "employmentRate.h"
#include "ft_Capital.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<wageFunction>(), WAGEFUNCTION);
	admin.registerAtomic(NewAtomicFunction<fp_Capital_chgCapital>(), FP_CAPITAL_CHGCAPITAL);
	admin.registerAtomic(NewAtomicFunction<ft_Population>(), FT_POPULATION);
	admin.registerAtomic(NewAtomicFunction<InvestmentNetReal>(), INVESTMENTNETREAL);
	admin.registerAtomic(NewAtomicFunction<Labor>(), LABOR);
	admin.registerAtomic(NewAtomicFunction<ft_WageRate>(), FT_WAGERATE);
	admin.registerAtomic(NewAtomicFunction<Output>(), OUTPUT);
	admin.registerAtomic(NewAtomicFunction<piR>(), PIR);
	admin.registerAtomic(NewAtomicFunction<fp_LaborProductivity_chgLaborProductivity>(), FP_LABORPRODUCTIVITY_CHGLABORPRODUCTIVITY);
	admin.registerAtomic(NewAtomicFunction<ft_Debt>(), FT_DEBT);
	admin.registerAtomic(NewAtomicFunction<InvestmentGross>(), INVESTMENTGROSS);
	admin.registerAtomic(NewAtomicFunction<InterestPayments>(), INTERESTPAYMENTS);
	admin.registerAtomic(NewAtomicFunction<debtRate>(), DEBTRATE);
	admin.registerAtomic(NewAtomicFunction<ProfitNet>(), PROFITNET);
	admin.registerAtomic(NewAtomicFunction<fp_WageRate_chgWageRate>(), FP_WAGERATE_CHGWAGERATE);
	admin.registerAtomic(NewAtomicFunction<fp_Population_chgPopulation>(), FP_POPULATION_CHGPOPULATION);
	admin.registerAtomic(NewAtomicFunction<ft_LaborProductivity>(), FT_LABORPRODUCTIVITY);
	admin.registerAtomic(NewAtomicFunction<fp_Debt_chgDebt>(), FP_DEBT_CHGDEBT);
	admin.registerAtomic(NewAtomicFunction<ProfitGrossReal>(), PROFITGROSSREAL);
	admin.registerAtomic(NewAtomicFunction<Wages>(), WAGES);
	admin.registerAtomic(NewAtomicFunction<Omega>(), OMEGA);
	admin.registerAtomic(NewAtomicFunction<InvestmentFunctionReal>(), INVESTMENTFUNCTIONREAL);
	admin.registerAtomic(NewAtomicFunction<employmentRate>(), EMPLOYMENTRATE);
	admin.registerAtomic(NewAtomicFunction<ft_Capital>(), FT_CAPITAL);
	//
}