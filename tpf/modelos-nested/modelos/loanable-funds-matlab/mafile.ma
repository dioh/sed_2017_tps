
[top]
%Coupled model
components: ConsB0@ConsBtop ConsW0@ConsWtop ConstantBuy0@ConstantBuytop Debt0@Debttop IntFee0@IntFeetop Interest0@Interesttop InvBuy0@InvBuytop Lend0@Lendtop Money0@Moneytop Output0@Outputtop PiCG0@PiCGtop PiIG0@PiIGtop Repay0@Repaytop WagesC0@WagesCtop WagesI0@WagesItop YCValue0@YCValuetop YIValue0@YIValuetop velocityOfMoney0@velocityOfMoneytop  DEVS_BASIC_COUPLED_BankersNW  DEVS_BASIC_COUPLED_ConsNW  DEVS_BASIC_COUPLED_DepCons  DEVS_BASIC_COUPLED_DepInv  DEVS_BASIC_COUPLED_InvNW  DEVS_BASIC_COUPLED_Loans  DEVS_BASIC_COUPLED_Reserves  DEVS_BASIC_COUPLED_Workers  DEVS_BASIC_COUPLED_WorkersNW CPIValue0@CPIValuetop IPCValue0@IPCValuetop bfValue0@bfValuetop rLValue0@rLValuetop tauBC0@tauBCtop tauL0@tauLtop tauMC0@tauMCtop tauMI0@tauMItop tauR0@tauRtop tauWC0@tauWCtop wSValue0@wSValuetop

% In ports
in: in_port_CPIValue in_port_IPCValue in_port_bfValue in_port_rLValue in_port_tauBC in_port_tauL in_port_tauMC in_port_tauMI in_port_tauR in_port_tauWC in_port_wSValue


% Out ports
out: out_port_BankersNW out_port_ConsB out_port_ConsNW out_port_ConsW out_port_ConstantBuy out_port_Debt out_port_DepCons out_port_DepInv out_port_IntFee out_port_Interest out_port_InvBuy out_port_InvNW out_port_Lend out_port_Loans out_port_Money out_port_Output out_port_PiCG out_port_PiIG out_port_Repay out_port_Reserves out_port_WagesC out_port_WagesI out_port_Workers out_port_WorkersNW out_port_YCValue out_port_YIValue out_port_velocityOfMoney

% Input connections
link: in_port_CPIValue in_port_CPIValue@CPIValue0
link: in_port_IPCValue in_port_IPCValue@IPCValue0
link: in_port_bfValue in_port_bfValue@bfValue0
link: in_port_rLValue in_port_rLValue@rLValue0
link: in_port_tauBC in_port_tauBC@tauBC0
link: in_port_tauL in_port_tauL@tauL0
link: in_port_tauMC in_port_tauMC@tauMC0
link: in_port_tauMI in_port_tauMI@tauMI0
link: in_port_tauR in_port_tauR@tauR0
link: in_port_tauWC in_port_tauWC@tauWC0
link: in_port_wSValue in_port_wSValue@wSValue0

