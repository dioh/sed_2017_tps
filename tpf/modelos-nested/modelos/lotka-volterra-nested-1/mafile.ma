[top]
%Coupled model
components: paramA@paramAtop paramB@paramBtop paramC@paramCtop paramD@paramDtop  DEVS_COUPLED_PredatorModel  DEVS_COUPLED_PreyModel
% In ports
in: in_port_paramA in_port_paramB in_port_paramC in_port_paramD
% Out ports
out: out_port_Predator out_port_Prey
% Input connections
link: in_port_paramA in_port_paramA@paramA
link: in_port_paramB in_port_paramB@paramB
link: in_port_paramC in_port_paramC@paramC
link: in_port_paramD in_port_paramD@paramD
% Output connections
link: out_port_Predator@DEVS_COUPLED_PredatorModel out_port_Predator
link: out_port_Prey@DEVS_COUPLED_PreyModel out_port_Prey
% Internal connections
link: out_port_Prey@DEVS_COUPLED_PreyModel in_port_Prey@DEVS_COUPLED_PredatorModel
link: out_port_paramC@paramC in_port_paramC@DEVS_COUPLED_PredatorModel
link: out_port_paramD@paramD in_port_paramD@DEVS_COUPLED_PredatorModel
link: out_port_Predator@DEVS_COUPLED_PredatorModel in_port_Predator@DEVS_COUPLED_PreyModel
link: out_port_paramA@paramA in_port_paramA@DEVS_COUPLED_PreyModel
link: out_port_paramB@paramB in_port_paramB@DEVS_COUPLED_PreyModel

[DEVS_COUPLED_PredatorModel]
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
link: out_port_paramD@paramD1 in_port_paramD@DEVS_BASIC_COUPLED_Predator
% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')
[DEVS_BASIC_COUPLED_Predator]
%Coupled model
components: MinusPredator_Predator@MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator PlusPredator_Predator@PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator TotPredator@TotPredatorDEVS_BASIC_COUPLED_Predator Predator@PredatorDEVS_BASIC_COUPLED_Predator
% In ports
in: in_port_Prey in_port_paramC in_port_paramD
% Out ports
out: out_port_Predator
% Input connections
link: in_port_paramC in_port_paramC@MinusPredator_Predator
link: in_port_Prey in_port_Prey@PlusPredator_Predator
link: in_port_paramD in_port_paramD@PlusPredator_Predator
% Output connections
link: out_port_Predator@Predator out_port_Predator
% Internal connections
link: out_port_Predator@Predator in_port_Predator@MinusPredator_Predator
link: out_port_Predator@Predator in_port_Predator@PlusPredator_Predator
link: out_port_TotPredator@TotPredator in_port_TotPredator@Predator
link: out_port_MinusPredator_Predator@MinusPredator_Predator in_minus_port_MinusPredator_Predator@TotPredator
link: out_port_PlusPredator_Predator@PlusPredator_Predator in_plus_port_PlusPredator_Predator@TotPredator
[Predator]
% Atomic model DEVSIntegrator
x0: 5
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
link: out_port_paramB@paramB1 in_port_paramB@DEVS_BASIC_COUPLED_Prey
% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')
[DEVS_BASIC_COUPLED_Prey]
%Coupled model
components: MinusPrey_Prey@MinusPrey_PreyDEVS_BASIC_COUPLED_Prey PlusPrey_Prey@PlusPrey_PreyDEVS_BASIC_COUPLED_Prey TotPrey@TotPreyDEVS_BASIC_COUPLED_Prey Prey@PreyDEVS_BASIC_COUPLED_Prey
% In ports
in: in_port_Predator in_port_paramA in_port_paramB
% Out ports
out: out_port_Prey
% Input connections
link: in_port_Predator in_port_Predator@MinusPrey_Prey
link: in_port_paramB in_port_paramB@MinusPrey_Prey
link: in_port_paramA in_port_paramA@PlusPrey_Prey
% Output connections
link: out_port_Prey@Prey out_port_Prey
% Internal connections
link: out_port_Prey@Prey in_port_Prey@MinusPrey_Prey
link: out_port_Prey@Prey in_port_Prey@PlusPrey_Prey
link: out_port_TotPrey@TotPrey in_port_TotPrey@Prey
link: out_port_MinusPrey_Prey@MinusPrey_Prey in_minus_port_MinusPrey_Prey@TotPrey
link: out_port_PlusPrey_Prey@PlusPrey_Prey in_plus_port_PlusPrey_Prey@TotPrey
[Prey]
% Atomic model DEVSIntegrator
x0: 100
dQMin: 0.001
dQRel: 0.001
