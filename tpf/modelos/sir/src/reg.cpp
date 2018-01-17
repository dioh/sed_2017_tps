#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "SuccumbingPlus.h"
#include "SuccumbingMinus.h"
#include "RecoveringPlus.h"
#include "RecoveringMinus.h"
#include "InfectedTot.h"
#include "RecoveredTot.h"
#include "SusceptiblesTot.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<SuccumbingPlus>(), SUCCUMBINGPLUS);
	admin.registerAtomic(NewAtomicFunction<SuccumbingMinus>(), SUCCUMBINGMINUS);
	admin.registerAtomic(NewAtomicFunction<RecoveringPlus>(), RECOVERINGPLUS);
	admin.registerAtomic(NewAtomicFunction<RecoveringMinus>(), RECOVERINGMINUS);
	admin.registerAtomic(NewAtomicFunction<InfectedTot>(), INFECTEDTOT);
	admin.registerAtomic(NewAtomicFunction<RecoveredTot>(), RECOVEREDTOT);
	admin.registerAtomic(NewAtomicFunction<SusceptiblesTot>(), SUSCEPTIBLESTOT);
	//
}