% Output connections
link: out_port_BankersNW@DEVS_BASIC_COUPLED_BankersNW out_port_BankersNW
link: out_port_ConsB@ConsB0 out_port_ConsB
link: out_port_ConsNW@DEVS_BASIC_COUPLED_ConsNW out_port_ConsNW
link: out_port_ConsW@ConsW0 out_port_ConsW
link: out_port_ConstantBuy@ConstantBuy0 out_port_ConstantBuy
link: out_port_Debt@Debt0 out_port_Debt
link: out_port_DepCons@DEVS_BASIC_COUPLED_DepCons out_port_DepCons
link: out_port_DepInv@DEVS_BASIC_COUPLED_DepInv out_port_DepInv
link: out_port_IntFee@IntFee0 out_port_IntFee
link: out_port_Interest@Interest0 out_port_Interest
link: out_port_InvBuy@InvBuy0 out_port_InvBuy
link: out_port_InvNW@DEVS_BASIC_COUPLED_InvNW out_port_InvNW
link: out_port_Lend@Lend0 out_port_Lend
link: out_port_Loans@DEVS_BASIC_COUPLED_Loans out_port_Loans
link: out_port_Money@Money0 out_port_Money
link: out_port_Output@Output0 out_port_Output
link: out_port_PiCG@PiCG0 out_port_PiCG
link: out_port_PiIG@PiIG0 out_port_PiIG
link: out_port_Repay@Repay0 out_port_Repay
link: out_port_Reserves@DEVS_BASIC_COUPLED_Reserves out_port_Reserves
link: out_port_WagesC@WagesC0 out_port_WagesC
link: out_port_WagesI@WagesI0 out_port_WagesI
link: out_port_Workers@DEVS_BASIC_COUPLED_Workers out_port_Workers
link: out_port_WorkersNW@DEVS_BASIC_COUPLED_WorkersNW out_port_WorkersNW
link: out_port_YCValue@YCValue0 out_port_YCValue
link: out_port_YIValue@YIValue0 out_port_YIValue
link: out_port_velocityOfMoney@velocityOfMoney0 out_port_velocityOfMoney

