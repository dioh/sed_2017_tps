#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "AuxgrowthCoefficient.h"
#include "AuxratioofStocktoCapacity.h"
#include "AuxeffectofRatioofStocktoCapacityonGrowthCoefficient.h"
#include "FplusStock1Flow1.h"
#include "FtotStock1Integrator.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<AuxgrowthCoefficient>(), AUXGROWTHCOEFFICIENT);
	admin.registerAtomic(NewAtomicFunction<AuxratioofStocktoCapacity>(), AUXRATIOOFSTOCKTOCAPACITY);
	admin.registerAtomic(NewAtomicFunction<AuxeffectofRatioofStocktoCapacityonGrowthCoefficient>(), AUXEFFECTOFRATIOOFSTOCKTOCAPACITYONGROWTHCOEFFICIENT);
	admin.registerAtomic(NewAtomicFunction<FplusStock1Flow1>(), FPLUSSTOCK1FLOW1);
	admin.registerAtomic(NewAtomicFunction<FtotStock1Integrator>(), FTOTSTOCK1INTEGRATOR);
	//
}