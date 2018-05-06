#include "pmodeladm.h"
#include "register.h"

#include "paramPulsetop.h"
#include "paramBtop.h"
#include "paramDtop.h"
#include "paramAtop.h"
#include "cteVariablePredatorModel.h"
#include "paramDPredatorModel.h"
#include "specialParamCPredatorModel.h"
#include "paramBPreyModel.h"
#include "paramAPreyModel.h"
#include "ctePulsePreySubSubModel.h"
#include "paramEtop.h"
#include "specialParamCtop.h"
#include "auxVariablePredatorModel.h"
#include "PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator.h"
#include "MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator.h"
#include "combinerPreySubSubModel.h"
#include "Flow1_PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock.h"
#include "preySubFlow_PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock.h"
#include "PlusPrey_PreyDEVS_BASIC_COUPLED_Prey.h"
#include "MinusPrey_PreyDEVS_BASIC_COUPLED_Prey.h"
#include "populationGrowth_hunterDEVS_BASIC_COUPLED_hunter.h"
#include "populationDeath_hunterDEVS_BASIC_COUPLED_hunter.h"
#include "PULSE_V_1_FP_1_I_1_paramEDEVS_COUPLED_top.h"
#include "PULSE_V_2_FP_2_I_2_specialParamCDEVS_COUPLED_top.h"
#include "PULSE_V_combiner_FP_10_I_50_Flow1DEVS_BASIC_COUPLED_PreySubSubModelStock.h"
#include "PULSE_V_paramPulse_FP_1_I_1_populationGrowthDEVS_BASIC_COUPLED_hunter.h"
#include "TotPredatorDEVS_BASIC_COUPLED_Predator.h"
#include "TotPreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock.h"
#include "TotPreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock.h"
#include "TotPreyDEVS_BASIC_COUPLED_Prey.h"
#include "TothunterDEVS_BASIC_COUPLED_hunter.h"
#include "PredatorDEVS_BASIC_COUPLED_Predator.h"
#include "PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock.h"
#include "PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock.h"
#include "PreyDEVS_BASIC_COUPLED_Prey.h"
#include "hunterDEVS_BASIC_COUPLED_hunter.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	//admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<paramPulsetop>(), PARAMPULSETOP);
	admin.registerAtomic(NewAtomicFunction<paramBtop>(), PARAMBTOP);
	admin.registerAtomic(NewAtomicFunction<paramDtop>(), PARAMDTOP);
	admin.registerAtomic(NewAtomicFunction<paramAtop>(), PARAMATOP);
	admin.registerAtomic(NewAtomicFunction<cteVariablePredatorModel>(), CTEVARIABLEPREDATORMODEL);
	admin.registerAtomic(NewAtomicFunction<paramDPredatorModel>(), PARAMDPREDATORMODEL);
	admin.registerAtomic(NewAtomicFunction<specialParamCPredatorModel>(), SPECIALPARAMCPREDATORMODEL);
	admin.registerAtomic(NewAtomicFunction<paramBPreyModel>(), PARAMBPREYMODEL);
	admin.registerAtomic(NewAtomicFunction<paramAPreyModel>(), PARAMAPREYMODEL);
	admin.registerAtomic(NewAtomicFunction<ctePulsePreySubSubModel>(), CTEPULSEPREYSUBSUBMODEL);
	admin.registerAtomic(NewAtomicFunction<paramEtop>(), PARAMETOP);
	admin.registerAtomic(NewAtomicFunction<specialParamCtop>(), SPECIALPARAMCTOP);
	admin.registerAtomic(NewAtomicFunction<auxVariablePredatorModel>(), AUXVARIABLEPREDATORMODEL);
	admin.registerAtomic(NewAtomicFunction<PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator>(), PLUSPREDATOR_PREDATORDEVS_BASIC_COUPLED_PREDATOR);
	admin.registerAtomic(NewAtomicFunction<MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator>(), MINUSPREDATOR_PREDATORDEVS_BASIC_COUPLED_PREDATOR);
	admin.registerAtomic(NewAtomicFunction<combinerPreySubSubModel>(), COMBINERPREYSUBSUBMODEL);
	admin.registerAtomic(NewAtomicFunction<Flow1_PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock>(), FLOW1_PREYSUBSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBSUBMODELSTOCK);
	admin.registerAtomic(NewAtomicFunction<preySubFlow_PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock>(), PREYSUBFLOW_PREYSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBMODELSTOCK);
	admin.registerAtomic(NewAtomicFunction<PlusPrey_PreyDEVS_BASIC_COUPLED_Prey>(), PLUSPREY_PREYDEVS_BASIC_COUPLED_PREY);
	admin.registerAtomic(NewAtomicFunction<MinusPrey_PreyDEVS_BASIC_COUPLED_Prey>(), MINUSPREY_PREYDEVS_BASIC_COUPLED_PREY);
	admin.registerAtomic(NewAtomicFunction<populationGrowth_hunterDEVS_BASIC_COUPLED_hunter>(), POPULATIONGROWTH_HUNTERDEVS_BASIC_COUPLED_HUNTER);
	admin.registerAtomic(NewAtomicFunction<populationDeath_hunterDEVS_BASIC_COUPLED_hunter>(), POPULATIONDEATH_HUNTERDEVS_BASIC_COUPLED_HUNTER);
	admin.registerAtomic(NewAtomicFunction<PULSE_V_1_FP_1_I_1_paramEDEVS_COUPLED_top>(), PULSE_V_1_FP_1_I_1_PARAMEDEVS_COUPLED_TOP);
	admin.registerAtomic(NewAtomicFunction<PULSE_V_2_FP_2_I_2_specialParamCDEVS_COUPLED_top>(), PULSE_V_2_FP_2_I_2_SPECIALPARAMCDEVS_COUPLED_TOP);
	admin.registerAtomic(NewAtomicFunction<PULSE_V_combiner_FP_10_I_50_Flow1DEVS_BASIC_COUPLED_PreySubSubModelStock>(), PULSE_V_COMBINER_FP_10_I_50_FLOW1DEVS_BASIC_COUPLED_PREYSUBSUBMODELSTOCK);
	admin.registerAtomic(NewAtomicFunction<PULSE_V_paramPulse_FP_1_I_1_populationGrowthDEVS_BASIC_COUPLED_hunter>(), PULSE_V_PARAMPULSE_FP_1_I_1_POPULATIONGROWTHDEVS_BASIC_COUPLED_HUNTER);
	admin.registerAtomic(NewAtomicFunction<TotPredatorDEVS_BASIC_COUPLED_Predator>(), TOTPREDATORDEVS_BASIC_COUPLED_PREDATOR);
	admin.registerAtomic(NewAtomicFunction<TotPreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock>(), TOTPREYSUBSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBSUBMODELSTOCK);
	admin.registerAtomic(NewAtomicFunction<TotPreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock>(), TOTPREYSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBMODELSTOCK);
	admin.registerAtomic(NewAtomicFunction<TotPreyDEVS_BASIC_COUPLED_Prey>(), TOTPREYDEVS_BASIC_COUPLED_PREY);
	admin.registerAtomic(NewAtomicFunction<TothunterDEVS_BASIC_COUPLED_hunter>(), TOTHUNTERDEVS_BASIC_COUPLED_HUNTER);
	admin.registerAtomic(NewAtomicFunction<PredatorDEVS_BASIC_COUPLED_Predator>(), PREDATORDEVS_BASIC_COUPLED_PREDATOR);
	admin.registerAtomic(NewAtomicFunction<PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock>(), PREYSUBSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBSUBMODELSTOCK);
	admin.registerAtomic(NewAtomicFunction<PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock>(), PREYSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBMODELSTOCK);
	admin.registerAtomic(NewAtomicFunction<PreyDEVS_BASIC_COUPLED_Prey>(), PREYDEVS_BASIC_COUPLED_PREY);
	admin.registerAtomic(NewAtomicFunction<hunterDEVS_BASIC_COUPLED_hunter>(), HUNTERDEVS_BASIC_COUPLED_HUNTER);
	
}