% Internal connections
link: out_port_BankersNW@DEVS_BASIC_COUPLED_BankersNW in_port_BankersNW@ConsB0
link: out_port_tauBC@tauBC0 in_port_tauBC@ConsB0
link: out_port_Workers@DEVS_BASIC_COUPLED_Workers in_port_Workers@ConsW0
link: out_port_tauWC@tauWC0 in_port_tauWC@ConsW0
link: out_port_CPIValue@CPIValue0 in_port_CPIValue@ConstantBuy0
link: out_port_PiCG@PiCG0 in_port_PiCG@ConstantBuy0
link: out_port_ConsB@ConsB0 in_port_ConsB@DEVS_BASIC_COUPLED_BankersNW
link: out_port_IntFee@IntFee0 in_port_IntFee@DEVS_BASIC_COUPLED_BankersNW
link: out_port_ConsB@ConsB0 in_port_ConsB@DEVS_BASIC_COUPLED_ConsNW
link: out_port_ConsW@ConsW0 in_port_ConsW@DEVS_BASIC_COUPLED_ConsNW
link: out_port_ConstantBuy@ConstantBuy0 in_port_ConstantBuy@DEVS_BASIC_COUPLED_ConsNW
link: out_port_IntFee@IntFee0 in_port_IntFee@DEVS_BASIC_COUPLED_ConsNW
link: out_port_Interest@Interest0 in_port_Interest@DEVS_BASIC_COUPLED_ConsNW
link: out_port_InvBuy@InvBuy0 in_port_InvBuy@DEVS_BASIC_COUPLED_ConsNW
link: out_port_WagesC@WagesC0 in_port_WagesC@DEVS_BASIC_COUPLED_ConsNW
link: out_port_ConsB@ConsB0 in_port_ConsB@DEVS_BASIC_COUPLED_DepCons
link: out_port_ConsW@ConsW0 in_port_ConsW@DEVS_BASIC_COUPLED_DepCons
link: out_port_ConstantBuy@ConstantBuy0 in_port_ConstantBuy@DEVS_BASIC_COUPLED_DepCons
link: out_port_IntFee@IntFee0 in_port_IntFee@DEVS_BASIC_COUPLED_DepCons
link: out_port_Interest@Interest0 in_port_Interest@DEVS_BASIC_COUPLED_DepCons
link: out_port_InvBuy@InvBuy0 in_port_InvBuy@DEVS_BASIC_COUPLED_DepCons
link: out_port_Lend@Lend0 in_port_Lend@DEVS_BASIC_COUPLED_DepCons
link: out_port_Repay@Repay0 in_port_Repay@DEVS_BASIC_COUPLED_DepCons
link: out_port_WagesC@WagesC0 in_port_WagesC@DEVS_BASIC_COUPLED_DepCons
link: out_port_ConstantBuy@ConstantBuy0 in_port_ConstantBuy@DEVS_BASIC_COUPLED_DepInv
link: out_port_Interest@Interest0 in_port_Interest@DEVS_BASIC_COUPLED_DepInv
link: out_port_InvBuy@InvBuy0 in_port_InvBuy@DEVS_BASIC_COUPLED_DepInv
link: out_port_Lend@Lend0 in_port_Lend@DEVS_BASIC_COUPLED_DepInv
link: out_port_Repay@Repay0 in_port_Repay@DEVS_BASIC_COUPLED_DepInv
link: out_port_WagesI@WagesI0 in_port_WagesI@DEVS_BASIC_COUPLED_DepInv
link: out_port_ConstantBuy@ConstantBuy0 in_port_ConstantBuy@DEVS_BASIC_COUPLED_InvNW
link: out_port_Interest@Interest0 in_port_Interest@DEVS_BASIC_COUPLED_InvNW
link: out_port_InvBuy@InvBuy0 in_port_InvBuy@DEVS_BASIC_COUPLED_InvNW
link: out_port_WagesI@WagesI0 in_port_WagesI@DEVS_BASIC_COUPLED_InvNW
link: out_port_Lend@Lend0 in_port_Lend@DEVS_BASIC_COUPLED_Loans
link: out_port_Repay@Repay0 in_port_Repay@DEVS_BASIC_COUPLED_Loans
link: out_port_ConsW@ConsW0 in_port_ConsW@DEVS_BASIC_COUPLED_Workers
link: out_port_WagesC@WagesC0 in_port_WagesC@DEVS_BASIC_COUPLED_Workers
link: out_port_WagesI@WagesI0 in_port_WagesI@DEVS_BASIC_COUPLED_Workers
link: out_port_ConsW@ConsW0 in_port_ConsW@DEVS_BASIC_COUPLED_WorkersNW
link: out_port_WagesC@WagesC0 in_port_WagesC@DEVS_BASIC_COUPLED_WorkersNW
link: out_port_WagesI@WagesI0 in_port_WagesI@DEVS_BASIC_COUPLED_WorkersNW
link: out_port_Loans@DEVS_BASIC_COUPLED_Loans in_port_Loans@Debt0
link: out_port_Interest@Interest0 in_port_Interest@IntFee0
link: out_port_bfValue@bfValue0 in_port_bfValue@IntFee0
link: out_port_Loans@DEVS_BASIC_COUPLED_Loans in_port_Loans@Interest0
link: out_port_rLValue@rLValue0 in_port_rLValue@Interest0
link: out_port_IPCValue@IPCValue0 in_port_IPCValue@InvBuy0
link: out_port_PiIG@PiIG0 in_port_PiIG@InvBuy0
link: out_port_DepCons@DEVS_BASIC_COUPLED_DepCons in_port_DepCons@Lend0
link: out_port_tauL@tauL0 in_port_tauL@Lend0
link: out_port_BankersNW@DEVS_BASIC_COUPLED_BankersNW in_port_BankersNW@Money0
link: out_port_DepCons@DEVS_BASIC_COUPLED_DepCons in_port_DepCons@Money0
link: out_port_DepInv@DEVS_BASIC_COUPLED_DepInv in_port_DepInv@Money0
link: out_port_Workers@DEVS_BASIC_COUPLED_Workers in_port_Workers@Money0
link: out_port_YCValue@YCValue0 in_port_YCValue@Output0
link: out_port_YIValue@YIValue0 in_port_YIValue@Output0
link: out_port_WagesC@WagesC0 in_port_WagesC@PiCG0
link: out_port_YCValue@YCValue0 in_port_YCValue@PiCG0
link: out_port_WagesI@WagesI0 in_port_WagesI@PiIG0
link: out_port_YIValue@YIValue0 in_port_YIValue@PiIG0
link: out_port_Loans@DEVS_BASIC_COUPLED_Loans in_port_Loans@Repay0
link: out_port_tauR@tauR0 in_port_tauR@Repay0
link: out_port_YCValue@YCValue0 in_port_YCValue@WagesC0
link: out_port_wSValue@wSValue0 in_port_wSValue@WagesC0
link: out_port_YIValue@YIValue0 in_port_YIValue@WagesI0
link: out_port_wSValue@wSValue0 in_port_wSValue@WagesI0
link: out_port_DepCons@DEVS_BASIC_COUPLED_DepCons in_port_DepCons@YCValue0
link: out_port_tauMC@tauMC0 in_port_tauMC@YCValue0
link: out_port_DepInv@DEVS_BASIC_COUPLED_DepInv in_port_DepInv@YIValue0
link: out_port_tauMI@tauMI0 in_port_tauMI@YIValue0
link: out_port_Money@Money0 in_port_Money@velocityOfMoney0
link: out_port_Output@Output0 in_port_Output@velocityOfMoney0

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')





































