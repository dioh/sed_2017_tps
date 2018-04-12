
[top]
%Coupled model
components: ConsB@ConsBtop ConsW@ConsWtop ConstantBuy@ConstantBuytop Debt@Debttop IntFee@IntFeetop Interest@Interesttop InvBuy@InvBuytop Lend@Lendtop Money@Moneytop Output@Outputtop PiCG@PiCGtop PiIG@PiIGtop Repay@Repaytop WagesC@WagesCtop WagesI@WagesItop YCValue@YCValuetop YIValue@YIValuetop velocityOfMoney@velocityOfMoneytop  DEVS_BASIC_COUPLED_BankersNW  DEVS_BASIC_COUPLED_ConsNW  DEVS_BASIC_COUPLED_DepCons  DEVS_BASIC_COUPLED_DepInv  DEVS_BASIC_COUPLED_InvNW  DEVS_BASIC_COUPLED_Loans  DEVS_BASIC_COUPLED_Reserves  DEVS_BASIC_COUPLED_Workers  DEVS_BASIC_COUPLED_WorkersNW CPIValue@CPIValuetop IPCValue@IPCValuetop bfValue@bfValuetop rLValue@rLValuetop tauBC@tauBCtop tauL@tauLtop tauMC@tauMCtop tauMI@tauMItop tauR@tauRtop tauWC@tauWCtop wSValue@wSValuetop

% In ports
in: in_port_CPIValue in_port_IPCValue in_port_bfValue in_port_rLValue in_port_tauBC in_port_tauL in_port_tauMC in_port_tauMI in_port_tauR in_port_tauWC in_port_wSValue


% Out ports
out: out_port_BankersNW out_port_ConsB out_port_ConsNW out_port_ConsW out_port_ConstantBuy out_port_Debt out_port_DepCons out_port_DepInv out_port_IntFee out_port_Interest out_port_InvBuy out_port_InvNW out_port_Lend out_port_Loans out_port_Money out_port_Output out_port_PiCG out_port_PiIG out_port_Repay out_port_Reserves out_port_WagesC out_port_WagesI out_port_Workers out_port_WorkersNW out_port_YCValue out_port_YIValue out_port_velocityOfMoney

% Input connections
link: in_port_CPIValue in_port_CPIValue@CPIValue
link: in_port_IPCValue in_port_IPCValue@IPCValue
link: in_port_bfValue in_port_bfValue@bfValue
link: in_port_rLValue in_port_rLValue@rLValue
link: in_port_tauBC in_port_tauBC@tauBC
link: in_port_tauL in_port_tauL@tauL
link: in_port_tauMC in_port_tauMC@tauMC
link: in_port_tauMI in_port_tauMI@tauMI
link: in_port_tauR in_port_tauR@tauR
link: in_port_tauWC in_port_tauWC@tauWC
link: in_port_wSValue in_port_wSValue@wSValue

% Output connections
link: out_port_BankersNW@DEVS_BASIC_COUPLED_BankersNW out_port_BankersNW
link: out_port_ConsB@ConsB out_port_ConsB
link: out_port_ConsNW@DEVS_BASIC_COUPLED_ConsNW out_port_ConsNW
link: out_port_ConsW@ConsW out_port_ConsW
link: out_port_ConstantBuy@ConstantBuy out_port_ConstantBuy
link: out_port_Debt@Debt out_port_Debt
link: out_port_DepCons@DEVS_BASIC_COUPLED_DepCons out_port_DepCons
link: out_port_DepInv@DEVS_BASIC_COUPLED_DepInv out_port_DepInv
link: out_port_IntFee@IntFee out_port_IntFee
link: out_port_Interest@Interest out_port_Interest
link: out_port_InvBuy@InvBuy out_port_InvBuy
link: out_port_InvNW@DEVS_BASIC_COUPLED_InvNW out_port_InvNW
link: out_port_Lend@Lend out_port_Lend
link: out_port_Loans@DEVS_BASIC_COUPLED_Loans out_port_Loans
link: out_port_Money@Money out_port_Money
link: out_port_Output@Output out_port_Output
link: out_port_PiCG@PiCG out_port_PiCG
link: out_port_PiIG@PiIG out_port_PiIG
link: out_port_Repay@Repay out_port_Repay
link: out_port_Reserves@DEVS_BASIC_COUPLED_Reserves out_port_Reserves
link: out_port_WagesC@WagesC out_port_WagesC
link: out_port_WagesI@WagesI out_port_WagesI
link: out_port_Workers@DEVS_BASIC_COUPLED_Workers out_port_Workers
link: out_port_WorkersNW@DEVS_BASIC_COUPLED_WorkersNW out_port_WorkersNW
link: out_port_YCValue@YCValue out_port_YCValue
link: out_port_YIValue@YIValue out_port_YIValue
link: out_port_velocityOfMoney@velocityOfMoney out_port_velocityOfMoney

