close all
clear all
clc
A = importdata('/home/argos/Dropbox/DEVS/TP Final/hola_3.8.txt');

D=zeros(45,6);
n=1;
for i=1:(size(A,1)-1)
    if A(i,2)==A(i+1,2)
        D(n,:)=D(n,:)+A(i,:);
    else
        D(n,:)=D(n,:)+A(i,:);
        n=n+1;
    end
end
D(45,:)=D(45,:)+A(size(A,1),:);
D=D./10;

% Col 1 de D = % de P0 iniciales | Col 2 = % de Influyents iniciales | Col
% 3 = 5.5 (no sirve) | Col 4-6 = promedio de votos. 

x=D(:,1);
y=D(:,2);
%--------------------------------------------------------
xi=linspace(min(x),max(x),30);
yi=linspace(min(y),max(y),30);

[XI YI]=meshgrid(xi,yi);
figure
subplot(1,4,1)
colormap('hot');
set(gca,'fontsize',18)
ZI = griddata(x,y,D(:,4),XI,YI);
contourf(XI,YI,ZI)
set(gca, 'CLim', [0, 100]);     % Para que los colores vayan de 0 a 100.
caxis([0 100])

ylabel('Influyentes_{ini} [%]')
xlabel('P0_{ini} [%]')
title('Partido A')

subplot(1,4,2)
set(gca,'fontsize',18)
ZI = griddata(x,y,D(:,5),XI,YI);
contourf(XI,YI,ZI)
set(gca, 'CLim', [0, 100]);      % Para que los colores vayan de 0 a 100.
caxis([0 100])
xlabel('P0_{ini} [%]')
title('Partido B')

subplot(1,4,3)
set(gca,'fontsize',18)
ZI = griddata(x,y,D(:,6),XI,YI);
contourf(XI,YI,ZI)
set(gca, 'CLim', [0, 100]);      % Para que los colores vayan de 0 a 100.
caxis([0 100])
xlabel('P0_{ini} [%]')
title('Sin definir')

h=colorbar;
set(h, 'Position', [.7514 .11 .0581 .8150],'fontsize',18)