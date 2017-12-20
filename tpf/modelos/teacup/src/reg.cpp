#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "HeatLossToRoomPlus.h"
#include "HeatLossToRoomMinus.h"
#include "TemperatureTot.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<HeatLossToRoomPlus>(), HEATLOSSTOROOMPLUS);
	admin.registerAtomic(NewAtomicFunction<HeatLossToRoomMinus>(), HEATLOSSTOROOMMINUS);
	admin.registerAtomic(NewAtomicFunction<TemperatureTot>(), TEMPERATURETOT);
	//
}