% Internal connections
link: out_port_BankersNW@DEVS_BASIC_COUPLED_BankersNW in_port_BankersNW@ConsB
link: out_port_tauBC@tauBC in_port_tauBC@ConsB
link: out_port_Workers@DEVS_BASIC_COUPLED_Workers in_port_Workers@ConsW
link: out_port_tauWC@tauWC in_port_tauWC@ConsW
link: out_port_CPIValue@CPIValue in_port_CPIValue@ConstantBuy
link: out_port_PiCG@PiCG in_port_PiCG@ConstantBuy
link: out_port_ConsB@ConsB in_port_ConsB@DEVS_BASIC_COUPLED_BankersNW
link: out_port_IntFee@IntFee in_port_IntFee@DEVS_BASIC_COUPLED_BankersNW
link: out_port_ConsB@ConsB in_port_ConsB@DEVS_BASIC_COUPLED_ConsNW
link: out_port_ConsW@ConsW in_port_ConsW@DEVS_BASIC_COUPLED_ConsNW
link: out_port_ConstantBuy@ConstantBuy in_port_ConstantBuy@DEVS_BASIC_COUPLED_ConsNW
link: out_port_IntFee@IntFee in_port_IntFee@DEVS_BASIC_COUPLED_ConsNW
link: out_port_Interest@Interest in_port_Interest@DEVS_BASIC_COUPLED_ConsNW
link: out_port_InvBuy@InvBuy in_port_InvBuy@DEVS_BASIC_COUPLED_ConsNW
link: out_port_WagesC@WagesC in_port_WagesC@DEVS_BASIC_COUPLED_ConsNW
link: out_port_ConsB@ConsB in_port_ConsB@DEVS_BASIC_COUPLED_DepCons
link: out_port_ConsW@ConsW in_port_ConsW@DEVS_BASIC_COUPLED_DepCons
link: out_port_ConstantBuy@ConstantBuy in_port_ConstantBuy@DEVS_BASIC_COUPLED_DepCons
link: out_port_IntFee@IntFee in_port_IntFee@DEVS_BASIC_COUPLED_DepCons
link: out_port_Interest@Interest in_port_Interest@DEVS_BASIC_COUPLED_DepCons
link: out_port_InvBuy@InvBuy in_port_InvBuy@DEVS_BASIC_COUPLED_DepCons
link: out_port_Lend@Lend in_port_Lend@DEVS_BASIC_COUPLED_DepCons
link: out_port_Repay@Repay in_port_Repay@DEVS_BASIC_COUPLED_DepCons
link: out_port_WagesC@WagesC in_port_WagesC@DEVS_BASIC_COUPLED_DepCons
link: out_port_ConstantBuy@ConstantBuy in_port_ConstantBuy@DEVS_BASIC_COUPLED_DepInv
link: out_port_Interest@Interest in_port_Interest@DEVS_BASIC_COUPLED_DepInv
link: out_port_InvBuy@InvBuy in_port_InvBuy@DEVS_BASIC_COUPLED_DepInv
link: out_port_Lend@Lend in_port_Lend@DEVS_BASIC_COUPLED_DepInv
link: out_port_Repay@Repay in_port_Repay@DEVS_BASIC_COUPLED_DepInv
link: out_port_WagesI@WagesI in_port_WagesI@DEVS_BASIC_COUPLED_DepInv
link: out_port_ConstantBuy@ConstantBuy in_port_ConstantBuy@DEVS_BASIC_COUPLED_InvNW
link: out_port_Interest@Interest in_port_Interest@DEVS_BASIC_COUPLED_InvNW
link: out_port_InvBuy@InvBuy in_port_InvBuy@DEVS_BASIC_COUPLED_InvNW
link: out_port_WagesI@WagesI in_port_WagesI@DEVS_BASIC_COUPLED_InvNW
link: out_port_Lend@Lend in_port_Lend@DEVS_BASIC_COUPLED_Loans
link: out_port_Repay@Repay in_port_Repay@DEVS_BASIC_COUPLED_Loans
link: out_port_ConsW@ConsW in_port_ConsW@DEVS_BASIC_COUPLED_Workers
link: out_port_WagesC@WagesC in_port_WagesC@DEVS_BASIC_COUPLED_Workers
link: out_port_WagesI@WagesI in_port_WagesI@DEVS_BASIC_COUPLED_Workers
link: out_port_ConsW@ConsW in_port_ConsW@DEVS_BASIC_COUPLED_WorkersNW
link: out_port_WagesC@WagesC in_port_WagesC@DEVS_BASIC_COUPLED_WorkersNW
link: out_port_WagesI@WagesI in_port_WagesI@DEVS_BASIC_COUPLED_WorkersNW
link: out_port_Loans@DEVS_BASIC_COUPLED_Loans in_port_Loans@Debt
link: out_port_Interest@Interest in_port_Interest@IntFee
link: out_port_bfValue@bfValue in_port_bfValue@IntFee
link: out_port_Loans@DEVS_BASIC_COUPLED_Loans in_port_Loans@Interest
link: out_port_rLValue@rLValue in_port_rLValue@Interest
link: out_port_IPCValue@IPCValue in_port_IPCValue@InvBuy
link: out_port_PiIG@PiIG in_port_PiIG@InvBuy
link: out_port_DepCons@DEVS_BASIC_COUPLED_DepCons in_port_DepCons@Lend
link: out_port_tauL@tauL in_port_tauL@Lend
link: out_port_BankersNW@DEVS_BASIC_COUPLED_BankersNW in_port_BankersNW@Money
link: out_port_DepCons@DEVS_BASIC_COUPLED_DepCons in_port_DepCons@Money
link: out_port_DepInv@DEVS_BASIC_COUPLED_DepInv in_port_DepInv@Money
link: out_port_Workers@DEVS_BASIC_COUPLED_Workers in_port_Workers@Money
link: out_port_YCValue@YCValue in_port_YCValue@Output
link: out_port_YIValue@YIValue in_port_YIValue@Output
link: out_port_WagesC@WagesC in_port_WagesC@PiCG
link: out_port_YCValue@YCValue in_port_YCValue@PiCG
link: out_port_WagesI@WagesI in_port_WagesI@PiIG
link: out_port_YIValue@YIValue in_port_YIValue@PiIG
link: out_port_Loans@DEVS_BASIC_COUPLED_Loans in_port_Loans@Repay
link: out_port_tauR@tauR in_port_tauR@Repay
link: out_port_YCValue@YCValue in_port_YCValue@WagesC
link: out_port_wSValue@wSValue in_port_wSValue@WagesC
link: out_port_YIValue@YIValue in_port_YIValue@WagesI
link: out_port_wSValue@wSValue in_port_wSValue@WagesI
link: out_port_DepCons@DEVS_BASIC_COUPLED_DepCons in_port_DepCons@YCValue
link: out_port_tauMC@tauMC in_port_tauMC@YCValue
link: out_port_DepInv@DEVS_BASIC_COUPLED_DepInv in_port_DepInv@YIValue
link: out_port_tauMI@tauMI in_port_tauMI@YIValue
link: out_port_Money@Money in_port_Money@velocityOfMoney
link: out_port_Output@Output in_port_Output@velocityOfMoney

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')





































