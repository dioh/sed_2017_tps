#include "pmodeladm.h"
#include "register.h"

#include "intervaltop.h"
#include "volumetop.h"
#include "firstPulsetop.h"
#include "flow1_stock1DEVS_BASIC_COUPLED_stock1.h"
#include "PULSE_V_volume_FP_firstPulse_I_intervalDEVS_BASIC_COUPLED_stock1.h"
#include "Totstock1DEVS_BASIC_COUPLED_stock1.h"
#include "stock1DEVS_BASIC_COUPLED_stock1.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	//admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<intervaltop>(), INTERVALTOP);
	admin.registerAtomic(NewAtomicFunction<volumetop>(), VOLUMETOP);
	admin.registerAtomic(NewAtomicFunction<firstPulsetop>(), FIRSTPULSETOP);
	admin.registerAtomic(NewAtomicFunction<flow1_stock1DEVS_BASIC_COUPLED_stock1>(), FLOW1_STOCK1DEVS_BASIC_COUPLED_STOCK1);
	admin.registerAtomic(NewAtomicFunction<PULSE_V_volume_FP_firstPulse_I_intervalDEVS_BASIC_COUPLED_stock1>(), PULSE_V_VOLUME_FP_FIRSTPULSE_I_INTERVALDEVS_BASIC_COUPLED_STOCK1);
	admin.registerAtomic(NewAtomicFunction<Totstock1DEVS_BASIC_COUPLED_stock1>(), TOTSTOCK1DEVS_BASIC_COUPLED_STOCK1);
	admin.registerAtomic(NewAtomicFunction<stock1DEVS_BASIC_COUPLED_stock1>(), STOCK1DEVS_BASIC_COUPLED_STOCK1);
	
}