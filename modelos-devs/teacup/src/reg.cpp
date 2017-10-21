#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Fminus.h"
#include "Fplus.h"
#include "Ftot.h"
#include "Cte.h"


void register_atomics_on(ParallelModelAdmin &admin)
{
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	admin.registerAtomic(NewAtomicFunction<Ftot>(), FTOT);
	
	admin.registerAtomic(NewAtomicFunction<Fminus>(), FMINUS);
	admin.registerAtomic(NewAtomicFunction<Fplus>(), FPLUS);
}