[DEVS_BASIC_COUPLED_BankersNW]
%Coupled model
components: chgBankersNW_BankersNW@chgBankersNW_BankersNWDEVS_BASIC_COUPLED_BankersNW TotBankersNW@TotBankersNWDEVS_BASIC_COUPLED_BankersNW BankersNW@BankersNWDEVS_BASIC_COUPLED_BankersNW

% In ports
in: in_port_ConsB in_port_IntFee


% Out ports
out: out_port_BankersNW

% Input connections
link: in_port_ConsB in_port_ConsB@chgBankersNW_BankersNW
link: in_port_IntFee in_port_IntFee@chgBankersNW_BankersNW

% Output connections
link: out_port_BankersNW@BankersNW out_port_BankersNW

% Internal connections
link: out_port_TotBankersNW@TotBankersNW in_port_TotBankersNW@BankersNW
link: out_port_chgBankersNW_BankersNW@chgBankersNW_BankersNW in_plus_port_chgBankersNW_BankersNW@TotBankersNW

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[BankersNW]
% Atomic model DEVSIntegrator
x0: -0
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_ConsNW]
%Coupled model
components: chgConsNW_ConsNW@chgConsNW_ConsNWDEVS_BASIC_COUPLED_ConsNW TotConsNW@TotConsNWDEVS_BASIC_COUPLED_ConsNW ConsNW@ConsNWDEVS_BASIC_COUPLED_ConsNW

% In ports
in: in_port_ConsB in_port_ConsW in_port_ConstantBuy in_port_IntFee in_port_Interest in_port_InvBuy in_port_WagesC


% Out ports
out: out_port_ConsNW

