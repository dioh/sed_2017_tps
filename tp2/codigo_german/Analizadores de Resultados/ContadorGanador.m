close all
clear all
clc
A = importdata('/home/argos/Dropbox/DEVS/TP Final/hola_3.8.txt');

thr_win = 70;   % Si saca esta o más cantidad de votos, ese partido gana.

% Para cada simulación, determino quien gana.
for i=1:size(A,1)
    if max(A(i,[4:6]))<thr_win
        Win(i,:)=[A(i,[1,2]),1,0,0];       % Bipartidismo.
    else
        if A(i,6)>=thr_win
            Win(i,:)=[A(i,[1,2]),0,0,1];   % Ganan indecisos.
        end
        if max(A(i,[4:5]))>=thr_win
            Win(i,:)=[A(i,[1,2]),0,1,0];   % Unipartidismo.
        end
    end
end


% Sumo sobre todas las simulaciones:
D=zeros(45,5);
n=1;
for i=1:(size(A,1)-1)
    if A(i,2)==A(i+1,2)
        D(n,:)=D(n,:)+Win(i,:);
    else
        D(n,:)=D(n,:)+Win(i,:);
        n=n+1;
    end
end
D(45,:)=D(45,:)+Win(size(A,1),:);
D=D./10;        % Col 3 = % de bipartidismo | Col 4 = $ de indecisión | Col 5 = % de unipartidismo,

% D es una matriz que tiene los % de las veces que se efectuaron cada
% escenario en las simulaciones. Por ejemplo 60.0000   40.0000    0.7000
% 0.2000    0.1000 indica que cuando P0_ini = 60% | Influyentes = 40% hubo
% un 70% de los casos en donde el estado final fue bipartidismo, 20%
% unipartidismo y 10% indecisión.

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
ZI = griddata(x,y,100.*D(:,3),XI,YI);
contourf(XI,YI,ZI)
set(gca, 'CLim', [0, 100]);      % Para que los colores vayan de 0 a 100.
caxis([0 100])

ylabel('Influyentes_{ini} [%]')
xlabel('P0_{ini} [%]')
title('Bipartidismo')

subplot(1,4,2)
set(gca,'fontsize',18)
ZI = griddata(x,y,100*D(:,4),XI,YI);
contourf(XI,YI,ZI)
set(gca, 'CLim', [0, 100]);      % Para que los colores vayan de 0 a 100.
caxis([0 100])
xlabel('P0_{ini} [%]')
title('Unipartidismo')

subplot(1,4,3)
set(gca,'fontsize',18)
ZI = griddata(x,y,100*D(:,5),XI,YI);
contourf(XI,YI,ZI)
set(gca, 'CLim', [0, 100]);      % Para que los colores vayan de 0 a 100.
caxis([0 100])
xlabel('P0_{ini} [%]')
title('indecisión')

h=colorbar;
set(h, 'Position', [.7514 .11 .0581 .8150],'fontsize',18)
%----------------------------------------------------------
% PARTE DISCRETA:
figure

WinMatrix_bipart=zeros(9,9);                
WinMatrix_unipart=zeros(9,9);               
WinMatrix_nose=zeros(9,9);               
for k=1:size(D,1)
    WinMatrix_bipart(10-round(D(k,2)./10),round(D(k,1)./10))=100*D(k,3);
    WinMatrix_unipart(10-round(D(k,2)./10),round(D(k,1)./10))=100*D(k,4);
    WinMatrix_nose(10-round(D(k,2)./10),round(D(k,1)./10))=100*D(k,5);
end
% Para que funcione el gca tengo que escribirlo en forma de matriz.

subplot(1,4,1)
colormap('winter')
set(gca,'fontsize',18)
imagesc(WinMatrix_bipart)
set(gca, 'CLim', [0, 100]);     % Para que los colores vayan de 0 a 100.
caxis([0 100])
ylabel('Influyentes_{ini} [%]')
xlabel('P0_{ini} [%]')
title('Bipartidismo')

%Esto arregla el tema de los ejes "y":
yticklabels = 10:10:90;
yticks = linspace(1, size(WinMatrix_bipart, 1), numel(yticklabels));
set(gca, 'YTick', yticks, 'YTickLabel', flipud(yticklabels(:)))


subplot(1,4,2)
set(gca,'fontsize',18)
imagesc(WinMatrix_unipart)
set(gca, 'CLim', [0, 100]);      % Para que los colores vayan de 0 a 100.
xlabel('P0_{ini} [%]')
title('Unipartidismo')
set(gca, 'YTick', yticks, 'YTickLabel', flipud(yticklabels(:)))

subplot(1,4,3)
set(gca,'fontsize',18)
imagesc(WinMatrix_nose)
set(gca, 'CLim', [0, 100]);      % Para que los colores vayan de 0 a 100.
xlabel('P0_{ini} [%]')
title('indecisión')
set(gca, 'YTick', yticks, 'YTickLabel', flipud(yticklabels(:)))

h=colorbar;
set(h, 'Position', [.7514 .11 .0581 .8150],'fontsize',18)