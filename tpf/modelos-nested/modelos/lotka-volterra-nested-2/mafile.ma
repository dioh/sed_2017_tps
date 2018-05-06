
[top]
%Coupled model
components: paramE0@paramEtop specialParamC0@specialParamCtop  DEVS_BASIC_COUPLED_hunter paramA0@paramAtop paramB0@paramBtop paramD0@paramDtop paramPulse0@paramPulsetop  DEVS_COUPLED_PredatorModel  DEVS_COUPLED_PreyModel PULSE_V_1_FP_1_I_1_paramE0@PULSE_V_1_FP_1_I_1_paramEDEVS_COUPLED_top PULSE_V_2_FP_2_I_2_specialParamC0@PULSE_V_2_FP_2_I_2_specialParamCDEVS_COUPLED_top

% In ports
in: in_port_ctePulse in_port_cteVariable in_port_paramA in_port_paramB in_port_paramD in_port_paramPulse in_port_start


% Out ports
out: out_port_Predator out_port_Prey out_port_PreySubModelStock out_port_PreySubSubModelStock out_port_auxVariable out_port_combiner out_port_hunter out_port_paramE out_port_specialParamC

% Input connections
link: in_port_start in_port_start@DEVS_BASIC_COUPLED_hunter
link: in_port_cteVariable in_port_cteVariable@DEVS_COUPLED_PredatorModel
link: in_port_ctePulse in_port_ctePulse@DEVS_COUPLED_PreyModel
link: in_port_start in_port_start@DEVS_COUPLED_PreyModel
link: in_port_start in_port_start@PULSE_V_1_FP_1_I_1_paramE0
link: in_port_start in_port_start@PULSE_V_2_FP_2_I_2_specialParamC0
link: in_port_paramA in_port_paramA@paramA0
link: in_port_paramB in_port_paramB@paramB0
link: in_port_paramD in_port_paramD@paramD0
link: in_port_paramPulse in_port_paramPulse@paramPulse0

% Output connections
link: out_port_Predator@DEVS_COUPLED_PredatorModel out_port_Predator
link: out_port_Prey@DEVS_COUPLED_PreyModel out_port_Prey
link: out_port_PreySubModelStock@DEVS_COUPLED_PreyModel out_port_PreySubModelStock
link: out_port_PreySubSubModelStock@DEVS_COUPLED_PreyModel out_port_PreySubSubModelStock
link: out_port_auxVariable@DEVS_COUPLED_PredatorModel out_port_auxVariable
link: out_port_combiner@DEVS_COUPLED_PreyModel out_port_combiner
link: out_port_hunter@DEVS_BASIC_COUPLED_hunter out_port_hunter
link: out_port_paramE@paramE0 out_port_paramE
link: out_port_specialParamC@specialParamC0 out_port_specialParamC

% Internal connections
link: out_port_paramPulse@paramPulse0 in_port_paramPulse@DEVS_BASIC_COUPLED_hunter
link: out_port_Prey@DEVS_COUPLED_PreyModel in_port_Prey@DEVS_COUPLED_PredatorModel
link: out_port_hunter@DEVS_BASIC_COUPLED_hunter in_port_hunter@DEVS_COUPLED_PredatorModel
link: out_port_paramD@paramD0 in_port_paramD@DEVS_COUPLED_PredatorModel
link: out_port_specialParamC@specialParamC0 in_port_specialParamC@DEVS_COUPLED_PredatorModel
link: out_port_Predator@DEVS_COUPLED_PredatorModel in_port_Predator@DEVS_COUPLED_PreyModel
link: out_port_paramA@paramA0 in_port_paramA@DEVS_COUPLED_PreyModel
link: out_port_paramB@paramB0 in_port_paramB@DEVS_COUPLED_PreyModel
link: out_port_PULSE_V_1_FP_1_I_1_paramE@PULSE_V_1_FP_1_I_1_paramE0 in_port_PULSE_V_1_FP_1_I_1_paramE@paramE0
link: out_port_paramA@paramA0 in_port_paramA@paramE0
link: out_port_paramB@paramB0 in_port_paramB@paramE0
link: out_port_PULSE_V_2_FP_2_I_2_specialParamC@PULSE_V_2_FP_2_I_2_specialParamC0 in_port_PULSE_V_2_FP_2_I_2_specialParamC@specialParamC0

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')





[DEVS_BASIC_COUPLED_hunter]
%Coupled model
components: populationDeath_hunter1@populationDeath_hunterDEVS_BASIC_COUPLED_hunter populationGrowth_hunter1@populationGrowth_hunterDEVS_BASIC_COUPLED_hunter Tothunter1@TothunterDEVS_BASIC_COUPLED_hunter hunter1@hunterDEVS_BASIC_COUPLED_hunter PULSE_V_paramPulse_FP_1_I_1_populationGrowth1@PULSE_V_paramPulse_FP_1_I_1_populationGrowthDEVS_BASIC_COUPLED_hunter

