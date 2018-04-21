[top]
components : RationalSupportersTot@RationalSupportersTot RationalSupporters@QSS1 DegeneratesTot@DegeneratesTot Degenerates@QSS1 NeutralistsTot@NeutralistsTot Neutralists@QSS1 outDegeneratesRightPlus@outDegeneratesRightPlus outDegeneratesRightMinus@outDegeneratesRightMinus neutralistsToDegeneratesPlus@neutralistsToDegeneratesPlus neutralistsToDegeneratesMinus@neutralistsToDegeneratesMinus rationalsToNeutralistsPlus@rationalsToNeutralistsPlus rationalsToNeutralistsMinus@rationalsToNeutralistsMinus neutralistsToRationalsPlus@neutralistsToRationalsPlus neutralistsToRationalsMinus@neutralistsToRationalsMinus outDegeneratesLeftPlus@outDegeneratesLeftPlus outDegeneratesLeftMinus@outDegeneratesLeftMinus 

% External Input Ports
in : 
% External Output Ports
out : RationalSupporters Degenerates Neutralists 

% Links internos (input ports => atomicos tipo 'Cte')

% Internal I/O Connections
link : out@RationalSupportersTot in@RationalSupporters
link : out@DegeneratesTot in@Degenerates
link : out@NeutralistsTot in@Neutralists
link : out@outDegeneratesRightMinus outDegeneratesRightMinus@DegeneratesTot
link : out@neutralistsToDegeneratesPlus neutralistsToDegeneratesPlus@DegeneratesTot
link : out@neutralistsToDegeneratesMinus neutralistsToDegeneratesMinus@NeutralistsTot
link : out@rationalsToNeutralistsMinus rationalsToNeutralistsMinus@RationalSupportersTot
link : out@rationalsToNeutralistsPlus rationalsToNeutralistsPlus@NeutralistsTot
link : out@neutralistsToRationalsPlus neutralistsToRationalsPlus@RationalSupportersTot
link : out@neutralistsToRationalsMinus neutralistsToRationalsMinus@NeutralistsTot
link : out@outDegeneratesLeftMinus outDegeneratesLeftMinus@DegeneratesTot
link : out@RationalSupporters RationalSupporters@rationalsToNeutralistsPlus
link : out@RationalSupporters RationalSupporters@rationalsToNeutralistsMinus
link : out@Degenerates Degenerates@outDegeneratesRightPlus
link : out@Degenerates Degenerates@outDegeneratesRightMinus
link : out@Degenerates Degenerates@outDegeneratesLeftPlus
link : out@Degenerates Degenerates@outDegeneratesLeftMinus
link : out@Neutralists Neutralists@neutralistsToDegeneratesPlus
link : out@Neutralists Neutralists@neutralistsToDegeneratesMinus
link : out@Neutralists Neutralists@neutralistsToRationalsPlus
link : out@Neutralists Neutralists@neutralistsToRationalsMinus

% Links internos (variables de interes => output ports)
link : out@RationalSupporters RationalSupporters
link : out@Degenerates Degenerates
link : out@Neutralists Neutralists

% Integradores
[RationalSupporters]
x0 : 1
dQRel : 0.0001
dQMin : 0.0001
[Degenerates]
x0 : 1
dQRel : 0.0001
dQMin : 0.0001
[Neutralists]
x0 : 98
dQRel : 0.0001
dQMin : 0.0001