#include "pmodeladm.h"
#include "register.h"

#include "piZtop.h"
#include "employmentRateZerotop.h"
#include "Betaatop.h"
#include "rateInterestOnLoanstop.h"
#include "piStop.h"
#include "Alphaatop.h"
#include "velocityOfMoneytop.h"
#include "deltaKRealtop.h"
#include "employmentRateStabletop.h"
#include "piRtop.h"
#include "InvestmentNetRealtop.h"
#include "Wagestop.h"
#include "wageFunctiontop.h"
#include "Interesttop.h"
#include "omegatop.h"
#include "ProfitGrossRealtop.h"
#include "InvestmentGrosstop.h"
#include "Outputtop.h"
#include "Labortop.h"
#include "employmentRateValuetop.h"
#include "InvestmentFunctionRealtop.h"
#include "ProfitNettop.h"
#include "chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity.h"
#include "chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate.h"
#include "chgDebt_DebtDEVS_BASIC_COUPLED_Debt.h"
#include "chgPopulation_PopulationDEVS_BASIC_COUPLED_Population.h"
#include "chgCapital_CapitalDEVS_BASIC_COUPLED_Capital.h"
#include "TotLaborProductivityDEVS_BASIC_COUPLED_LaborProductivity.h"
#include "TotwageRateDEVS_BASIC_COUPLED_wageRate.h"
#include "TotDebtDEVS_BASIC_COUPLED_Debt.h"
#include "TotPopulationDEVS_BASIC_COUPLED_Population.h"
#include "TotCapitalDEVS_BASIC_COUPLED_Capital.h"
#include "LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity.h"
#include "wageRateDEVS_BASIC_COUPLED_wageRate.h"
#include "DebtDEVS_BASIC_COUPLED_Debt.h"
#include "PopulationDEVS_BASIC_COUPLED_Population.h"
#include "CapitalDEVS_BASIC_COUPLED_Capital.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	//admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<piZtop>(), PIZTOP);
	admin.registerAtomic(NewAtomicFunction<employmentRateZerotop>(), EMPLOYMENTRATEZEROTOP);
	admin.registerAtomic(NewAtomicFunction<Betaatop>(), BETAATOP);
	admin.registerAtomic(NewAtomicFunction<rateInterestOnLoanstop>(), RATEINTERESTONLOANSTOP);
	admin.registerAtomic(NewAtomicFunction<piStop>(), PISTOP);
	admin.registerAtomic(NewAtomicFunction<Alphaatop>(), ALPHAATOP);
	admin.registerAtomic(NewAtomicFunction<velocityOfMoneytop>(), VELOCITYOFMONEYTOP);
	admin.registerAtomic(NewAtomicFunction<deltaKRealtop>(), DELTAKREALTOP);
	admin.registerAtomic(NewAtomicFunction<employmentRateStabletop>(), EMPLOYMENTRATESTABLETOP);
	admin.registerAtomic(NewAtomicFunction<piRtop>(), PIRTOP);
	admin.registerAtomic(NewAtomicFunction<InvestmentNetRealtop>(), INVESTMENTNETREALTOP);
	admin.registerAtomic(NewAtomicFunction<Wagestop>(), WAGESTOP);
	admin.registerAtomic(NewAtomicFunction<wageFunctiontop>(), WAGEFUNCTIONTOP);
	admin.registerAtomic(NewAtomicFunction<Interesttop>(), INTERESTTOP);
	admin.registerAtomic(NewAtomicFunction<omegatop>(), OMEGATOP);
	admin.registerAtomic(NewAtomicFunction<ProfitGrossRealtop>(), PROFITGROSSREALTOP);
	admin.registerAtomic(NewAtomicFunction<InvestmentGrosstop>(), INVESTMENTGROSSTOP);
	admin.registerAtomic(NewAtomicFunction<Outputtop>(), OUTPUTTOP);
	admin.registerAtomic(NewAtomicFunction<Labortop>(), LABORTOP);
	admin.registerAtomic(NewAtomicFunction<employmentRateValuetop>(), EMPLOYMENTRATEVALUETOP);
	admin.registerAtomic(NewAtomicFunction<InvestmentFunctionRealtop>(), INVESTMENTFUNCTIONREALTOP);
	admin.registerAtomic(NewAtomicFunction<ProfitNettop>(), PROFITNETTOP);
	admin.registerAtomic(NewAtomicFunction<chgLaborProductivity_LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity>(), CHGLABORPRODUCTIVITY_LABORPRODUCTIVITYDEVS_BASIC_COUPLED_LABORPRODUCTIVITY);
	admin.registerAtomic(NewAtomicFunction<chgwageRate_wageRateDEVS_BASIC_COUPLED_wageRate>(), CHGWAGERATE_WAGERATEDEVS_BASIC_COUPLED_WAGERATE);
	admin.registerAtomic(NewAtomicFunction<chgDebt_DebtDEVS_BASIC_COUPLED_Debt>(), CHGDEBT_DEBTDEVS_BASIC_COUPLED_DEBT);
	admin.registerAtomic(NewAtomicFunction<chgPopulation_PopulationDEVS_BASIC_COUPLED_Population>(), CHGPOPULATION_POPULATIONDEVS_BASIC_COUPLED_POPULATION);
	admin.registerAtomic(NewAtomicFunction<chgCapital_CapitalDEVS_BASIC_COUPLED_Capital>(), CHGCAPITAL_CAPITALDEVS_BASIC_COUPLED_CAPITAL);
	admin.registerAtomic(NewAtomicFunction<TotLaborProductivityDEVS_BASIC_COUPLED_LaborProductivity>(), TOTLABORPRODUCTIVITYDEVS_BASIC_COUPLED_LABORPRODUCTIVITY);
	admin.registerAtomic(NewAtomicFunction<TotwageRateDEVS_BASIC_COUPLED_wageRate>(), TOTWAGERATEDEVS_BASIC_COUPLED_WAGERATE);
	admin.registerAtomic(NewAtomicFunction<TotDebtDEVS_BASIC_COUPLED_Debt>(), TOTDEBTDEVS_BASIC_COUPLED_DEBT);
	admin.registerAtomic(NewAtomicFunction<TotPopulationDEVS_BASIC_COUPLED_Population>(), TOTPOPULATIONDEVS_BASIC_COUPLED_POPULATION);
	admin.registerAtomic(NewAtomicFunction<TotCapitalDEVS_BASIC_COUPLED_Capital>(), TOTCAPITALDEVS_BASIC_COUPLED_CAPITAL);
	admin.registerAtomic(NewAtomicFunction<LaborProductivityDEVS_BASIC_COUPLED_LaborProductivity>(), LABORPRODUCTIVITYDEVS_BASIC_COUPLED_LABORPRODUCTIVITY);
	admin.registerAtomic(NewAtomicFunction<wageRateDEVS_BASIC_COUPLED_wageRate>(), WAGERATEDEVS_BASIC_COUPLED_WAGERATE);
	admin.registerAtomic(NewAtomicFunction<DebtDEVS_BASIC_COUPLED_Debt>(), DEBTDEVS_BASIC_COUPLED_DEBT);
	admin.registerAtomic(NewAtomicFunction<PopulationDEVS_BASIC_COUPLED_Population>(), POPULATIONDEVS_BASIC_COUPLED_POPULATION);
	admin.registerAtomic(NewAtomicFunction<CapitalDEVS_BASIC_COUPLED_Capital>(), CAPITALDEVS_BASIC_COUPLED_CAPITAL);
	
}