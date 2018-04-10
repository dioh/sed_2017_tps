
[top]
%Coupled model
components: paramE specialParamC DEVS_BASIC_COUPLED_hunter paramA paramB paramD paramPulse DEVS_COUPLED_PredatorModel DEVS_COUPLED_PreyModel PULSE_V_1_FP_1_I_1 PULSE_V_2_FP_2_I_2

% In ports
in: in_port_ctePulse in_port_cteVariable in_port_paramA in_port_paramB in_port_paramD in_port_paramPulse



% Out ports
out: out_port_Predator out_port_Prey out_port_PreySubModelStock out_port_PreySubSubModelStock out_port_auxVariable out_port_combiner out_port_hunter out_port_paramE out_port_specialParamC

% Input connections
link: in_port_cteVariable in_port_cteVariable@DEVS_COUPLED_PredatorModel
link: in_port_ctePulse in_port_ctePulse@DEVS_COUPLED_PreyModel
link: in_port_paramA in_port_paramA@paramA
link: in_port_paramB in_port_paramB@paramB
link: in_port_paramD in_port_paramD@paramD
link: in_port_paramPulse in_port_paramPulse@paramPulse

% Output connections
link: out_port_Predator@DEVS_COUPLED_PredatorModel out_port_Predator
link: out_port_Prey@DEVS_COUPLED_PreyModel out_port_Prey
link: out_port_PreySubModelStock@DEVS_COUPLED_PreyModel out_port_PreySubModelStock
link: out_port_PreySubSubModelStock@DEVS_COUPLED_PreyModel out_port_PreySubSubModelStock
link: out_port_auxVariable@DEVS_COUPLED_PredatorModel out_port_auxVariable
link: out_port_combiner@DEVS_COUPLED_PreyModel out_port_combiner
link: out_port_hunter@DEVS_BASIC_COUPLED_hunter out_port_hunter
link: out_port_paramE@paramE out_port_paramE
link: out_port_specialParamC@specialParamC out_port_specialParamC

% Internal connections
link: out_port_paramPulse@paramPulse in_port_paramPulse@DEVS_BASIC_COUPLED_hunter
link: out_port_Prey@DEVS_COUPLED_PreyModel in_port_Prey@DEVS_COUPLED_PredatorModel
link: out_port_hunter@DEVS_BASIC_COUPLED_hunter in_port_hunter@DEVS_COUPLED_PredatorModel
link: out_port_paramD@paramD in_port_paramD@DEVS_COUPLED_PredatorModel
link: out_port_specialParamC@specialParamC in_port_specialParamC@DEVS_COUPLED_PredatorModel
link: out_port_Predator@DEVS_COUPLED_PredatorModel in_port_Predator@DEVS_COUPLED_PreyModel
link: out_port_paramA@paramA in_port_paramA@DEVS_COUPLED_PreyModel
link: out_port_paramB@paramB in_port_paramB@DEVS_COUPLED_PreyModel
link: out_port_PULSE_V_1_FP_1_I_1@PULSE_V_1_FP_1_I_1 in_port_PULSE_V_1_FP_1_I_1@paramE
link: out_port_paramA@paramA in_port_paramA@paramE
link: out_port_paramB@paramB in_port_paramB@paramE
link: out_port_PULSE_V_2_FP_2_I_2@PULSE_V_2_FP_2_I_2 in_port_PULSE_V_2_FP_2_I_2@specialParamC

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')





[DEVS_BASIC_COUPLED_hunter]
%Coupled model
components: populationDeath_hunter populationGrowth_hunter Tothunter hunter PULSE_V_paramPulse_FP_1_I_1

% In ports
in: in_port_paramPulse



% Out ports
out: out_port_hunter

% Input connections
link: in_port_paramPulse in_port_paramPulse@PULSE_V_paramPulse_FP_1_I_1

% Output connections
link: out_port_hunter@hunter out_port_hunter

% Internal connections
link: out_port_populationDeath_hunter@populationDeath_hunter in_port_populationDeath_hunter@Tothunter
link: out_port_populationGrowth_hunter@populationGrowth_hunter in_port_populationGrowth_hunter@Tothunter
link: out_port_Tothunter@Tothunter in_port_Tothunter@hunter
link: out_port_hunter@hunter in_port_hunter@populationDeath_hunter
link: out_port_PULSE_V_paramPulse_FP_1_I_1@PULSE_V_paramPulse_FP_1_I_1 in_port_PULSE_V_paramPulse_FP_1_I_1@populationGrowth_hunter
link: out_port_hunter@hunter in_port_hunter@populationGrowth_hunter

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')








[hunter]
% Atomic model DEVSIntegrator
x0: 5
dQMin: 0.001
dQRel: 0.001













[DEVS_COUPLED_PredatorModel]
%Coupled model
components: auxVariable DEVS_BASIC_COUPLED_Predator cteVariable paramD specialParamC

% In ports
in: in_port_Prey in_port_cteVariable in_port_hunter in_port_paramD in_port_specialParamC