% In ports
in: in_port_paramPulse in_port_start


% Out ports
out: out_port_hunter

% Input connections
link: in_port_paramPulse in_port_paramPulse@PULSE_V_paramPulse_FP_1_I_1_populationGrowth1
link: in_port_start in_port_start@PULSE_V_paramPulse_FP_1_I_1_populationGrowth1

% Output connections
link: out_port_hunter@hunter1 out_port_hunter

% Internal connections
link: out_port_populationDeath_hunter@populationDeath_hunter1 in_minus_port_populationDeath_hunter@Tothunter1
link: out_port_populationGrowth_hunter@populationGrowth_hunter1 in_plus_port_populationGrowth_hunter@Tothunter1
link: out_port_Tothunter@Tothunter1 in_port_Tothunter@hunter1
link: out_port_PULSE_V_paramPulse_FP_1_I_1_populationGrowth@PULSE_V_paramPulse_FP_1_I_1_populationGrowth1 in_port_increment@hunter1
link: out_port_hunter@hunter1 in_port_hunter@populationDeath_hunter1
link: out_port_hunter@hunter1 in_port_hunter@populationGrowth_hunter1

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')








[hunter1]
% Atomic model DEVSIntegrator
x0: 5
non_negative: 0
dQMin: 0.001
dQRel: 0.001













[DEVS_COUPLED_PredatorModel]
%Coupled model
components: auxVariable1@auxVariablePredatorModel  DEVS_BASIC_COUPLED_Predator cteVariable1@cteVariablePredatorModel paramD1@paramDPredatorModel specialParamC1@specialParamCPredatorModel

% In ports
in: in_port_Prey in_port_cteVariable in_port_hunter in_port_paramD in_port_specialParamC


% Out ports
out: out_port_Predator out_port_auxVariable

% Input connections
link: in_port_Prey in_port_Prey@DEVS_BASIC_COUPLED_Predator
link: in_port_hunter in_port_hunter@DEVS_BASIC_COUPLED_Predator
link: in_port_cteVariable in_port_cteVariable@cteVariable1
link: in_port_paramD in_port_paramD@paramD1
link: in_port_specialParamC in_port_specialParamC@specialParamC1

% Output connections
link: out_port_Predator@DEVS_BASIC_COUPLED_Predator out_port_Predator
link: out_port_auxVariable@auxVariable1 out_port_auxVariable

% Internal connections
link: out_port_cteVariable@cteVariable1 in_port_cteVariable@DEVS_BASIC_COUPLED_Predator
link: out_port_paramD@paramD1 in_port_paramD@DEVS_BASIC_COUPLED_Predator
link: out_port_specialParamC@specialParamC1 in_port_specialParamC@DEVS_BASIC_COUPLED_Predator
link: out_port_cteVariable@cteVariable1 in_port_cteVariable@auxVariable1

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')



[DEVS_BASIC_COUPLED_Predator]
%Coupled model
components: MinusPredator_Predator2@MinusPredator_PredatorDEVS_BASIC_COUPLED_Predator PlusPredator_Predator2@PlusPredator_PredatorDEVS_BASIC_COUPLED_Predator TotPredator2@TotPredatorDEVS_BASIC_COUPLED_Predator Predator2@PredatorDEVS_BASIC_COUPLED_Predator

% In ports
in: in_port_Prey in_port_cteVariable in_port_hunter in_port_paramD in_port_specialParamC


% Out ports
out: out_port_Predator

% Input connections
link: in_port_hunter in_port_hunter@MinusPredator_Predator2
link: in_port_specialParamC in_port_specialParamC@MinusPredator_Predator2
link: in_port_Prey in_port_Prey@PlusPredator_Predator2
link: in_port_cteVariable in_port_cteVariable@PlusPredator_Predator2
link: in_port_paramD in_port_paramD@PlusPredator_Predator2

% Output connections
link: out_port_Predator@Predator2 out_port_Predator

% Internal connections
link: out_port_Predator@Predator2 in_port_Predator@MinusPredator_Predator2
link: out_port_Predator@Predator2 in_port_Predator@PlusPredator_Predator2
link: out_port_TotPredator@TotPredator2 in_port_TotPredator@Predator2
link: out_port_MinusPredator_Predator@MinusPredator_Predator2 in_minus_port_MinusPredator_Predator@TotPredator2
link: out_port_PlusPredator_Predator@PlusPredator_Predator2 in_plus_port_PlusPredator_Predator@TotPredator2

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')








[Predator2]
% Atomic model DEVSIntegrator
x0: 5
non_negative: 0
dQMin: 0.001
dQRel: 0.001