[DEVS_BASIC_COUPLED_BankersNW]
%Coupled model
components: chgBankersNW_BankersNW1@chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW TotBankersNW1@TotBankersNWDEVS_BASIC_COUPLED_BankersNW BankersNW1@BankersNWDEVS_BASIC_COUPLED_BankersNW

% In ports
in: in_port_ConsB in_port_IntFee


% Out ports
out: out_port_BankersNW

% Input connections
link: in_port_ConsB in_port_ConsB@chgBankersNW_BankersNW1
link: in_port_IntFee in_port_IntFee@chgBankersNW_BankersNW1

% Output connections
link: out_port_BankersNW@BankersNW1 out_port_BankersNW

% Internal connections
link: out_port_TotBankersNW@TotBankersNW1 in_port_TotBankersNW@BankersNW1
link: out_port_chgBankersNW_BankersNW@chgBankersNW_BankersNW1 in_plus_port_chgBankersNW_BankersNW@TotBankersNW1

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[BankersNW1]
% Atomic model DEVSIntegrator
x0: -0
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_ConsNW]
%Coupled model
components: chgConsNW_ConsNW1@chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW TotConsNW1@TotConsNWDEVS_BASIC_COUPLED_ConsNW ConsNW1@ConsNWDEVS_BASIC_COUPLED_ConsNW

% In ports
in: in_port_ConsB in_port_ConsW in_port_ConstantBuy in_port_IntFee in_port_Interest in_port_InvBuy in_port_WagesC


% Out ports
out: out_port_ConsNW

% Input connections
link: in_port_ConsB in_port_ConsB@chgConsNW_ConsNW1
link: in_port_ConsW in_port_ConsW@chgConsNW_ConsNW1
link: in_port_ConstantBuy in_port_ConstantBuy@chgConsNW_ConsNW1
link: in_port_IntFee in_port_IntFee@chgConsNW_ConsNW1
link: in_port_Interest in_port_Interest@chgConsNW_ConsNW1
link: in_port_InvBuy in_port_InvBuy@chgConsNW_ConsNW1
link: in_port_WagesC in_port_WagesC@chgConsNW_ConsNW1

% Output connections
link: out_port_ConsNW@ConsNW1 out_port_ConsNW

% Internal connections
link: out_port_TotConsNW@TotConsNW1 in_port_TotConsNW@ConsNW1
link: out_port_chgConsNW_ConsNW@chgConsNW_ConsNW1 in_plus_port_chgConsNW_ConsNW@TotConsNW1

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[ConsNW1]
% Atomic model DEVSIntegrator
x0: 100
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_DepCons]
%Coupled model
components: chgDepCons_DepCons1@chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons TotDepCons1@TotDepConsDEVS_BASIC_COUPLED_DepCons DepCons1@DepConsDEVS_BASIC_COUPLED_DepCons

