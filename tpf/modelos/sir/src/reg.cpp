#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "ft_Recovered.h"
#include "fp_Recovered_Recovering.h"
#include "fm_Susceptible_Succumbing.h"
#include "fm_Infectious_Recovering.h"
#include "ft_Infectious.h"
#include "ft_Susceptible.h"
#include "fp_Infectious_Succumbing.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<ft_Recovered>(), FT_RECOVERED);
	admin.registerAtomic(NewAtomicFunction<fp_Recovered_Recovering>(), FP_RECOVERED_RECOVERING);
	admin.registerAtomic(NewAtomicFunction<fm_Susceptible_Succumbing>(), FM_SUSCEPTIBLE_SUCCUMBING);
	admin.registerAtomic(NewAtomicFunction<fm_Infectious_Recovering>(), FM_INFECTIOUS_RECOVERING);
	admin.registerAtomic(NewAtomicFunction<ft_Infectious>(), FT_INFECTIOUS);
	admin.registerAtomic(NewAtomicFunction<ft_Susceptible>(), FT_SUSCEPTIBLE);
	admin.registerAtomic(NewAtomicFunction<fp_Infectious_Succumbing>(), FP_INFECTIOUS_SUCCUMBING);
	//
}