[DEVS_COUPLED_PreyModel]
%Coupled model
components:  DEVS_BASIC_COUPLED_Prey paramA1@paramAPreyModel paramB1@paramBPreyModel  DEVS_COUPLED_PreySubModel

% In ports
in: in_port_Predator in_port_ctePulse in_port_paramA in_port_paramB in_port_start


% Out ports
out: out_port_Prey out_port_PreySubModelStock out_port_PreySubSubModelStock out_port_combiner

% Input connections
link: in_port_Predator in_port_Predator@DEVS_BASIC_COUPLED_Prey
link: in_port_ctePulse in_port_ctePulse@DEVS_COUPLED_PreySubModel
link: in_port_start in_port_start@DEVS_COUPLED_PreySubModel
link: in_port_paramA in_port_paramA@paramA1
link: in_port_paramB in_port_paramB@paramB1

% Output connections
link: out_port_Prey@DEVS_BASIC_COUPLED_Prey out_port_Prey
link: out_port_PreySubModelStock@DEVS_COUPLED_PreySubModel out_port_PreySubModelStock
link: out_port_PreySubSubModelStock@DEVS_COUPLED_PreySubModel out_port_PreySubSubModelStock
link: out_port_combiner@DEVS_COUPLED_PreySubModel out_port_combiner

% Internal connections
link: out_port_PreySubModelStock@DEVS_COUPLED_PreySubModel in_port_PreySubModelStock@DEVS_BASIC_COUPLED_Prey
link: out_port_PreySubSubModelStock@DEVS_COUPLED_PreySubModel in_port_PreySubSubModelStock@DEVS_BASIC_COUPLED_Prey
link: out_port_paramA@paramA1 in_port_paramA@DEVS_BASIC_COUPLED_Prey
link: out_port_paramB@paramB1 in_port_paramB@DEVS_BASIC_COUPLED_Prey
link: out_port_Prey@DEVS_BASIC_COUPLED_Prey in_port_Prey@DEVS_COUPLED_PreySubModel

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')

[DEVS_BASIC_COUPLED_Prey]
%Coupled model
components: MinusPrey_Prey2@MinusPrey_PreyDEVS_BASIC_COUPLED_Prey PlusPrey_Prey2@PlusPrey_PreyDEVS_BASIC_COUPLED_Prey TotPrey2@TotPreyDEVS_BASIC_COUPLED_Prey Prey2@PreyDEVS_BASIC_COUPLED_Prey

% In ports
in: in_port_Predator in_port_PreySubModelStock in_port_PreySubSubModelStock in_port_paramA in_port_paramB


% Out ports
out: out_port_Prey

% Input connections
link: in_port_Predator in_port_Predator@MinusPrey_Prey2
link: in_port_PreySubSubModelStock in_port_PreySubSubModelStock@MinusPrey_Prey2
link: in_port_paramB in_port_paramB@MinusPrey_Prey2
link: in_port_PreySubModelStock in_port_PreySubModelStock@PlusPrey_Prey2
link: in_port_paramA in_port_paramA@PlusPrey_Prey2

% Output connections
link: out_port_Prey@Prey2 out_port_Prey

% Internal connections
link: out_port_Prey@Prey2 in_port_Prey@MinusPrey_Prey2
link: out_port_Prey@Prey2 in_port_Prey@PlusPrey_Prey2
link: out_port_TotPrey@TotPrey2 in_port_TotPrey@Prey2
link: out_port_MinusPrey_Prey@MinusPrey_Prey2 in_minus_port_MinusPrey_Prey@TotPrey2
link: out_port_PlusPrey_Prey@PlusPrey_Prey2 in_plus_port_PlusPrey_Prey@TotPrey2

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')








[Prey2]
% Atomic model DEVSIntegrator
x0: 100
non_negative: 0
dQMin: 0.001
dQRel: 0.001







[DEVS_COUPLED_PreySubModel]
%Coupled model
components:  DEVS_BASIC_COUPLED_PreySubModelStock  DEVS_COUPLED_PreySubSubModel

% In ports
in: in_port_Prey in_port_ctePulse in_port_start


% Out ports
out: out_port_PreySubModelStock out_port_PreySubSubModelStock out_port_combiner

% Input connections
link: in_port_Prey in_port_Prey@DEVS_BASIC_COUPLED_PreySubModelStock
link: in_port_Prey in_port_Prey@DEVS_COUPLED_PreySubSubModel
link: in_port_ctePulse in_port_ctePulse@DEVS_COUPLED_PreySubSubModel
link: in_port_start in_port_start@DEVS_COUPLED_PreySubSubModel

