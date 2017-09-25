[top]
components : int_susc@QSS1 int_inf@QSS1 int_recov@QSS1 fts@FtotSusc fps@FplusSusc fms@FminusSusc fti@FtotInf fpi@FplusInf fmi@FminusInf ftr@FtotRecov fpr@FplusRecov fmr@FminusRecov
out : susceptible infected recovered
link : out@int_susc susceptible
link : out@int_susc inVar1@fms
link : out@int_susc inVar2@fpi
link : out@fps inPlus@fts
link : out@fms inMinus@fts
link : out@fts in@int_susc
link : out@int_inf infected
link : out@int_inf inVar1@fpi
link : out@int_inf inVar1@fmi
link : out@int_inf inVar2@fms
link : out@int_inf inVar1@fpr
link : out@fpi inPlus@fti
link : out@fmi inMinus@fti
link : out@fti in@int_inf
link : out@fpr inPlus@ftr
link : out@fmr inMinus@ftr
link : out@ftr in@int_recov
link : out@int_recov recovered

[int_susc]
x0 : 1000
dQRel : 1e-2
dQMin : 1e-4

[int_inf]
x0 : 5
dQRel : 1e-2
dQMin : 1e-4

[int_recov]
x0 : 0
dQRel : 1e-2
dQMin : 1e-4
