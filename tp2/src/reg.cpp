#include "pmodeladm.h"
#include "register.h"

#include "Shock0.h"
#include "Shock1.h"
#include "Shock2.h"
#include "Shock3.h"
#include "Shock4.h"


void register_atomics_on(ParallelModelAdmin &admin)
{
	admin.registerAtomic(NewAtomicFunction<Shock0>(), Shock0);
	admin.registerAtomic(NewAtomicFunction<Shock1>(), Shock1);
	admin.registerAtomic(NewAtomicFunction<Shock2>(), Shock2);
	admin.registerAtomic(NewAtomicFunction<Shock3>(), Shock3);
	admin.registerAtomic(NewAtomicFunction<Shock4>(), Shock4);
}
