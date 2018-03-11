#include "pmodeladm.h"
#include "register.h"

#include "qss1.h"
#include "Cte.h"
#include "RepayF.h"
#include "ProfitNet.h"
#include "ConsW.h"
#include "Money.h"
#include "LendF.h"
#include "ProfitShare.h"
#include "ProfitGross.h"
#include "ConsB.h"
#include "Interest.h"
#include "GDProduct.h"
#include "Wages.h"
#include "WagesShare.h"
#include "velocityOfMoney.h"
#include "BankShare.h"
#include "chgBankPlus.h"
#include "chgBankMinus.h"
#include "chgDebtFirmsPlus.h"
#include "chgDebtFirmsMinus.h"
#include "chgFirmsPlus.h"
#include "chgFirmsMinus.h"
#include "chgWorkersPlus.h"
#include "chgWorkersMinus.h"
#include "FirmsTot.h"
#include "DebtFirmsTot.h"
#include "WorkersTot.h"
#include "BankTot.h"
// Registro modelos atomicos
void register_atomics_on(ParallelModelAdmin &admin)
{
	// Atomicos base
	admin.registerAtomic(NewAtomicFunction<QSS1>(), QSS_MODEL_NAME);
	admin.registerAtomic(NewAtomicFunction<Cte>(), CTE);
	
	// Atomicos especificos del modelo
	admin.registerAtomic(NewAtomicFunction<RepayF>(), REPAYF);
	admin.registerAtomic(NewAtomicFunction<ProfitNet>(), PROFITNET);
	admin.registerAtomic(NewAtomicFunction<ConsW>(), CONSW);
	admin.registerAtomic(NewAtomicFunction<Money>(), MONEY);
	admin.registerAtomic(NewAtomicFunction<LendF>(), LENDF);
	admin.registerAtomic(NewAtomicFunction<ProfitShare>(), PROFITSHARE);
	admin.registerAtomic(NewAtomicFunction<ProfitGross>(), PROFITGROSS);
	admin.registerAtomic(NewAtomicFunction<ConsB>(), CONSB);
	admin.registerAtomic(NewAtomicFunction<Interest>(), INTEREST);
	admin.registerAtomic(NewAtomicFunction<GDProduct>(), GDPRODUCT);
	admin.registerAtomic(NewAtomicFunction<Wages>(), WAGES);
	admin.registerAtomic(NewAtomicFunction<WagesShare>(), WAGESSHARE);
	admin.registerAtomic(NewAtomicFunction<velocityOfMoney>(), VELOCITYOFMONEY);
	admin.registerAtomic(NewAtomicFunction<BankShare>(), BANKSHARE);
	admin.registerAtomic(NewAtomicFunction<chgBankPlus>(), CHGBANKPLUS);
	admin.registerAtomic(NewAtomicFunction<chgBankMinus>(), CHGBANKMINUS);
	admin.registerAtomic(NewAtomicFunction<chgDebtFirmsPlus>(), CHGDEBTFIRMSPLUS);
	admin.registerAtomic(NewAtomicFunction<chgDebtFirmsMinus>(), CHGDEBTFIRMSMINUS);
	admin.registerAtomic(NewAtomicFunction<chgFirmsPlus>(), CHGFIRMSPLUS);
	admin.registerAtomic(NewAtomicFunction<chgFirmsMinus>(), CHGFIRMSMINUS);
	admin.registerAtomic(NewAtomicFunction<chgWorkersPlus>(), CHGWORKERSPLUS);
	admin.registerAtomic(NewAtomicFunction<chgWorkersMinus>(), CHGWORKERSMINUS);
	admin.registerAtomic(NewAtomicFunction<FirmsTot>(), FIRMSTOT);
	admin.registerAtomic(NewAtomicFunction<DebtFirmsTot>(), DEBTFIRMSTOT);
	admin.registerAtomic(NewAtomicFunction<WorkersTot>(), WORKERSTOT);
	admin.registerAtomic(NewAtomicFunction<BankTot>(), BANKTOT);
	//
}