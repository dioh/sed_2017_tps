#include "pmodeladm.h"
#include "register.h"

#include "CteRoomTemperature.h"


void register_atomics_on(ParallelModelAdmin &admin)
{
	admin.registerAtomic(NewAtomicFunction<CteRoomTemperature>(), CTEROOMTEMPERATURE);
}
