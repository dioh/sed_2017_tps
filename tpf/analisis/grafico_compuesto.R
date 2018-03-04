wagerate = read.csv("/home/danito/facu/sed_2017/sed_2017_tps/tpf/analisis/wagerate.csv")
wagerate$X <- NULL
View(wagerate)

require(ggpubr)
require(ggplot2)
require(plyr)
require(data.table)
require(reshape2)

qplot(data=wagerate, x=t, y=wagerate)

qplot(data=wagerate, t)

fuga = function(fugados, a=250, b=250, i=500){
  variacion = floor(runif(1, -10, 10))
  return(data.frame(A=a + fugados, B=b + variacion, I= max(i - fugados - variacion, 0)))
}


df = ldply(seq(1, 250, 5), fuga)
df$t = 1:nrow(df)

df = melt(df, id.var="t")
wage = rbind(melt(wagerate, id.var="t"))


p1 =ggplot(data=wage) + geom_point(aes(x=t, y=value, color=variable))
p2 =ggplot(data=df) + geom_col(aes(x=t, y=value,
                                   fill=variable), position="dodge") + 
  scale_fill_brewer(palette = "Spectral") + facet_wrap( ~ variable, nrow = 3)

ggarrange(p1, p2, nrow=2)

names(df) <- c('t', 'variable.cell', 'value.cell')
df$value.goodw = df$variable.goodw <- NA
names(wage) <- c('t', 'variable.goodw', 'value.goodw')
wage$variable.cell = wage$value.cell = NA

rbind(df, wage)


p1 =ggplot(data=rbind(df, wage)) + 
  geom_point(aes(x=t, y=value.goodw, color=variable.goodw)) + 
  geom_col( aes(x=t, y=value.cell, fill=variable.cell), 
            position="dodge") + 
  scale_fill_brewer(palette = "Spectral") + 
  facet_wrap( ~ variable.cell, nrow = 4, scale="free")

