[top]
components : PreyTot@PreyTot Prey@QSS1 PredatorTot@PredatorTot Predator@QSS1 paramD@Cte paramC@Cte paramB@Cte paramA@Cte PlusPreyPlus@PlusPreyPlus PlusPreyMinus@PlusPreyMinus PlusPredatorPlus@PlusPredatorPlus PlusPredatorMinus@PlusPredatorMinus MinusPredatorPlus@MinusPredatorPlus MinusPredatorMinus@MinusPredatorMinus MinusPreyPlus@MinusPreyPlus MinusPreyMinus@MinusPreyMinus 

% External Input Ports
in : paramD paramC paramB paramA 
% External Output Ports
out : Prey Predator 

% Links internos (input ports => atomicos tipo 'Cte')
link : paramD inValue@paramD
link : paramC inValue@paramC
link : paramB inValue@paramB
link : paramA inValue@paramA

% Internal I/O Connections
link : out@PreyTot in@Prey
link : out@PredatorTot in@Predator
link : out@PlusPreyPlus PlusPreyPlus@PreyTot
link : out@PlusPredatorPlus PlusPredatorPlus@PredatorTot
link : out@MinusPredatorMinus MinusPredatorMinus@PredatorTot
link : out@MinusPreyMinus MinusPreyMinus@PreyTot
link : out@Prey Prey@PlusPreyPlus
link : out@Prey Prey@MinusPreyMinus
link : out@Predator Predator@PlusPredatorPlus
link : out@Predator Predator@MinusPredatorMinus
link : out@paramD paramD@PlusPredatorPlus
link : out@paramD paramD@PlusPredatorMinus
link : out@paramC paramC@MinusPredatorPlus
link : out@paramC paramC@MinusPredatorMinus
link : out@paramB paramB@MinusPreyPlus
link : out@paramB paramB@MinusPreyMinus
link : out@paramA paramA@PlusPreyPlus
link : out@paramA paramA@PlusPreyMinus

% Links internos (variables de interes => output ports)
link : out@Prey Prey
link : out@Predator Predator

% Integradores
[Prey]
x0 : 100
dQRel : 0.0001
dQMin : 0.0001
[Predator]
x0 : 5
dQRel : 0.0001
dQMin : 0.0001