% In ports
in: in_port_ConsB in_port_ConsW in_port_ConstantBuy in_port_IntFee in_port_Interest in_port_InvBuy in_port_Lend in_port_Repay in_port_WagesC


% Out ports
out: out_port_DepCons

% Input connections
link: in_port_ConsB in_port_ConsB@chgDepCons_DepCons1
link: in_port_ConsW in_port_ConsW@chgDepCons_DepCons1
link: in_port_ConstantBuy in_port_ConstantBuy@chgDepCons_DepCons1
link: in_port_IntFee in_port_IntFee@chgDepCons_DepCons1
link: in_port_Interest in_port_Interest@chgDepCons_DepCons1
link: in_port_InvBuy in_port_InvBuy@chgDepCons_DepCons1
link: in_port_Lend in_port_Lend@chgDepCons_DepCons1
link: in_port_Repay in_port_Repay@chgDepCons_DepCons1
link: in_port_WagesC in_port_WagesC@chgDepCons_DepCons1

% Output connections
link: out_port_DepCons@DepCons1 out_port_DepCons

% Internal connections
link: out_port_TotDepCons@TotDepCons1 in_port_TotDepCons@DepCons1
link: out_port_chgDepCons_DepCons@chgDepCons_DepCons1 in_plus_port_chgDepCons_DepCons@TotDepCons1

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[DepCons1]
% Atomic model DEVSIntegrator
x0: 100
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_DepInv]
%Coupled model
components: chgDepInv_DepInv1@chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv TotDepInv1@TotDepInvDEVS_BASIC_COUPLED_DepInv DepInv1@DepInvDEVS_BASIC_COUPLED_DepInv

% In ports
in: in_port_ConstantBuy in_port_Interest in_port_InvBuy in_port_Lend in_port_Repay in_port_WagesI


% Out ports
out: out_port_DepInv

% Input connections
link: in_port_ConstantBuy in_port_ConstantBuy@chgDepInv_DepInv1
link: in_port_Interest in_port_Interest@chgDepInv_DepInv1
link: in_port_InvBuy in_port_InvBuy@chgDepInv_DepInv1
link: in_port_Lend in_port_Lend@chgDepInv_DepInv1
link: in_port_Repay in_port_Repay@chgDepInv_DepInv1
link: in_port_WagesI in_port_WagesI@chgDepInv_DepInv1

% Output connections
link: out_port_DepInv@DepInv1 out_port_DepInv

% Internal connections
link: out_port_TotDepInv@TotDepInv1 in_port_TotDepInv@DepInv1
link: out_port_chgDepInv_DepInv@chgDepInv_DepInv1 in_plus_port_chgDepInv_DepInv@TotDepInv1

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[DepInv1]
% Atomic model DEVSIntegrator
x0: -0
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_InvNW]
%Coupled model
components: chgInvNW_InvNW1@chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW TotInvNW1@TotInvNWDEVS_BASIC_COUPLED_InvNW InvNW1@InvNWDEVS_BASIC_COUPLED_InvNW

% In ports
in: in_port_ConstantBuy in_port_Interest in_port_InvBuy in_port_WagesI


% Out ports
out: out_port_InvNW

% Input connections
link: in_port_ConstantBuy in_port_ConstantBuy@chgInvNW_InvNW1
link: in_port_Interest in_port_Interest@chgInvNW_InvNW1
link: in_port_InvBuy in_port_InvBuy@chgInvNW_InvNW1
link: in_port_WagesI in_port_WagesI@chgInvNW_InvNW1

% Output connections
link: out_port_InvNW@InvNW1 out_port_InvNW

% Internal connections
link: out_port_TotInvNW@TotInvNW1 in_port_TotInvNW@InvNW1
link: out_port_chgInvNW_InvNW@chgInvNW_InvNW1 in_plus_port_chgInvNW_InvNW@TotInvNW1

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[InvNW1]
% Atomic model DEVSIntegrator
x0: 0
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_Loans]
%Coupled model
components: chgLoans_Loans1@chgLoans_LoansDEVS_BASIC_COUPLED_Loans TotLoans1@TotLoansDEVS_BASIC_COUPLED_Loans Loans1@LoansDEVS_BASIC_COUPLED_Loans