% Out ports
out: out_port_Predator out_port_auxVariable

% Input connections
link: in_port_Prey in_port_Prey@DEVS_BASIC_COUPLED_Predator
link: in_port_hunter in_port_hunter@DEVS_BASIC_COUPLED_Predator
link: in_port_cteVariable in_port_cteVariable@cteVariable
link: in_port_paramD in_port_paramD@paramD
link: in_port_specialParamC in_port_specialParamC@specialParamC

% Output connections
link: out_port_Predator@DEVS_BASIC_COUPLED_Predator out_port_Predator
link: out_port_auxVariable@auxVariable out_port_auxVariable

% Internal connections
link: out_port_cteVariable@cteVariable in_port_cteVariable@DEVS_BASIC_COUPLED_Predator
link: out_port_paramD@paramD in_port_paramD@DEVS_BASIC_COUPLED_Predator
link: out_port_specialParamC@specialParamC in_port_specialParamC@DEVS_BASIC_COUPLED_Predator
link: out_port_cteVariable@cteVariable in_port_cteVariable@auxVariable

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')



[DEVS_BASIC_COUPLED_Predator]
%Coupled model
components: MinusPredator_Predator PlusPredator_Predator TotPredator Predator

% In ports
in: in_port_Prey in_port_cteVariable in_port_hunter in_port_paramD in_port_specialParamC



% Out ports
out: out_port_Predator

% Input connections
link: in_port_hunter in_port_hunter@MinusPredator_Predator
link: in_port_specialParamC in_port_specialParamC@MinusPredator_Predator
link: in_port_Prey in_port_Prey@PlusPredator_Predator
link: in_port_cteVariable in_port_cteVariable@PlusPredator_Predator
link: in_port_paramD in_port_paramD@PlusPredator_Predator

% Output connections
link: out_port_Predator@Predator out_port_Predator

% Internal connections
link: out_port_Predator@Predator in_port_Predator@MinusPredator_Predator
link: out_port_Predator@Predator in_port_Predator@PlusPredator_Predator
link: out_port_TotPredator@TotPredator in_port_TotPredator@Predator
link: out_port_MinusPredator_Predator@MinusPredator_Predator in_port_MinusPredator_Predator@TotPredator
link: out_port_PlusPredator_Predator@PlusPredator_Predator in_port_PlusPredator_Predator@TotPredator

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')








[Predator]
% Atomic model DEVSIntegrator
x0: 5
dQMin: 0.001
dQRel: 0.001









[DEVS_COUPLED_PreyModel]
%Coupled model
components: DEVS_BASIC_COUPLED_Prey paramA paramB DEVS_COUPLED_PreySubModel

% In ports
in: in_port_Predator in_port_ctePulse in_port_paramA in_port_paramB



% Out ports
out: out_port_Prey out_port_PreySubModelStock out_port_PreySubSubModelStock out_port_combiner

% Input connections
link: in_port_Predator in_port_Predator@DEVS_BASIC_COUPLED_Prey
link: in_port_ctePulse in_port_ctePulse@DEVS_COUPLED_PreySubModel
link: in_port_paramA in_port_paramA@paramA
link: in_port_paramB in_port_paramB@paramB

% Output connections
link: out_port_Prey@DEVS_BASIC_COUPLED_Prey out_port_Prey
link: out_port_PreySubModelStock@DEVS_COUPLED_PreySubModel out_port_PreySubModelStock
link: out_port_PreySubSubModelStock@DEVS_COUPLED_PreySubModel out_port_PreySubSubModelStock
link: out_port_combiner@DEVS_COUPLED_PreySubModel out_port_combiner

% Internal connections
link: out_port_PreySubModelStock@DEVS_COUPLED_PreySubModel in_port_PreySubModelStock@DEVS_BASIC_COUPLED_Prey
link: out_port_PreySubSubModelStock@DEVS_COUPLED_PreySubModel in_port_PreySubSubModelStock@DEVS_BASIC_COUPLED_Prey
link: out_port_paramA@paramA in_port_paramA@DEVS_BASIC_COUPLED_Prey
link: out_port_paramB@paramB in_port_paramB@DEVS_BASIC_COUPLED_Prey
link: out_port_Prey@DEVS_BASIC_COUPLED_Prey in_port_Prey@DEVS_COUPLED_PreySubModel

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')

[DEVS_BASIC_COUPLED_Prey]
%Coupled model
components: MinusPrey_Prey PlusPrey_Prey TotPrey Prey

% In ports
in: in_port_Predator in_port_PreySubModelStock in_port_PreySubSubModelStock in_port_paramA in_port_paramB



% Out ports
out: out_port_Prey

% Input connections
link: in_port_Predator in_port_Predator@MinusPrey_Prey
link: in_port_PreySubSubModelStock in_port_PreySubSubModelStock@MinusPrey_Prey
link: in_port_paramB in_port_paramB@MinusPrey_Prey
link: in_port_PreySubModelStock in_port_PreySubModelStock@PlusPrey_Prey
link: in_port_paramA in_port_paramA@PlusPrey_Prey

