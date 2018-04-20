[top]
components : ConsNWTot@ConsNWTot ConsNW@QSS1 DepInvTot@DepInvTot DepInv@QSS1 ReservesTot@ReservesTot Reserves@QSS1 WorkersNWTot@WorkersNWTot WorkersNW@QSS1 WorkersTot@WorkersTot Workers@QSS1 DepConsTot@DepConsTot DepCons@QSS1 LoansTot@LoansTot Loans@QSS1 InvNWTot@InvNWTot InvNW@QSS1 BankersNWTot@BankersNWTot BankersNW@QSS1 PiIG@PiIG CPIValue@Cte ConstantBuy@ConstantBuy tauBC@Cte bfValue@Cte wSValue@Cte tauMI@Cte tauR@Cte Repay@Repay YCValue@YCValue tauL@Cte Interest@Interest Output@Output YIValue@YIValue PiCG@PiCG rLValue@Cte IPCValue@Cte InvBuy@InvBuy Lend@Lend Money@Money ConsW@ConsW WagesI@WagesI ConsB@ConsB IntFee@IntFee tauWC@Cte WagesC@WagesC Debt@Debt velocityOfMoney@velocityOfMoney tauMC@Cte chgDepInvPlus@chgDepInvPlus chgDepInvMinus@chgDepInvMinus chgDepConsPlus@chgDepConsPlus chgDepConsMinus@chgDepConsMinus chgConsNWPlus@chgConsNWPlus chgConsNWMinus@chgConsNWMinus chgReservesPlus@chgReservesPlus chgReservesMinus@chgReservesMinus chgLoansPlus@chgLoansPlus chgLoansMinus@chgLoansMinus chgWorkersNWPlus@chgWorkersNWPlus chgWorkersNWMinus@chgWorkersNWMinus chgWorkersPlus@chgWorkersPlus chgWorkersMinus@chgWorkersMinus chgInvNWPlus@chgInvNWPlus chgInvNWMinus@chgInvNWMinus chgBankersNWPlus@chgBankersNWPlus chgBankersNWMinus@chgBankersNWMinus 

% External Input Ports
in : CPIValue tauBC bfValue wSValue tauMI tauR tauL rLValue IPCValue tauWC tauMC 
% External Output Ports
out : ConsNW DepInv Reserves WorkersNW Workers DepCons Loans InvNW BankersNW 

% Links internos (input ports => atomicos tipo 'Cte')
link : CPIValue inValue@CPIValue
link : tauBC inValue@tauBC
link : bfValue inValue@bfValue
link : wSValue inValue@wSValue
link : tauMI inValue@tauMI
link : tauR inValue@tauR
link : tauL inValue@tauL
link : rLValue inValue@rLValue
link : IPCValue inValue@IPCValue
link : tauWC inValue@tauWC
link : tauMC inValue@tauMC

