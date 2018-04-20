#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "paramBtop.h"
#include "paramDtop.h"
#include "paramAtop.h"
#include "paramPulsetop.h"
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
#include "TotPredatorDEVS_BASIC_COUPLED_Predator.h"
#include "TotPreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock.h"
#include "TotPreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock.h"
#include "TotPreyDEVS_BASIC_COUPLED_Prey.h"
#include "TothunterDEVS_BASIC_COUPLED_hunter.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<paramBtop>(), PARAMBTOP);
	admin.registerAtomic(NewAtomicFunction<paramDtop>(), PARAMDTOP);
	admin.registerAtomic(NewAtomicFunction<paramAtop>(), PARAMATOP);
	admin.registerAtomic(NewAtomicFunction<paramPulsetop>(), PARAMPULSETOP);
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
	admin.registerAtomic(NewAtomicFunction<TotPredatorDEVS_BASIC_COUPLED_Predator>(), TOTPREDATORDEVS_BASIC_COUPLED_PREDATOR);
	admin.registerAtomic(NewAtomicFunction<TotPreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock>(), TOTPREYSUBSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBSUBMODELSTOCK);
	admin.registerAtomic(NewAtomicFunction<TotPreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock>(), TOTPREYSUBMODELSTOCKDEVS_BASIC_COUPLED_PREYSUBMODELSTOCK);
	admin.registerAtomic(NewAtomicFunction<TotPreyDEVS_BASIC_COUPLED_Prey>(), TOTPREYDEVS_BASIC_COUPLED_PREY);
	admin.registerAtomic(NewAtomicFunction<TothunterDEVS_BASIC_COUPLED_hunter>(), TOTHUNTERDEVS_BASIC_COUPLED_HUNTER);
	
}