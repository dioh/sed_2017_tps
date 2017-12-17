[top]
components : Susceptible@QSS1 Infectious@QSS1 Recovered@QSS1 ft_Recovered@ft_Recovered ft_Susceptible@ft_Susceptible ft_Infectious@ft_Infectious fm_Susceptible_Succumbing@fm_Susceptible_Succumbing fm_Infectious_Recovering@fm_Infectious_Recovering fp_Recovered_Recovering@fp_Recovered_Recovering fp_Infectious_Succumbing@fp_Infectious_Succumbing TotalPopulation@Cte Duration@Cte ContactInfectivity@Cte 

% Puertos: Input de parametros. Output de variables de interes
in : in_TotalPopulation in_Duration in_ContactInfectivity 
out : out_Susceptible out_Infectious out_Recovered 

% Links inputs a constantes (conexiones con el top model)
link : in_TotalPopulation inValue@TotalPopulation 
link : in_Duration inValue@Duration 
link : in_ContactInfectivity inValue@ContactInfectivity 


% Link entre Stocks, Cte's, Aux's y f's
link : out@TotalPopulation in_TotalPopulation@fm_Susceptible_Succumbing 
link : out@TotalPopulation in_TotalPopulation@fp_Infectious_Succumbing 
link : out@Duration in_Duration@fm_Infectious_Recovering 
link : out@Duration in_Duration@fp_Recovered_Recovering 
link : out@ContactInfectivity in_ContactInfectivity@fm_Susceptible_Succumbing 
link : out@ContactInfectivity in_ContactInfectivity@fp_Infectious_Succumbing 
link : out@fm_Susceptible_Succumbing inMinus_Succumbing@ft_Susceptible 
link : out@ft_Susceptible in@Susceptible 
link : out@fp_Infectious_Succumbing inPlus_Succumbing@ft_Infectious 
link : out@fm_Infectious_Recovering inMinus_Recovering@ft_Infectious 
link : out@ft_Infectious in@Infectious 
link : out@fp_Recovered_Recovering inPlus_Recovering@ft_Recovered 
link : out@ft_Recovered in@Recovered 
link : out@Susceptible in_Susceptible@fm_Susceptible_Succumbing 
link : out@Susceptible in_Infectious@fp_Infectious_Succumbing 
link : out@Infectious in_Susceptible@fm_Susceptible_Succumbing 
link : out@Infectious in_Infectious@fp_Infectious_Succumbing 
link : out@Infectious in_Infectious@fm_Infectious_Recovering 
link : out@Infectious in_Recovered@fp_Recovered_Recovering 


% Liks output variables de interes
link : out@Susceptible out_Susceptible
link : out@Infectious out_Infectious
link : out@Recovered out_Recovered


% Integradores
[Susceptible]
x0 : x0
dQRel : 1e-4
dQMin : ee-4

[Infectious]
x0 : x0
dQRel : 1e-4
dQMin : ee-4

[Recovered]
x0 : x0
dQRel : 1e-4
dQMin : ee-4

