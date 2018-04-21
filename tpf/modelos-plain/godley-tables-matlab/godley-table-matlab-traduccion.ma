[top]
components : FirmsTot@FirmsTot Firms@QSS1 DebtFirmsTot@DebtFirmsTot DebtFirms@QSS1 WorkersTot@WorkersTot Workers@QSS1 BankTot@BankTot Bank@QSS1 tauWVal@Cte tauT@Cte RepayF@RepayF ProfitNet@ProfitNet ConsW@ConsW Money@Money LendF@LendF tauBVal@Cte share@Cte tauR@Cte tauL@Cte ProfitShare@ProfitShare ProfitGross@ProfitGross ConsB@ConsB rateOfInterestOnLoans@Cte Interest@Interest GDProduct@GDProduct Wages@Wages WagesShare@WagesShare velocityOfMoney@velocityOfMoney BankShare@BankShare chgBankPlus@chgBankPlus chgBankMinus@chgBankMinus chgDebtFirmsPlus@chgDebtFirmsPlus chgDebtFirmsMinus@chgDebtFirmsMinus chgFirmsPlus@chgFirmsPlus chgFirmsMinus@chgFirmsMinus chgWorkersPlus@chgWorkersPlus chgWorkersMinus@chgWorkersMinus 

% External Input Ports
in : tauWVal tauT tauBVal share tauR tauL rateOfInterestOnLoans 
% External Output Ports
out : Firms DebtFirms Workers Bank 

% Links internos (input ports => atomicos tipo 'Cte')
link : tauWVal inValue@tauWVal
link : tauT inValue@tauT
link : tauBVal inValue@tauBVal
link : share inValue@share
link : tauR inValue@tauR
link : tauL inValue@tauL
link : rateOfInterestOnLoans inValue@rateOfInterestOnLoans

% Internal I/O Connections
link : out@FirmsTot in@Firms
link : out@DebtFirmsTot in@DebtFirms
link : out@WorkersTot in@Workers
link : out@BankTot in@Bank
link : out@chgBankPlus chgBankPlus@BankTot
link : out@chgDebtFirmsPlus chgDebtFirmsPlus@DebtFirmsTot
link : out@chgFirmsPlus chgFirmsPlus@FirmsTot
link : out@chgWorkersPlus chgWorkersPlus@WorkersTot
link : out@Firms Firms@Money
link : out@Firms Firms@GDProduct
link : out@DebtFirms DebtFirms@RepayF
link : out@DebtFirms DebtFirms@LendF
link : out@DebtFirms DebtFirms@Interest
link : out@Workers Workers@ConsW
link : out@Workers Workers@Money
link : out@Bank Bank@Money
link : out@Bank Bank@ConsB
link : out@tauWVal tauWVal@ConsW
link : out@tauT tauT@GDProduct
link : out@RepayF RepayF@chgDebtFirmsPlus
link : out@RepayF RepayF@chgDebtFirmsMinus
link : out@RepayF RepayF@chgFirmsPlus
link : out@RepayF RepayF@chgFirmsMinus
link : out@ProfitNet ProfitNet@ProfitShare
link : out@ConsW ConsW@chgFirmsPlus
link : out@ConsW ConsW@chgFirmsMinus
link : out@ConsW ConsW@chgWorkersPlus
link : out@ConsW ConsW@chgWorkersMinus
link : out@Money Money@velocityOfMoney
link : out@LendF LendF@chgDebtFirmsPlus
link : out@LendF LendF@chgDebtFirmsMinus
link : out@LendF LendF@chgFirmsPlus
link : out@LendF LendF@chgFirmsMinus
link : out@tauBVal tauBVal@ConsB
link : out@share share@Wages
link : out@tauR tauR@RepayF
link : out@tauL tauL@LendF
link : out@ProfitGross ProfitGross@ProfitNet
link : out@ConsB ConsB@chgBankPlus
link : out@ConsB ConsB@chgBankMinus
link : out@ConsB ConsB@chgFirmsPlus
link : out@ConsB ConsB@chgFirmsMinus
link : out@rateOfInterestOnLoans rateOfInterestOnLoans@Interest
link : out@Interest Interest@chgBankPlus
link : out@Interest Interest@chgBankMinus
link : out@Interest Interest@chgFirmsPlus
link : out@Interest Interest@chgFirmsMinus
link : out@Interest Interest@ProfitNet
link : out@Interest Interest@BankShare
link : out@GDProduct GDProduct@ProfitShare
link : out@GDProduct GDProduct@ProfitGross
link : out@GDProduct GDProduct@Wages
link : out@GDProduct GDProduct@WagesShare
link : out@GDProduct GDProduct@velocityOfMoney
link : out@GDProduct GDProduct@BankShare
link : out@Wages Wages@chgFirmsPlus
link : out@Wages Wages@chgFirmsMinus
link : out@Wages Wages@chgWorkersPlus
link : out@Wages Wages@chgWorkersMinus
link : out@Wages Wages@ProfitGross
link : out@Wages Wages@WagesShare

% Links internos (variables de interes => output ports)
link : out@Firms Firms
link : out@DebtFirms DebtFirms
link : out@Workers Workers
link : out@Bank Bank

% Integradores
[Firms]
x0 : 80
dQRel : 0.0001
dQMin : 0.0001
[DebtFirms]
x0 : 100
dQRel : 0.0001
dQMin : 0.0001
[Workers]
x0 : 12
dQRel : 0.0001
dQMin : 0.0001
[Bank]
x0 : 8
dQRel : 0.0001
dQMin : 0.0001