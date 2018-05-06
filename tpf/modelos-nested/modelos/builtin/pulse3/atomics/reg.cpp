#include "pmodeladm.h"
#include "register.h"

#include "volumetop.h"
#include "exratop.h"
#include "firstPulsetop.h"
#include "intervaltop.h"
#include "flow2_stock1DEVS_BASIC_COUPLED_stock1.h"
#include "flow1_stock1DEVS_BASIC_COUPLED_stock1.h"
#include "flow3_stock1DEVS_BASIC_COUPLED_stock1.h"
#include "PULSE_V_volume_I_interval_flow2DEVS_BASIC_COUPLED_stock1.h"
#include "PULSE_V_volume_I_interval_flow1DEVS_BASIC_COUPLED_stock1.h"
#include "Totstock1DEVS_BASIC_COUPLED_stock1.h"
#include "stock1DEVS_BASIC_COUPLED_stock1.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	//admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<volumetop>(), VOLUMETOP);
	admin.registerAtomic(NewAtomicFunction<exratop>(), EXRATOP);
	admin.registerAtomic(NewAtomicFunction<firstPulsetop>(), FIRSTPULSETOP);
	admin.registerAtomic(NewAtomicFunction<intervaltop>(), INTERVALTOP);
	admin.registerAtomic(NewAtomicFunction<flow2_stock1DEVS_BASIC_COUPLED_stock1>(), FLOW2_STOCK1DEVS_BASIC_COUPLED_STOCK1);
	admin.registerAtomic(NewAtomicFunction<flow1_stock1DEVS_BASIC_COUPLED_stock1>(), FLOW1_STOCK1DEVS_BASIC_COUPLED_STOCK1);
	admin.registerAtomic(NewAtomicFunction<flow3_stock1DEVS_BASIC_COUPLED_stock1>(), FLOW3_STOCK1DEVS_BASIC_COUPLED_STOCK1);
	admin.registerAtomic(NewAtomicFunction<PULSE_V_volume_I_interval_flow2DEVS_BASIC_COUPLED_stock1>(), PULSE_V_VOLUME_I_INTERVAL_FLOW2DEVS_BASIC_COUPLED_STOCK1);
	admin.registerAtomic(NewAtomicFunction<PULSE_V_volume_I_interval_flow1DEVS_BASIC_COUPLED_stock1>(), PULSE_V_VOLUME_I_INTERVAL_FLOW1DEVS_BASIC_COUPLED_STOCK1);
	admin.registerAtomic(NewAtomicFunction<Totstock1DEVS_BASIC_COUPLED_stock1>(), TOTSTOCK1DEVS_BASIC_COUPLED_STOCK1);
	admin.registerAtomic(NewAtomicFunction<stock1DEVS_BASIC_COUPLED_stock1>(), STOCK1DEVS_BASIC_COUPLED_STOCK1);
	
}