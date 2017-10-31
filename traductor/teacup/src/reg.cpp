#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "FtotTeacupTemperatureIntegrator.h"
#include "FminusTeacupTemperatureHeatLosstoRoom.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<FtotTeacupTemperatureIntegrator>(), FTOTTEACUPTEMPERATUREINTEGRATOR);
	admin.registerAtomic(NewAtomicFunction<FminusTeacupTemperatureHeatLosstoRoom>(), FMINUSTEACUPTEMPERATUREHEATLOSSTOROOM);
	//
}