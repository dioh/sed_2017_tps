[top]
components : RationalSupportersTot@RationalSupportersTot RationalSupporters@QSS1 DegeneratesTot@DegeneratesTot Degenerates@QSS1 NeutralistsTot@NeutralistsTot Neutralists@QSS1 incubationTime@Cte rationalistsInfluence@rationalistsInfluence memeticInfectivity@Cte influencePerDegenerate@Cte influencePerRationalist@Cte degeneratesInfectivityRate@degeneratesInfectivityRate degeneratesInfluence@degeneratesInfluence trueMemes@trueMemes falseMemeSize@Cte rationalistsInfectivityRate@rationalistsInfectivityRate percentRationalists@percentRationalists falseMemes@falseMemes infectionLifetime@Cte constantTrueMemeSize@Cte rationalistsRecoveryRatePlus@rationalistsRecoveryRatePlus rationalistsRecoveryRateMinus@rationalistsRecoveryRateMinus degeneratesRecoveryRatePlus@degeneratesRecoveryRatePlus degeneratesRecoveryRateMinus@degeneratesRecoveryRateMinus degeneratesMaturationRatePlus@degeneratesMaturationRatePlus degeneratesMaturationRateMinus@degeneratesMaturationRateMinus rationalistsMaturationRatePlus@rationalistsMaturationRatePlus rationalistsMaturationRateMinus@rationalistsMaturationRateMinus 

% External Input Ports
in : incubationTime memeticInfectivity influencePerDegenerate influencePerRationalist falseMemeSize infectionLifetime constantTrueMemeSize 
% External Output Ports
out : RationalSupporters Degenerates Neutralists 

% Links internos (input ports => atomicos tipo 'Cte')
link : incubationTime inValue@incubationTime
link : memeticInfectivity inValue@memeticInfectivity
link : influencePerDegenerate inValue@influencePerDegenerate
link : influencePerRationalist inValue@influencePerRationalist
link : falseMemeSize inValue@falseMemeSize
link : infectionLifetime inValue@infectionLifetime
link : constantTrueMemeSize inValue@constantTrueMemeSize

% Internal I/O Connections
link : out@RationalSupportersTot in@RationalSupporters
link : out@DegeneratesTot in@Degenerates
link : out@NeutralistsTot in@Neutralists
link : out@rationalistsRecoveryRateMinus rationalistsRecoveryRateMinus@RationalSupportersTot
link : out@rationalistsRecoveryRatePlus rationalistsRecoveryRatePlus@NeutralistsTot
link : out@degeneratesRecoveryRatePlus degeneratesRecoveryRatePlus@DegeneratesTot
link : out@degeneratesRecoveryRateMinus degeneratesRecoveryRateMinus@NeutralistsTot
link : out@degeneratesMaturationRateMinus degeneratesMaturationRateMinus@DegeneratesTot
link : out@degeneratesMaturationRatePlus degeneratesMaturationRatePlus@NeutralistsTot
link : out@rationalistsMaturationRatePlus rationalistsMaturationRatePlus@RationalSupportersTot
link : out@rationalistsMaturationRateMinus rationalistsMaturationRateMinus@NeutralistsTot
link : out@RationalSupporters RationalSupporters@rationalistsRecoveryRatePlus
link : out@RationalSupporters RationalSupporters@rationalistsRecoveryRateMinus
link : out@RationalSupporters RationalSupporters@rationalistsInfluence
link : out@RationalSupporters RationalSupporters@percentRationalists
link : out@Degenerates Degenerates@degeneratesRecoveryRatePlus
link : out@Degenerates Degenerates@degeneratesRecoveryRateMinus
link : out@Degenerates Degenerates@degeneratesInfluence
link : out@Degenerates Degenerates@percentRationalists
link : out@Neutralists Neutralists@degeneratesMaturationRatePlus
link : out@Neutralists Neutralists@degeneratesMaturationRateMinus
link : out@Neutralists Neutralists@rationalistsMaturationRatePlus
link : out@Neutralists Neutralists@rationalistsMaturationRateMinus
link : out@incubationTime incubationTime@degeneratesInfectivityRate
link : out@incubationTime incubationTime@rationalistsInfectivityRate
link : out@rationalistsInfluence rationalistsInfluence@trueMemes
link : out@memeticInfectivity memeticInfectivity@degeneratesInfectivityRate
link : out@memeticInfectivity memeticInfectivity@rationalistsInfectivityRate
link : out@influencePerDegenerate influencePerDegenerate@degeneratesInfluence
link : out@influencePerRationalist influencePerRationalist@rationalistsInfluence
link : out@degeneratesInfectivityRate degeneratesInfectivityRate@degeneratesMaturationRatePlus
link : out@degeneratesInfectivityRate degeneratesInfectivityRate@degeneratesMaturationRateMinus
link : out@degeneratesInfluence degeneratesInfluence@falseMemes
link : out@trueMemes trueMemes@rationalistsInfectivityRate
link : out@falseMemeSize falseMemeSize@falseMemes
link : out@rationalistsInfectivityRate rationalistsInfectivityRate@rationalistsMaturationRatePlus
link : out@rationalistsInfectivityRate rationalistsInfectivityRate@rationalistsMaturationRateMinus
link : out@falseMemes falseMemes@degeneratesInfectivityRate
link : out@infectionLifetime infectionLifetime@rationalistsRecoveryRatePlus
link : out@infectionLifetime infectionLifetime@rationalistsRecoveryRateMinus
link : out@infectionLifetime infectionLifetime@degeneratesRecoveryRatePlus
link : out@infectionLifetime infectionLifetime@degeneratesRecoveryRateMinus
link : out@constantTrueMemeSize constantTrueMemeSize@trueMemes

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