% Output connections
link: out_port_Prey@Prey out_port_Prey

% Internal connections
link: out_port_Prey@Prey in_port_Prey@MinusPrey_Prey
link: out_port_Prey@Prey in_port_Prey@PlusPrey_Prey
link: out_port_TotPrey@TotPrey in_port_TotPrey@Prey
link: out_port_MinusPrey_Prey@MinusPrey_Prey in_port_MinusPrey_Prey@TotPrey
link: out_port_PlusPrey_Prey@PlusPrey_Prey in_port_PlusPrey_Prey@TotPrey

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')








[Prey]
% Atomic model DEVSIntegrator
x0: 100
dQMin: 0.001
dQRel: 0.001







[DEVS_COUPLED_PreySubModel]
%Coupled model
components: DEVS_BASIC_COUPLED_PreySubModelStock DEVS_COUPLED_PreySubSubModel

% In ports
in: in_port_Prey in_port_ctePulse



% Out ports
out: out_port_PreySubModelStock out_port_PreySubSubModelStock out_port_combiner

% Input connections
link: in_port_Prey in_port_Prey@DEVS_BASIC_COUPLED_PreySubModelStock
link: in_port_Prey in_port_Prey@DEVS_COUPLED_PreySubSubModel
link: in_port_ctePulse in_port_ctePulse@DEVS_COUPLED_PreySubSubModel

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
components: preySubFlow_PreySubModelStock TotPreySubModelStock PreySubModelStock

% In ports
in: in_port_Prey in_port_PreySubSubModelStock



% Out ports
out: out_port_PreySubModelStock

% Input connections
link: in_port_Prey in_port_Prey@preySubFlow_PreySubModelStock
link: in_port_PreySubSubModelStock in_port_PreySubSubModelStock@preySubFlow_PreySubModelStock

% Output connections
link: out_port_PreySubModelStock@PreySubModelStock out_port_PreySubModelStock

% Internal connections
link: out_port_TotPreySubModelStock@TotPreySubModelStock in_port_TotPreySubModelStock@PreySubModelStock
link: out_port_preySubFlow_PreySubModelStock@preySubFlow_PreySubModelStock in_port_preySubFlow_PreySubModelStock@TotPreySubModelStock
link: out_port_PreySubModelStock@PreySubModelStock in_port_PreySubModelStock@preySubFlow_PreySubModelStock

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[PreySubModelStock]
% Atomic model DEVSIntegrator
x0: 0
dQMin: 0.001
dQRel: 0.001



[DEVS_COUPLED_PreySubSubModel]
%Coupled model
components: combiner DEVS_BASIC_COUPLED_PreySubSubModelStock ctePulse

% In ports
in: in_port_Prey in_port_ctePulse



% Out ports
out: out_port_PreySubSubModelStock out_port_combiner

% Input connections
link: in_port_Prey in_port_Prey@combiner
link: in_port_ctePulse in_port_ctePulse@ctePulse

% Output connections
link: out_port_PreySubSubModelStock@DEVS_BASIC_COUPLED_PreySubSubModelStock out_port_PreySubSubModelStock
link: out_port_combiner@combiner out_port_combiner

% Internal connections
link: out_port_combiner@combiner in_port_combiner@DEVS_BASIC_COUPLED_PreySubSubModelStock
link: out_port_ctePulse@ctePulse in_port_ctePulse@combiner

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')



[DEVS_BASIC_COUPLED_PreySubSubModelStock]
%Coupled model
components: Flow1_PreySubSubModelStock TotPreySubSubModelStock PreySubSubModelStock PULSE_V_combiner_FP_10_I_50

% In ports
in: in_port_combiner



% Out ports
out: out_port_PreySubSubModelStock

% Input connections
link: in_port_combiner in_port_combiner@PULSE_V_combiner_FP_10_I_50

% Output connections
link: out_port_PreySubSubModelStock@PreySubSubModelStock out_port_PreySubSubModelStock

% Internal connections
link: out_port_PULSE_V_combiner_FP_10_I_50@PULSE_V_combiner_FP_10_I_50 in_port_PULSE_V_combiner_FP_10_I_50@Flow1_PreySubSubModelStock
link: out_port_PreySubSubModelStock@PreySubSubModelStock in_port_PreySubSubModelStock@Flow1_PreySubSubModelStock
link: out_port_TotPreySubSubModelStock@TotPreySubSubModelStock in_port_TotPreySubSubModelStock@PreySubSubModelStock
link: out_port_Flow1_PreySubSubModelStock@Flow1_PreySubSubModelStock in_port_Flow1_PreySubSubModelStock@TotPreySubSubModelStock

% Model components
% No hay que mostrar los atomicos (se declaran directo en la seccion 'components:')






[PreySubSubModelStock]
% Atomic model DEVSIntegrator
x0: 1000
dQMin: 0.001
dQRel: 0.001