% Internal I/O Connections
link : out@ConsNWTot in@ConsNW
link : out@DepInvTot in@DepInv
link : out@ReservesTot in@Reserves
link : out@WorkersNWTot in@WorkersNW
link : out@WorkersTot in@Workers
link : out@DepConsTot in@DepCons
link : out@LoansTot in@Loans
link : out@InvNWTot in@InvNW
link : out@BankersNWTot in@BankersNW
link : out@chgDepInvPlus chgDepInvPlus@DepInvTot
link : out@chgDepConsPlus chgDepConsPlus@DepConsTot
link : out@chgConsNWPlus chgConsNWPlus@ConsNWTot
link : out@chgReservesPlus chgReservesPlus@ReservesTot
link : out@chgLoansPlus chgLoansPlus@LoansTot
link : out@chgWorkersNWPlus chgWorkersNWPlus@WorkersNWTot
link : out@chgWorkersPlus chgWorkersPlus@WorkersTot
link : out@chgInvNWPlus chgInvNWPlus@InvNWTot
link : out@chgBankersNWPlus chgBankersNWPlus@BankersNWTot
link : out@DepInv DepInv@YIValue
link : out@DepInv DepInv@Money
link : out@Workers Workers@Money
link : out@Workers Workers@ConsW
link : out@DepCons DepCons@YCValue
link : out@DepCons DepCons@Lend
link : out@DepCons DepCons@Money
link : out@Loans Loans@Repay
link : out@Loans Loans@Interest
link : out@Loans Loans@Debt
link : out@BankersNW BankersNW@Money
link : out@BankersNW BankersNW@ConsB
link : out@PiIG PiIG@InvBuy
link : out@CPIValue CPIValue@ConstantBuy
link : out@ConstantBuy ConstantBuy@chgDepInvPlus
link : out@ConstantBuy ConstantBuy@chgDepInvMinus
link : out@ConstantBuy ConstantBuy@chgDepConsPlus
link : out@ConstantBuy ConstantBuy@chgDepConsMinus
link : out@ConstantBuy ConstantBuy@chgConsNWPlus
link : out@ConstantBuy ConstantBuy@chgConsNWMinus
link : out@ConstantBuy ConstantBuy@chgInvNWPlus
link : out@ConstantBuy ConstantBuy@chgInvNWMinus
link : out@tauBC tauBC@ConsB
link : out@bfValue bfValue@IntFee
link : out@wSValue wSValue@WagesI
link : out@wSValue wSValue@WagesC
link : out@tauMI tauMI@YIValue
link : out@tauR tauR@Repay
link : out@Repay Repay@chgDepInvPlus
link : out@Repay Repay@chgDepInvMinus
link : out@Repay Repay@chgDepConsPlus
link : out@Repay Repay@chgDepConsMinus
link : out@Repay Repay@chgLoansPlus
link : out@Repay Repay@chgLoansMinus
link : out@YCValue YCValue@Output
link : out@YCValue YCValue@PiCG
link : out@YCValue YCValue@WagesC
link : out@tauL tauL@Lend
link : out@Interest Interest@chgDepInvPlus
link : out@Interest Interest@chgDepInvMinus
link : out@Interest Interest@chgDepConsPlus
link : out@Interest Interest@chgDepConsMinus
link : out@Interest Interest@chgConsNWPlus
link : out@Interest Interest@chgConsNWMinus
link : out@Interest Interest@chgInvNWPlus
link : out@Interest Interest@chgInvNWMinus
link : out@Interest Interest@IntFee
link : out@Output Output@velocityOfMoney
link : out@YIValue YIValue@PiIG
link : out@YIValue YIValue@Output
link : out@YIValue YIValue@WagesI
link : out@PiCG PiCG@ConstantBuy
link : out@rLValue rLValue@Interest
link : out@IPCValue IPCValue@InvBuy
link : out@InvBuy InvBuy@chgDepInvPlus
link : out@InvBuy InvBuy@chgDepInvMinus
link : out@InvBuy InvBuy@chgDepConsPlus
link : out@InvBuy InvBuy@chgDepConsMinus
link : out@InvBuy InvBuy@chgConsNWPlus
link : out@InvBuy InvBuy@chgConsNWMinus
link : out@InvBuy InvBuy@chgInvNWPlus
link : out@InvBuy InvBuy@chgInvNWMinus
link : out@Lend Lend@chgDepInvPlus
link : out@Lend Lend@chgDepInvMinus
link : out@Lend Lend@chgDepConsPlus
link : out@Lend Lend@chgDepConsMinus
link : out@Lend Lend@chgLoansPlus
link : out@Lend Lend@chgLoansMinus
link : out@Money Money@velocityOfMoney
link : out@ConsW ConsW@chgDepConsPlus
link : out@ConsW ConsW@chgDepConsMinus
link : out@ConsW ConsW@chgConsNWPlus
link : out@ConsW ConsW@chgConsNWMinus
link : out@ConsW ConsW@chgWorkersNWPlus
link : out@ConsW ConsW@chgWorkersNWMinus
link : out@ConsW ConsW@chgWorkersPlus
link : out@ConsW ConsW@chgWorkersMinus
link : out@WagesI WagesI@chgDepInvPlus
link : out@WagesI WagesI@chgDepInvMinus
link : out@WagesI WagesI@chgWorkersNWPlus
link : out@WagesI WagesI@chgWorkersNWMinus
link : out@WagesI WagesI@chgWorkersPlus
link : out@WagesI WagesI@chgWorkersMinus
link : out@WagesI WagesI@chgInvNWPlus
link : out@WagesI WagesI@chgInvNWMinus
link : out@WagesI WagesI@PiIG
link : out@ConsB ConsB@chgDepConsPlus
link : out@ConsB ConsB@chgDepConsMinus
link : out@ConsB ConsB@chgConsNWPlus
link : out@ConsB ConsB@chgConsNWMinus
link : out@ConsB ConsB@chgBankersNWPlus
link : out@ConsB ConsB@chgBankersNWMinus
link : out@IntFee IntFee@chgDepConsPlus
link : out@IntFee IntFee@chgDepConsMinus
link : out@IntFee IntFee@chgConsNWPlus
link : out@IntFee IntFee@chgConsNWMinus
link : out@IntFee IntFee@chgBankersNWPlus
link : out@IntFee IntFee@chgBankersNWMinus
link : out@tauWC tauWC@ConsW
link : out@WagesC WagesC@chgDepConsPlus
link : out@WagesC WagesC@chgDepConsMinus
link : out@WagesC WagesC@chgConsNWPlus
link : out@WagesC WagesC@chgConsNWMinus
link : out@WagesC WagesC@chgWorkersNWPlus
link : out@WagesC WagesC@chgWorkersNWMinus
link : out@WagesC WagesC@chgWorkersPlus
link : out@WagesC WagesC@chgWorkersMinus
link : out@WagesC WagesC@PiCG
link : out@tauMC tauMC@YCValue

% Links internos (variables de interes => output ports)
link : out@ConsNW ConsNW
link : out@DepInv DepInv
link : out@Reserves Reserves
link : out@WorkersNW WorkersNW
link : out@Workers Workers
link : out@DepCons DepCons
link : out@Loans Loans
link : out@InvNW InvNW
link : out@BankersNW BankersNW

% Integradores
[ConsNW]
x0 : 100
dQRel : 0.0001
dQMin : 0.0001
[DepInv]
x0 : -0
dQRel : 0.0001
dQMin : 0.0001
[Reserves]
x0 : 100
dQRel : 0.0001
dQMin : 0.0001
[WorkersNW]
x0 : -0
dQRel : 0.0001
dQMin : 0.0001
[Workers]
x0 : -0
dQRel : 0.0001
dQMin : 0.0001
[DepCons]
x0 : 100
dQRel : 0.0001
dQMin : 0.0001
[Loans]
x0 : 0
dQRel : 0.0001
dQMin : 0.0001
[InvNW]
x0 : 0
dQRel : 0.0001
dQMin : 0.0001
[BankersNW]
x0 : -0
dQRel : 0.0001
dQMin : 0.0001