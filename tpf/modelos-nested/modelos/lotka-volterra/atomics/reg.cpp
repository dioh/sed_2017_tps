#include "pmodeladm.h"
#include "register.h"

#include "paramBtop.h"
#include "paramCtop.h"
#include "paramAtop.h"
#include "paramDtop.h"
#include "PlusPrey_PreyDEVS_BASIC_COUPLED_Prey.h"
#include "MinusPrey_PreyDEVS_BASIC_COUPLED_Prey.h"
#include "PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator.h"
#include "MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator.h"
#include "TotPreyDEVS_BASIC_COUPLED_Prey.h"
#include "TotPredatorDEVS_BASIC_COUPLED_Predator.h"
#include "PreyDEVS_BASIC_COUPLED_Prey.h"
#include "PredatorDEVS_BASIC_COUPLED_Predator.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	//admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<paramBtop>(), PARAMBTOP);
	admin.registerAtomic(NewAtomicFunction<paramCtop>(), PARAMCTOP);
	admin.registerAtomic(NewAtomicFunction<paramAtop>(), PARAMATOP);
	admin.registerAtomic(NewAtomicFunction<paramDtop>(), PARAMDTOP);
	admin.registerAtomic(NewAtomicFunction<PlusPrey_PreyDEVS_BASIC_COUPLED_Prey>(), PLUSPREY_PREYDEVS_BASIC_COUPLED_PREY);
	admin.registerAtomic(NewAtomicFunction<MinusPrey_PreyDEVS_BASIC_COUPLED_Prey>(), MINUSPREY_PREYDEVS_BASIC_COUPLED_PREY);
	admin.registerAtomic(NewAtomicFunction<PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator>(), PLUSPREDATOR_PREDATORDEVS_BASIC_COUPLED_PREDATOR);
	admin.registerAtomic(NewAtomicFunction<MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator>(), MINUSPREDATOR_PREDATORDEVS_BASIC_COUPLED_PREDATOR);
	admin.registerAtomic(NewAtomicFunction<TotPreyDEVS_BASIC_COUPLED_Prey>(), TOTPREYDEVS_BASIC_COUPLED_PREY);
	admin.registerAtomic(NewAtomicFunction<TotPredatorDEVS_BASIC_COUPLED_Predator>(), TOTPREDATORDEVS_BASIC_COUPLED_PREDATOR);
	admin.registerAtomic(NewAtomicFunction<PreyDEVS_BASIC_COUPLED_Prey>(), PREYDEVS_BASIC_COUPLED_PREY);
	admin.registerAtomic(NewAtomicFunction<PredatorDEVS_BASIC_COUPLED_Predator>(), PREDATORDEVS_BASIC_COUPLED_PREDATOR);
	
}