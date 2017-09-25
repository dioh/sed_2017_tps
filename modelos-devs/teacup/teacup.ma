[top]
components : int@QSS1 ft@Ftot fp@Fplus fm@Fminus 
out : tempTeacup
link : out@fp inPlus@ft
link : out@fm inMinus@ft
link : out@ft in@int
link : out@int inVar1@fm 
link : out@int tempTeacup

[int]
x0 : 80
dQRel : 1e-2
dQMin : 1e-4