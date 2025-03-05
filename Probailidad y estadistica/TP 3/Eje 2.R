# a)
  x = 1:10000

  sumDados = function(x){
    dados = sample(1:6,4,rep = T)
    # print(dados)
    sum(dados)
  }
  
  set.seed(111)
  t <- sapply(x, sumDados)

# b)
  tabla = table(t)
  tabla

# c)
  plot(tabla)
  barplot(tabla)