% Input connections
link: in_port_ConsB in_port_ConsB@chgConsNW_ConsNW
link: in_port_ConsW in_port_ConsW@chgConsNW_ConsNW
link: in_port_ConstantBuy in_port_ConstantBuy@chgConsNW_ConsNW
link: in_port_IntFee in_port_IntFee@chgConsNW_ConsNW
link: in_port_Interest in_port_Interest@chgConsNW_ConsNW
link: in_port_InvBuy in_port_InvBuy@chgConsNW_ConsNW
link: in_port_WagesC in_port_WagesC@chgConsNW_ConsNW

% Output connections
link: out_port_ConsNW@ConsNW out_port_ConsNW

% Internal connections
link: out_port_TotConsNW@TotConsNW in_port_TotConsNW@ConsNW
link: out_port_chgConsNW_ConsNW@chgConsNW_ConsNW in_plus_port_chgConsNW_ConsNW@TotConsNW

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[ConsNW]
% Atomic model DEVSIntegrator
x0: 100
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_DepCons]
%Coupled model
components: chgDepCons_DepCons@chgDepCons_DepConsDEVS_BASIC_COUPLED_DepCons TotDepCons@TotDepConsDEVS_BASIC_COUPLED_DepCons DepCons@DepConsDEVS_BASIC_COUPLED_DepCons

% In ports
in: in_port_ConsB in_port_ConsW in_port_ConstantBuy in_port_IntFee in_port_Interest in_port_InvBuy in_port_Lend in_port_Repay in_port_WagesC


% Out ports
out: out_port_DepCons

% Input connections
link: in_port_ConsB in_port_ConsB@chgDepCons_DepCons
link: in_port_ConsW in_port_ConsW@chgDepCons_DepCons
link: in_port_ConstantBuy in_port_ConstantBuy@chgDepCons_DepCons
link: in_port_IntFee in_port_IntFee@chgDepCons_DepCons
link: in_port_Interest in_port_Interest@chgDepCons_DepCons
link: in_port_InvBuy in_port_InvBuy@chgDepCons_DepCons
link: in_port_Lend in_port_Lend@chgDepCons_DepCons
link: in_port_Repay in_port_Repay@chgDepCons_DepCons
link: in_port_WagesC in_port_WagesC@chgDepCons_DepCons

% Output connections
link: out_port_DepCons@DepCons out_port_DepCons

% Internal connections
link: out_port_TotDepCons@TotDepCons in_port_TotDepCons@DepCons
link: out_port_chgDepCons_DepCons@chgDepCons_DepCons in_plus_port_chgDepCons_DepCons@TotDepCons

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[DepCons]
% Atomic model DEVSIntegrator
x0: 100
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_DepInv]
%Coupled model
components: chgDepInv_DepInv@chgDepInv_DepInvDEVS_BASIC_COUPLED_DepInv TotDepInv@TotDepInvDEVS_BASIC_COUPLED_DepInv DepInv@DepInvDEVS_BASIC_COUPLED_DepInv

% In ports
in: in_port_ConstantBuy in_port_Interest in_port_InvBuy in_port_Lend in_port_Repay in_port_WagesI


% Out ports
out: out_port_DepInv

% Input connections
link: in_port_ConstantBuy in_port_ConstantBuy@chgDepInv_DepInv
link: in_port_Interest in_port_Interest@chgDepInv_DepInv
link: in_port_InvBuy in_port_InvBuy@chgDepInv_DepInv
link: in_port_Lend in_port_Lend@chgDepInv_DepInv
link: in_port_Repay in_port_Repay@chgDepInv_DepInv
link: in_port_WagesI in_port_WagesI@chgDepInv_DepInv

% Output connections
link: out_port_DepInv@DepInv out_port_DepInv

% Internal connections
link: out_port_TotDepInv@TotDepInv in_port_TotDepInv@DepInv
link: out_port_chgDepInv_DepInv@chgDepInv_DepInv in_plus_port_chgDepInv_DepInv@TotDepInv

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[DepInv]
% Atomic model DEVSIntegrator
x0: -0
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_InvNW]
%Coupled model
components: chgInvNW_InvNW@chgInvNW_InvNWDEVS_BASIC_COUPLED_InvNW TotInvNW@TotInvNWDEVS_BASIC_COUPLED_InvNW InvNW@InvNWDEVS_BASIC_COUPLED_InvNW

% In ports
in: in_port_ConstantBuy in_port_Interest in_port_InvBuy in_port_WagesI


% Out ports
out: out_port_InvNW