% In ports
in: in_port_Lend in_port_Repay


% Out ports
out: out_port_Loans

% Input connections
link: in_port_Lend in_port_Lend@chgLoans_Loans1
link: in_port_Repay in_port_Repay@chgLoans_Loans1

% Output connections
link: out_port_Loans@Loans1 out_port_Loans

% Internal connections
link: out_port_TotLoans@TotLoans1 in_port_TotLoans@Loans1
link: out_port_chgLoans_Loans@chgLoans_Loans1 in_plus_port_chgLoans_Loans@TotLoans1

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[Loans1]
% Atomic model DEVSIntegrator
x0: 0
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_Reserves]
%Coupled model
components: chgReserves_Reserves1@chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves TotReserves1@TotReservesDEVS_BASIC_COUPLED_Reserves Reserves1@ReservesDEVS_BASIC_COUPLED_Reserves

% In ports


% Out ports
out: out_port_Reserves

% Input connections

% Output connections
link: out_port_Reserves@Reserves1 out_port_Reserves

% Internal connections
link: out_port_TotReserves@TotReserves1 in_port_TotReserves@Reserves1
link: out_port_chgReserves_Reserves@chgReserves_Reserves1 in_plus_port_chgReserves_Reserves@TotReserves1

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[Reserves1]
% Atomic model DEVSIntegrator
x0: 100
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_Workers]
%Coupled model
components: chgWorkers_Workers1@chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers TotWorkers1@TotWorkersDEVS_BASIC_COUPLED_Workers Workers1@WorkersDEVS_BASIC_COUPLED_Workers

% In ports
in: in_port_ConsW in_port_WagesC in_port_WagesI


% Out ports
out: out_port_Workers

% Input connections
link: in_port_ConsW in_port_ConsW@chgWorkers_Workers1
link: in_port_WagesC in_port_WagesC@chgWorkers_Workers1
link: in_port_WagesI in_port_WagesI@chgWorkers_Workers1

% Output connections
link: out_port_Workers@Workers1 out_port_Workers

% Internal connections
link: out_port_chgWorkers_Workers@chgWorkers_Workers1 in_plus_port_chgWorkers_Workers@TotWorkers1
link: out_port_TotWorkers@TotWorkers1 in_port_TotWorkers@Workers1

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[Workers1]
% Atomic model DEVSIntegrator
x0: -0
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_WorkersNW]
%Coupled model
components: chgWorkersNW_WorkersNW1@chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW TotWorkersNW1@TotWorkersNWDEVS_BASIC_COUPLED_WorkersNW WorkersNW1@WorkersNWDEVS_BASIC_COUPLED_WorkersNW

% In ports
in: in_port_ConsW in_port_WagesC in_port_WagesI


% Out ports
out: out_port_WorkersNW

% Input connections
link: in_port_ConsW in_port_ConsW@chgWorkersNW_WorkersNW1
link: in_port_WagesC in_port_WagesC@chgWorkersNW_WorkersNW1
link: in_port_WagesI in_port_WagesI@chgWorkersNW_WorkersNW1

% Output connections
link: out_port_WorkersNW@WorkersNW1 out_port_WorkersNW

% Internal connections
link: out_port_chgWorkersNW_WorkersNW@chgWorkersNW_WorkersNW1 in_plus_port_chgWorkersNW_WorkersNW@TotWorkersNW1
link: out_port_TotWorkersNW@TotWorkersNW1 in_port_TotWorkersNW@WorkersNW1

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[WorkersNW1]
% Atomic model DEVSIntegrator
x0: -0
dQMin: 0.001
dQRel: 0.001
























