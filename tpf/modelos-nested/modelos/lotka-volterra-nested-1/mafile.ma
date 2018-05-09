#include(macros.inc)
[top]
%Coupled model
components: paramA0@paramAtop paramB0@paramBtop paramC0@paramCtop paramD0@paramDtop  DEVS_COUPLED_PredatorModel  DEVS_COUPLED_PreyModel
% In ports
in: in_port_paramA in_port_paramB in_port_paramC in_port_paramD
% Out ports
out: out_port_Predator out_port_Prey
% Input connections
link: in_port_paramA in_port_paramA@paramA0
link: in_port_paramB in_port_paramB@paramB0
link: in_port_paramC in_port_paramC@paramC0
link: in_port_paramD in_port_paramD@paramD0
% Output connections
link: out_port_Predator@DEVS_COUPLED_PredatorModel out_port_Predator
link: out_port_Prey@DEVS_COUPLED_PreyModel out_port_Prey
% Internal connections
link: out_port_Prey@DEVS_COUPLED_PreyModel in_port_Prey@DEVS_COUPLED_PredatorModel
link: out_port_paramC@paramC0 in_port_paramC@DEVS_COUPLED_PredatorModel
link: out_port_paramD@paramD0 in_port_paramD@DEVS_COUPLED_PredatorModel
link: out_port_Predator@DEVS_COUPLED_PredatorModel in_port_Predator@DEVS_COUPLED_PreyModel
link: out_port_paramA@paramA0 in_port_paramA@DEVS_COUPLED_PreyModel
link: out_port_paramB@paramB0 in_port_paramB@DEVS_COUPLED_PreyModel[DEVS_COUPLED_PredatorModel]
%Coupled model
components:  DEVS_BASIC_COUPLED_Predator paramC1@paramCPredatorModel paramD1@paramDPredatorModel
% In ports
in: in_port_Prey in_port_paramC in_port_paramD
% Out ports
out: out_port_Predator
% Input connections
link: in_port_Prey in_port_Prey@DEVS_BASIC_COUPLED_Predator
link: in_port_paramC in_port_paramC@paramC1
link: in_port_paramD in_port_paramD@paramD1
% Output connections
link: out_port_Predator@DEVS_BASIC_COUPLED_Predator out_port_Predator
% Internal connections
link: out_port_paramC@paramC1 in_port_paramC@DEVS_BASIC_COUPLED_Predator
link: out_port_paramD@paramD1 in_port_paramD@DEVS_BASIC_COUPLED_Predator[DEVS_BASIC_COUPLED_Predator]
%Coupled model
components: MinusPredator_Predator2@MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator PlusPredator_Predator2@PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator TotPredator2@TotPredatorDEVS_BASIC_COUPLED_Predator Predator2@PredatorDEVS_BASIC_COUPLED_Predator
% In ports
in: in_port_Prey in_port_paramC in_port_paramD
% Out ports
out: out_port_Predator
% Input connections
link: in_port_paramC in_port_paramC@MinusPredator_Predator2
link: in_port_Prey in_port_Prey@PlusPredator_Predator2
link: in_port_paramD in_port_paramD@PlusPredator_Predator2
% Output connections
link: out_port_Predator@Predator2 out_port_Predator
% Internal connections
link: out_port_Predator@Predator2 in_port_Predator@MinusPredator_Predator2
link: out_port_Predator@Predator2 in_port_Predator@PlusPredator_Predator2
link: out_port_TotPredator@TotPredator2 in_port_TotPredator@Predator2
link: out_port_MinusPredator_Predator@MinusPredator_Predator2 in_minus_port_MinusPredator_Predator@TotPredator2
link: out_port_PlusPredator_Predator@PlusPredator_Predator2 in_plus_port_PlusPredator_Predator@TotPredator2
[Predator2]
% Atomic model DEVSIntegrator
x0: 5
non_negative: 0
dQMin: 0.001
dQRel: 0.001
[DEVS_COUPLED_PreyModel]
%Coupled model
components:  DEVS_BASIC_COUPLED_Prey paramA1@paramAPreyModel paramB1@paramBPreyModel
% In ports
in: in_port_Predator in_port_paramA in_port_paramB
% Out ports
out: out_port_Prey
% Input connections
link: in_port_Predator in_port_Predator@DEVS_BASIC_COUPLED_Prey
link: in_port_paramA in_port_paramA@paramA1
link: in_port_paramB in_port_paramB@paramB1
% Output connections
link: out_port_Prey@DEVS_BASIC_COUPLED_Prey out_port_Prey
% Internal connections
link: out_port_paramA@paramA1 in_port_paramA@DEVS_BASIC_COUPLED_Prey
link: out_port_paramB@paramB1 in_port_paramB@DEVS_BASIC_COUPLED_Prey[DEVS_BASIC_COUPLED_Prey]
%Coupled model
components: MinusPrey_Prey2@MinusPrey_PreyDEVS_BASIC_COUPLED_Prey PlusPrey_Prey2@PlusPrey_PreyDEVS_BASIC_COUPLED_Prey TotPrey2@TotPreyDEVS_BASIC_COUPLED_Prey Prey2@PreyDEVS_BASIC_COUPLED_Prey
% In ports
in: in_port_Predator in_port_paramA in_port_paramB
% Out ports
out: out_port_Prey
% Input connections
link: in_port_Predator in_port_Predator@MinusPrey_Prey2
link: in_port_paramB in_port_paramB@MinusPrey_Prey2
link: in_port_paramA in_port_paramA@PlusPrey_Prey2
% Output connections
link: out_port_Prey@Prey2 out_port_Prey
% Internal connections
link: out_port_Prey@Prey2 in_port_Prey@MinusPrey_Prey2
link: out_port_Prey@Prey2 in_port_Prey@PlusPrey_Prey2
link: out_port_TotPrey@TotPrey2 in_port_TotPrey@Prey2
link: out_port_MinusPrey_Prey@MinusPrey_Prey2 in_minus_port_MinusPrey_Prey@TotPrey2
link: out_port_PlusPrey_Prey@PlusPrey_Prey2 in_plus_port_PlusPrey_Prey@TotPrey2
[Prey2]
% Atomic model DEVSIntegrator
x0: 100
non_negative: 0
dQMin: 0.001
dQRel: 0.001