% Input connections
link: in_port_ConstantBuy in_port_ConstantBuy@chgInvNW_InvNW
link: in_port_Interest in_port_Interest@chgInvNW_InvNW
link: in_port_InvBuy in_port_InvBuy@chgInvNW_InvNW
link: in_port_WagesI in_port_WagesI@chgInvNW_InvNW

% Output connections
link: out_port_InvNW@InvNW out_port_InvNW

% Internal connections
link: out_port_TotInvNW@TotInvNW in_port_TotInvNW@InvNW
link: out_port_chgInvNW_InvNW@chgInvNW_InvNW in_plus_port_chgInvNW_InvNW@TotInvNW

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[InvNW]
% Atomic model DEVSIntegrator
x0: 0
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_Loans]
%Coupled model
components: chgLoans_Loans@chgLoans_LoansDEVS_BASIC_COUPLED_Loans TotLoans@TotLoansDEVS_BASIC_COUPLED_Loans Loans@LoansDEVS_BASIC_COUPLED_Loans

% In ports
in: in_port_Lend in_port_Repay


% Out ports
out: out_port_Loans

% Input connections
link: in_port_Lend in_port_Lend@chgLoans_Loans
link: in_port_Repay in_port_Repay@chgLoans_Loans

% Output connections
link: out_port_Loans@Loans out_port_Loans

% Internal connections
link: out_port_TotLoans@TotLoans in_port_TotLoans@Loans
link: out_port_chgLoans_Loans@chgLoans_Loans in_plus_port_chgLoans_Loans@TotLoans

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[Loans]
% Atomic model DEVSIntegrator
x0: 0
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_Reserves]
%Coupled model
components: chgReserves_Reserves@chgReserves_ReservesDEVS_BASIC_COUPLED_Reserves TotReserves@TotReservesDEVS_BASIC_COUPLED_Reserves Reserves@ReservesDEVS_BASIC_COUPLED_Reserves

% In ports


% Out ports
out: out_port_Reserves

% Input connections

% Output connections
link: out_port_Reserves@Reserves out_port_Reserves

% Internal connections
link: out_port_TotReserves@TotReserves in_port_TotReserves@Reserves
link: out_port_chgReserves_Reserves@chgReserves_Reserves in_plus_port_chgReserves_Reserves@TotReserves

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[Reserves]
% Atomic model DEVSIntegrator
x0: 100
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_Workers]
%Coupled model
components: chgWorkers_Workers@chgWorkers_WorkersDEVS_BASIC_COUPLED_Workers TotWorkers@TotWorkersDEVS_BASIC_COUPLED_Workers Workers@WorkersDEVS_BASIC_COUPLED_Workers

% In ports
in: in_port_ConsW in_port_WagesC in_port_WagesI


% Out ports
out: out_port_Workers

% Input connections
link: in_port_ConsW in_port_ConsW@chgWorkers_Workers
link: in_port_WagesC in_port_WagesC@chgWorkers_Workers
link: in_port_WagesI in_port_WagesI@chgWorkers_Workers

% Output connections
link: out_port_Workers@Workers out_port_Workers

% Internal connections
link: out_port_chgWorkers_Workers@chgWorkers_Workers in_plus_port_chgWorkers_Workers@TotWorkers
link: out_port_TotWorkers@TotWorkers in_port_TotWorkers@Workers

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[Workers]
% Atomic model DEVSIntegrator
x0: -0
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_WorkersNW]
%Coupled model
components: chgWorkersNW_WorkersNW@chgWorkersNW_WorkersNWDEVS_BASIC_COUPLED_WorkersNW TotWorkersNW@TotWorkersNWDEVS_BASIC_COUPLED_WorkersNW WorkersNW@WorkersNWDEVS_BASIC_COUPLED_WorkersNW

% In ports
in: in_port_ConsW in_port_WagesC in_port_WagesI


% Out ports
out: out_port_WorkersNW

% Input connections
link: in_port_ConsW in_port_ConsW@chgWorkersNW_WorkersNW
link: in_port_WagesC in_port_WagesC@chgWorkersNW_WorkersNW
link: in_port_WagesI in_port_WagesI@chgWorkersNW_WorkersNW

% Output connections
link: out_port_WorkersNW@WorkersNW out_port_WorkersNW

% Internal connections
link: out_port_chgWorkersNW_WorkersNW@chgWorkersNW_WorkersNW in_plus_port_chgWorkersNW_WorkersNW@TotWorkersNW
link: out_port_TotWorkersNW@TotWorkersNW in_port_TotWorkersNW@WorkersNW

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[WorkersNW]
% Atomic model DEVSIntegrator
x0: -0
dQMin: 0.001
dQRel: 0.001
























