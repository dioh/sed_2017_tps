#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "PlusPreyPlus.h"
#include "PlusPreyMinus.h"
#include "PlusPredatorPlus.h"
#include "PlusPredatorMinus.h"
#include "MinusPredatorPlus.h"
#include "MinusPredatorMinus.h"
#include "MinusPreyPlus.h"
#include "MinusPreyMinus.h"
#include "PreyTot.h"
#include "PredatorTot.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<PlusPreyPlus>(), PLUSPREYPLUS);
	admin.registerAtomic(NewAtomicFunction<PlusPreyMinus>(), PLUSPREYMINUS);
	admin.registerAtomic(NewAtomicFunction<PlusPredatorPlus>(), PLUSPREDATORPLUS);
	admin.registerAtomic(NewAtomicFunction<PlusPredatorMinus>(), PLUSPREDATORMINUS);
	admin.registerAtomic(NewAtomicFunction<MinusPredatorPlus>(), MINUSPREDATORPLUS);
	admin.registerAtomic(NewAtomicFunction<MinusPredatorMinus>(), MINUSPREDATORMINUS);
	admin.registerAtomic(NewAtomicFunction<MinusPreyPlus>(), MINUSPREYPLUS);
	admin.registerAtomic(NewAtomicFunction<MinusPreyMinus>(), MINUSPREYMINUS);
	admin.registerAtomic(NewAtomicFunction<PreyTot>(), PREYTOT);
	admin.registerAtomic(NewAtomicFunction<PredatorTot>(), PREDATORTOT);
	//
}