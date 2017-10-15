close all
clear all
clc
A = importdata('/home/argos/Dropbox/DEVS/TP Final/holaequi.txt');

N=9;       % Cantidad de líneas de c.c.

n=0;
% Calculo el promedio del estado final:
D=zeros(N,6);
for i=1:N
    for k=1:10
         D(i,:)=D(i,:)+A(n+k,:);
    end
    n=n+10;
end
D = (D./10);

%---------------------------------------------------------------------------
subplot(1,4,1)
colormap('hot');
set(gca,'fontsize',18)
imagesc(D(:,4))
set(gca,'xticklabel',[])
set(gca, 'CLim', [0, 100]);     % Para que los colores vayan de 0 a 100.
ylabel('P0_{ini} [%]')
title('Partido A')

yticklabels = 90:-10:10;
yticks = linspace(1, size(D, 1), numel(yticklabels));
set(gca, 'YTick', yticks, 'YTickLabel', flipud(yticklabels(:)))

subplot(1,4,2)
set(gca,'fontsize',18)
imagesc(D(:,5))
set(gca,'xticklabel',[])
set(gca,'yticklabel',[])
set(gca, 'CLim', [0, 100]);     % Para que los colores vayan de 0 a 100.
title('Partido B')
set(gca, 'YTick', yticks, 'YTickLabel', flipud(yticklabels(:)))


subplot(1,4,3)
set(gca,'fontsize',18)
imagesc(D(:,6))
set(gca,'xticklabel',[])
set(gca, 'CLim', [0, 100]);     % Para que los colores vayan de 0 a 100.
title('Sin definir')
set(gca, 'YTick', yticks, 'YTickLabel', flipud(yticklabels(:)))


set(gca, 'CLim', [0, 100]);
h=colorbar;
set(h, 'Position', [.7514 .11 .0581 .8150],'fontsize',18)