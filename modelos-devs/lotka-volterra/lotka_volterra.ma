[top]
components : int_hares@QSS1 int_lynx@QSS1 ftl@FtotLynx fpl@FplusLynx fml@FminusLynx fth@FtotHares fph@FplusHares fmh@FminusHares
out : hares lynx
link : out@int_hares hares
link : out@int_hares inVar1@fph
link : out@int_hares inVar1@fmh
link : out@int_hares inVar2@fpl
link : out@fph inPlus@fth
link : out@fmh inMinus@fth
link : out@fth in@int_hares
link : out@int_lynx lynx
link : out@int_lynx inVar1@fpl
link : out@int_lynx inVar1@fml
link : out@int_lynx inVar2@fmh
link : out@fpl inPlus@ftl
link : out@fml inMinus@ftl
link : out@ftl in@int_lynx

[int_hares]
x0 : 34
dQRel : 1e-2
dQMin : 1e-4

[int_lynx]
x0 : 4
dQRel : 1e-2
dQMin : 1e-4
