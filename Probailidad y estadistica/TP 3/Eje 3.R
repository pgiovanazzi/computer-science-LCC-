bolas = c(1,1,1,0,0,0,0,0)

# a)
  unaExtraccion = sample(bolas, 1)
  unaExtraccion
  
  # otra forma de hacerlo seria:
  unaExtraccion_v2 = sample(c(1,0), 1, prob = c(3/8,5/8)) # prob asigna a 1, la probabilidad de 3/8 y a 0, 5/8.
  unaExtraccion_v2
  
# b)
  ochoExtracciones = sample(bolas, 8, rep = T)
  ochoExtracciones

# c)
  # Retorna la cantidad de bolas negras de 30 extracciones
  set.seed(111) # Setea la semilla
  bolasNegras30ext = function(x){
                        30 - sum(sample(bolas, 30, rep = T))
                     }
  
  # Aplica la funcion a cada elemento del arreglo de 1 a 10000
  listBolasNegras10000de30ext = sapply(1:10000, bolasNegras30ext)
  table(listBolasNegras10000de30ext)
  plot(listBolasNegras10000de30ext)
  