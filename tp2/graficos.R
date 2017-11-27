require(plyr)
require(ggplot2)
resultados <- read.csv("~/facu/sed_2017/sed_2017_tps/tp2/dat/resultados.csv",
                       header = FALSE)
names(resultados) = c('experimento','trial', 'A', 'I','B')


res = melt(resultados)
names(res) = c('experimento','trial', 'Partido', "Cantidad")

qplot(data=res, x=Partido, y=Cantidad, geom=c('boxplot','jitter'), facets = '~ experimento') + 
  ggtitle("Whisker-and-box plot de resultados")  + theme_grey(base_size = 18) + 
  facet_wrap(facets=' experimento', nrow = 3)
ggsave("/home/danito/facu/sed_2017/sed_2017_tps/tp2/informe/imagenes/histograma_resultados.png")
qplot(data=res, x=Partido, y=Cantidad,
      geom=c('violin', 'jitter'),
      draw_quantiles = c(0.25, 0.5, 0.75),
      fill=Partido) + ggtitle("Violin plot de resultados") + 
  theme_grey(base_size = 18) + facet_wrap(facets=' experimento', nrow = 3)
ggsave("/home/danito/facu/sed_2017/sed_2017_tps/tp2/informe/imagenes/violin_resultados.png")
