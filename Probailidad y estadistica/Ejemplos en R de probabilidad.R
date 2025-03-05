moneda = c(0,1)
prob = sample(moneda,1000,replace = TRUE) # Toma 1 y 0 1000 veces aleatoriamente
tabla <- table(prob)
tabla
mean(prob) # Aproximadamente 0.5 que seria la probabilidad de que sea 1 o 0
