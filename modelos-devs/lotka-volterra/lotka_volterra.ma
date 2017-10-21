[top]
components : int_hares@QSS1 int_lynx@QSS1 ftl@FtotLynx fpl@FplusLynx fml@FminusLynx fth@FtotHares fph@FplusHares fmh@FminusHares hareDeathRate@Cte hareBirthRate@Cte lynxDeathRate@Cte lynxBirthRate@Cte

% Puertos input output
in : inHareDeathRate inHareBirthRate inLynxDeathRate inLynxBirthRate
out : hares lynx

% Links parametros a constantes
link : inHareDeathRate inVal@hareDeathRate
link : inHareBirthRate inVal@hareBirthRate
link : inLynxDeathRate inVal@lynxDeathRate
link : inLynxBirthRate inVal@lynxBirthRate

% Links constantes a modelo
link : out@hareDeathRate inHareDeathRate@fmh
link : out@hareBirthRate inHareBirthRate@fph
link : out@lynxDeathRate inLynxDeathRate@fml
link : out@lynxBirthRate inLynxBirthRate@fpl

% Links acoplado minimal integrador hares
link : out@fph inPlus@fth
link : out@fmh inMinus@fth
link : out@fth in@int_hares

% Links acoplado minimal integrador lynx
link : out@fpl inPlus@ftl
link : out@fml inMinus@ftl
link : out@ftl in@int_lynx

% Links modelo
link : out@int_hares inHares@fph
link : out@int_hares inHares@fmh
link : out@int_hares inHares@fpl
link : out@int_lynx inLynx@fpl
link : out@int_lynx inLynx@fml
link : out@int_lynx inLynx@fmh

% Links output variables de interes
link : out@int_lynx lynx
link : out@int_hares hares

[int_hares]
x0 : 250
dQRel : 1e-2
dQMin : 1e-4

[int_lynx]
x0 : 100
dQRel : 1e-2
dQMin : 1e-4
