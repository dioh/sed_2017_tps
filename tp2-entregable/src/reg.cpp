#include "pmodeladm.h"
#include "register.h"

#include "Shocker.h"


void register_atomics_on(ParallelModelAdmin &admin)
{
	admin.registerAtomic(NewAtomicFunction<Shocker>(), SHOCKER);
}
