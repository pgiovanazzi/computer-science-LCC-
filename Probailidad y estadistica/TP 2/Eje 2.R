fumadores <- c(69.3, 56.0, 22.1, 47.6, 53.2, 48.1, 52.7, 34.4, 60.2, 43.8, 23.2, 13.8)
noFumadores <- c(28.6, 25.1, 26.4, 34.9, 29.8, 28.4, 38.5, 30.2, 30.6, 31.8, 41.6, 21.1, 36.0, 37.9, 13.9)
fumadores <- sort(fumadores)
noFumadores <- sort(noFumadores)
# a)
  # media de fumadores
  mean(fumadores)
  # media de no fumadores
  mean(noFumadores)
# b)
  # desviasion estandar de fumadores
  sd(fumadores)
  # desviasion estandar de noFumadores
  sd(noFumadores)
# c)
  tabla <- data.frame(cbind(fumadores,noFumadores))
  tabla
  boxplot(tabla)
# d)
  # Los la media de los fumadores aproximadamente tardan en dormirse 10 minutos mas que la media de los
  # no fumadores. Ademas los fumadores tiene una variacion de tiempo mas disperso con respecto a la media, mientras
  # que los no fumadores que tienen menos variacion de tiempo al dormirce con respecto a la media.