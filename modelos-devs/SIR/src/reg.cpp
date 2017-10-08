#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "FminusSusc.h"
#include "FplusSusc.h"
#include "FtotSusc.h"

#include "FtotInf.h"
#include "FplusInf.h"
#include "FminusInf.h"

#include "FtotRecov.h"
#include "FplusRecov.h"
#include "FminusRecov.h"

#include "Cte.h"


void register_atomics_on(ParallelModelAdmin &admin)
{
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);

	admin.registerAtomic(NewAtomicFunction<FminusSusc>(), FMINUSSUSC);
	admin.registerAtomic(NewAtomicFunction<FplusSusc>(), FPLUSSUSC);
	admin.registerAtomic(NewAtomicFunction<FtotSusc>(), FTOTSUSC);

	admin.registerAtomic(NewAtomicFunction<FminusInf>(), FMINUSINF);
	admin.registerAtomic(NewAtomicFunction<FplusInf>(), FPLUSINF);
	admin.registerAtomic(NewAtomicFunction<FtotInf>(), FTOTINF);

	admin.registerAtomic(NewAtomicFunction<FminusRecov>(), FMINUSRECOV);
	admin.registerAtomic(NewAtomicFunction<FplusRecov>(), FPLUSRECOV);
	admin.registerAtomic(NewAtomicFunction<FtotRecov>(), FTOTRECOV);
}
