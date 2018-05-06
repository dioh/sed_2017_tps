#include "pmodeladm.h"
#include "register.h"

#include "firstPulseXtop.h"
#include "volumeXtop.h"
#include "intervalXtop.h"
#include "flow1_stock1DEVS_BASIC_COUPLED_stock1.h"
#include "flow2_stock1DEVS_BASIC_COUPLED_stock1.h"
#include "PULSE_V_volumeX_I_intervalX_flow1DEVS_BASIC_COUPLED_stock1.h"
#include "Totstock1DEVS_BASIC_COUPLED_stock1.h"
#include "stock1DEVS_BASIC_COUPLED_stock1.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	//admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<firstPulseXtop>(), FIRSTPULSEXTOP);
	admin.registerAtomic(NewAtomicFunction<volumeXtop>(), VOLUMEXTOP);
	admin.registerAtomic(NewAtomicFunction<intervalXtop>(), INTERVALXTOP);
	admin.registerAtomic(NewAtomicFunction<flow1_stock1DEVS_BASIC_COUPLED_stock1>(), FLOW1_STOCK1DEVS_BASIC_COUPLED_STOCK1);
	admin.registerAtomic(NewAtomicFunction<flow2_stock1DEVS_BASIC_COUPLED_stock1>(), FLOW2_STOCK1DEVS_BASIC_COUPLED_STOCK1);
	admin.registerAtomic(NewAtomicFunction<PULSE_V_volumeX_I_intervalX_flow1DEVS_BASIC_COUPLED_stock1>(), PULSE_V_VOLUMEX_I_INTERVALX_FLOW1DEVS_BASIC_COUPLED_STOCK1);
	admin.registerAtomic(NewAtomicFunction<Totstock1DEVS_BASIC_COUPLED_stock1>(), TOTSTOCK1DEVS_BASIC_COUPLED_STOCK1);
	admin.registerAtomic(NewAtomicFunction<stock1DEVS_BASIC_COUPLED_stock1>(), STOCK1DEVS_BASIC_COUPLED_STOCK1);
	
}