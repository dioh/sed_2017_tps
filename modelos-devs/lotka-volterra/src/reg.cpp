#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "FminusHares.h"
#include "FplusHares.h"
#include "FtotHares.h"

#include "FtotLynx.h"
#include "FplusLynx.h"
#include "FminusLynx.h"


void register_atomics_on(ParallelModelAdmin &admin)
{
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);

	admin.registerAtomic(NewAtomicFunction<FminusHares>(), FMINUSHARES);
	admin.registerAtomic(NewAtomicFunction<FplusHares>(), FPLUSHARES);
	admin.registerAtomic(NewAtomicFunction<FtotHares>(), FTOTHARES);

	admin.registerAtomic(NewAtomicFunction<FminusLynx>(), FMINUSLYNX);
	admin.registerAtomic(NewAtomicFunction<FplusLynx>(), FPLUSLYNX);
	admin.registerAtomic(NewAtomicFunction<FtotLynx>(), FTOTLYNX);
}
