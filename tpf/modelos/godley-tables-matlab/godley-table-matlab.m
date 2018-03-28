function f=f(x,t)
Bank=x(1);
DebtFirms=x(2);
Firms=x(3);
Workers=x(4);
tauR=7;
tauL=7;
tauW=0.04;
tauT=0.33;
tauB=1;
share=0.3;
rateOfInterestOnLoans=0.185;
RepayF=(DebtFirms)/((tauR));
Money=Workers+Firms+Bank;
LendF=(DebtFirms)/((tauL));
Interest=(DebtFirms)*(rateOfInterestOnLoans);
GDProduct=(Firms)/((tauT));
ConsW=(Workers)/((tauW));
ConsB=(Bank)/((tauB));
Wages=(GDProduct)*(1-(share));
velocityOfMoney=(GDProduct)/((Money));
BankShare=(Interest)/((GDProduct));
WagesShare=(Wages)/((GDProduct));
ProfitGross=GDProduct-(Wages);
ProfitNet=ProfitGross-(Interest);
ProfitShare=(ProfitNet)/((GDProduct));
f(1)=Interest-(ConsB);
f(2)=LendF-(RepayF);
f(3)=LendF+ConsW+ConsB-(Interest+Wages+RepayF);
f(4)=Wages-(ConsW);
endfunction;

x0(1)=8;
x0(2)=100;
x0(3)=80;
x0(4)=12;