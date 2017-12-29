#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "outDegeneratesRightPlus.h"
#include "outDegeneratesRightMinus.h"
#include "neutralistsToDegeneratesPlus.h"
#include "neutralistsToDegeneratesMinus.h"
#include "rationalsToNeutralistsPlus.h"
#include "rationalsToNeutralistsMinus.h"
#include "neutralistsToRationalsPlus.h"
#include "neutralistsToRationalsMinus.h"
#include "outDegeneratesLeftPlus.h"
#include "outDegeneratesLeftMinus.h"
#include "RationalSupportersTot.h"
#include "DegeneratesTot.h"
#include "NeutralistsTot.h"
// Agregado manualmente
#include "Shocker.h"
#include "Conector.h"

// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<outDegeneratesRightPlus>(), OUTDEGENERATESRIGHTPLUS);
	admin.registerAtomic(NewAtomicFunction<outDegeneratesRightMinus>(), OUTDEGENERATESRIGHTMINUS);
	admin.registerAtomic(NewAtomicFunction<neutralistsToDegeneratesPlus>(), NEUTRALISTSTODEGENERATESPLUS);
	admin.registerAtomic(NewAtomicFunction<neutralistsToDegeneratesMinus>(), NEUTRALISTSTODEGENERATESMINUS);
	admin.registerAtomic(NewAtomicFunction<rationalsToNeutralistsPlus>(), RATIONALSTONEUTRALISTSPLUS);
	admin.registerAtomic(NewAtomicFunction<rationalsToNeutralistsMinus>(), RATIONALSTONEUTRALISTSMINUS);
	admin.registerAtomic(NewAtomicFunction<neutralistsToRationalsPlus>(), NEUTRALISTSTORATIONALSPLUS);
	admin.registerAtomic(NewAtomicFunction<neutralistsToRationalsMinus>(), NEUTRALISTSTORATIONALSMINUS);
	admin.registerAtomic(NewAtomicFunction<outDegeneratesLeftPlus>(), OUTDEGENERATESLEFTPLUS);
	admin.registerAtomic(NewAtomicFunction<outDegeneratesLeftMinus>(), OUTDEGENERATESLEFTMINUS);
	admin.registerAtomic(NewAtomicFunction<RationalSupportersTot>(), RATIONALSUPPORTERSTOT);
	admin.registerAtomic(NewAtomicFunction<DegeneratesTot>(), DEGENERATESTOT);
	admin.registerAtomic(NewAtomicFunction<NeutralistsTot>(), NEUTRALISTSTOT);
	// Agregado manualmente
	admin.registerAtomic(NewAtomicFunction<Shocker>(), SHOCKER);
	admin.registerAtomic(NewAtomicFunction<Conector>(), CONECTOR);
}