% Output connections
link: out_port_PreySubModelStock@DEVS_BASIC_COUPLED_PreySubModelStock out_port_PreySubModelStock
link: out_port_PreySubSubModelStock@DEVS_COUPLED_PreySubSubModel out_port_PreySubSubModelStock
link: out_port_combiner@DEVS_COUPLED_PreySubSubModel out_port_combiner

% Internal connections
link: out_port_PreySubSubModelStock@DEVS_COUPLED_PreySubSubModel in_port_PreySubSubModelStock@DEVS_BASIC_COUPLED_PreySubModelStock

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')

[DEVS_BASIC_COUPLED_PreySubModelStock]
%Coupled model
components: preySubFlow_PreySubModelStock3@preySubFlow_PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock TotPreySubModelStock3@TotPreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock PreySubModelStock3@PreySubModelStockDEVS_BASIC_COUPLED_PreySubModelStock

% In ports
in: in_port_Prey in_port_PreySubSubModelStock


% Out ports
out: out_port_PreySubModelStock

% Input connections
link: in_port_Prey in_port_Prey@preySubFlow_PreySubModelStock3
link: in_port_PreySubSubModelStock in_port_PreySubSubModelStock@preySubFlow_PreySubModelStock3

% Output connections
link: out_port_PreySubModelStock@PreySubModelStock3 out_port_PreySubModelStock

% Internal connections
link: out_port_TotPreySubModelStock@TotPreySubModelStock3 in_port_TotPreySubModelStock@PreySubModelStock3
link: out_port_preySubFlow_PreySubModelStock@preySubFlow_PreySubModelStock3 in_minus_port_preySubFlow_PreySubModelStock@TotPreySubModelStock3
link: out_port_PreySubModelStock@PreySubModelStock3 in_port_PreySubModelStock@preySubFlow_PreySubModelStock3

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[PreySubModelStock3]
% Atomic model DEVSIntegrator
x0: 0
non_negative: 0
dQMin: 0.001
dQRel: 0.001



[DEVS_COUPLED_PreySubSubModel]
%Coupled model
components: combiner3@combinerPreySubSubModel  DEVS_BASIC_COUPLED_PreySubSubModelStock ctePulse3@ctePulsePreySubSubModel

% In ports
in: in_port_Prey in_port_ctePulse in_port_start


% Out ports
out: out_port_PreySubSubModelStock out_port_combiner

% Input connections
link: in_port_start in_port_start@DEVS_BASIC_COUPLED_PreySubSubModelStock
link: in_port_Prey in_port_Prey@combiner3
link: in_port_ctePulse in_port_ctePulse@ctePulse3

% Output connections
link: out_port_PreySubSubModelStock@DEVS_BASIC_COUPLED_PreySubSubModelStock out_port_PreySubSubModelStock
link: out_port_combiner@combiner3 out_port_combiner

% Internal connections
link: out_port_combiner@combiner3 in_port_combiner@DEVS_BASIC_COUPLED_PreySubSubModelStock
link: out_port_ctePulse@ctePulse3 in_port_ctePulse@combiner3

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')



[DEVS_BASIC_COUPLED_PreySubSubModelStock]
%Coupled model
components: Flow1_PreySubSubModelStock4@Flow1_PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock TotPreySubSubModelStock4@TotPreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock PreySubSubModelStock4@PreySubSubModelStockDEVS_BASIC_COUPLED_PreySubSubModelStock PULSE_V_combiner_FP_10_I_50_Flow14@PULSE_V_combiner_FP_10_I_50_Flow1DEVS_BASIC_COUPLED_PreySubSubModelStock

% In ports
in: in_port_combiner in_port_start


% Out ports
out: out_port_PreySubSubModelStock

% Input connections
link: in_port_combiner in_port_combiner@PULSE_V_combiner_FP_10_I_50_Flow14
link: in_port_start in_port_start@PULSE_V_combiner_FP_10_I_50_Flow14

% Output connections
link: out_port_PreySubSubModelStock@PreySubSubModelStock4 out_port_PreySubSubModelStock

% Internal connections
link: out_port_PreySubSubModelStock@PreySubSubModelStock4 in_port_PreySubSubModelStock@Flow1_PreySubSubModelStock4
link: out_port_TotPreySubSubModelStock@TotPreySubSubModelStock4 in_port_TotPreySubSubModelStock@PreySubSubModelStock4
link: out_port_PULSE_V_combiner_FP_10_I_50_Flow1@PULSE_V_combiner_FP_10_I_50_Flow14 in_port_subtract@PreySubSubModelStock4
link: out_port_Flow1_PreySubSubModelStock@Flow1_PreySubSubModelStock4 in_minus_port_Flow1_PreySubSubModelStock@TotPreySubSubModelStock4

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[PreySubSubModelStock4]
% Atomic model DEVSIntegrator
x0: 1000
non_negative: 0
dQMin: 0.001
dQRel: 0.001










