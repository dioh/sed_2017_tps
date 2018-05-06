
[top]
%Coupled model
components:  DEVS_BASIC_COUPLED_Predator  DEVS_BASIC_COUPLED_Prey paramA0@paramAtop paramB0@paramBtop paramC0@paramCtop paramD0@paramDtop

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
link: out_port_Predator@DEVS_BASIC_COUPLED_Predator out_port_Predator
link: out_port_Prey@DEVS_BASIC_COUPLED_Prey out_port_Prey

% Internal connections
link: out_port_Prey@DEVS_BASIC_COUPLED_Prey in_port_Prey@DEVS_BASIC_COUPLED_Predator
link: out_port_paramC@paramC0 in_port_paramC@DEVS_BASIC_COUPLED_Predator
link: out_port_paramD@paramD0 in_port_paramD@DEVS_BASIC_COUPLED_Predator
link: out_port_Predator@DEVS_BASIC_COUPLED_Predator in_port_Predator@DEVS_BASIC_COUPLED_Prey
link: out_port_paramA@paramA0 in_port_paramA@DEVS_BASIC_COUPLED_Prey
link: out_port_paramB@paramB0 in_port_paramB@DEVS_BASIC_COUPLED_Prey

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')

[DEVS_BASIC_COUPLED_Predator]
%Coupled model
components: MinusPredator_Predator1@MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator PlusPredator_Predator1@PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator TotPredator1@TotPredatorDEVS_BASIC_COUPLED_Predator Predator1@PredatorDEVS_BASIC_COUPLED_Predator

% In ports
in: in_port_Prey in_port_paramC in_port_paramD


% Out ports
out: out_port_Predator

% Input connections
link: in_port_paramC in_port_paramC@MinusPredator_Predator1
link: in_port_Prey in_port_Prey@PlusPredator_Predator1
link: in_port_paramD in_port_paramD@PlusPredator_Predator1

% Output connections
link: out_port_Predator@Predator1 out_port_Predator

% Internal connections
link: out_port_Predator@Predator1 in_port_Predator@MinusPredator_Predator1
link: out_port_Predator@Predator1 in_port_Predator@PlusPredator_Predator1
link: out_port_TotPredator@TotPredator1 in_port_TotPredator@Predator1
link: out_port_MinusPredator_Predator@MinusPredator_Predator1 in_minus_port_MinusPredator_Predator@TotPredator1
link: out_port_PlusPredator_Predator@PlusPredator_Predator1 in_plus_port_PlusPredator_Predator@TotPredator1

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')








[Predator1]
% Atomic model DEVSIntegrator
x0: 5
non_negative: 0
dQMin: 0.001
dQRel: 0.001



[DEVS_BASIC_COUPLED_Prey]
%Coupled model
components: MinusPrey_Prey1@MinusPrey_PreyDEVS_BASIC_COUPLED_Prey PlusPrey_Prey1@PlusPrey_PreyDEVS_BASIC_COUPLED_Prey TotPrey1@TotPreyDEVS_BASIC_COUPLED_Prey Prey1@PreyDEVS_BASIC_COUPLED_Prey

% In ports
in: in_port_Predator in_port_paramA in_port_paramB


% Out ports
out: out_port_Prey

% Input connections
link: in_port_Predator in_port_Predator@MinusPrey_Prey1
link: in_port_paramB in_port_paramB@MinusPrey_Prey1
link: in_port_paramA in_port_paramA@PlusPrey_Prey1

% Output connections
link: out_port_Prey@Prey1 out_port_Prey

% Internal connections
link: out_port_Prey@Prey1 in_port_Prey@MinusPrey_Prey1
link: out_port_Prey@Prey1 in_port_Prey@PlusPrey_Prey1
link: out_port_TotPrey@TotPrey1 in_port_TotPrey@Prey1
link: out_port_MinusPrey_Prey@MinusPrey_Prey1 in_minus_port_MinusPrey_Prey@TotPrey1
link: out_port_PlusPrey_Prey@PlusPrey_Prey1 in_plus_port_PlusPrey_Prey@TotPrey1

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')








[Prey1]
% Atomic model DEVSIntegrator
x0: 100
non_negative: 0
dQMin: 0.001
dQRel: 0.001










