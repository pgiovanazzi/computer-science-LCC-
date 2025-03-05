#1 a) La variable edad es una variable de tipo cuantitativa discreta.
#b)
  edad <- c(22,22,23,24,25,25,26,27,28,29,29,29,29,29,31,31,32,33,34,35,35,35,36,38,39,39,42,42,44,44,45,45,45,47,48,52,59,66,67,69,69)
#c)
#c1- Calcula longitud.
  length(edad)
#c2- Calcula media,mediana, moda y cuartiles, respectivamente.
  mean(edad)
  median(edad)
  library("modeest")
  mlv(edad, method = "discrete") # o tambien mfv(edad)
  quantile(edad)
#c3- Calcula rango, rango intercuartílico, desviación estándar y variancia respectivamente.
  range(edad)
  IQR(edad)
  sd(edad)
  var(edad)
#c4- Calcula percentil 10 y percentil 50 respectivamente.
  quantile(edad, .10)
  quantile(edad, .50) # o bien quantile(edad, c(.10,.50))
#c5-Calcula su mínimo y máximo y cuartiles, todos mediante un único comando.
  summary(edad)
#c6- Diagrama de caja.
  boxplot(edad)
#c7- Diagrama tallo-hoja.
  stem(edad)
#c8- Histograma.
  hist(edad)
#Para agregar diagrama de barra barplot(edad) y diagrama de pastel pie(edad)
#d) 
#En c1 la funcion length calcula la cantidad de unidades de la muestra.
#En c2
  #la funcion mean calcula la media de la muestra, seria la suma de las mediciones dividido entre las n mediciones.
  #la funcion median calcula la mediana de la muestra, es el valor de la posicion media para un conjunto de n muestras que estan ordenados de menor a mayor.
  #la funcion mlv o mfv calcula la moda de una muestra, es el valor de la muestra que se observa con mas frecuencia.
  #la funcion quantile calula los cuartlines de la muestra, para un conjunto de n mediciones ordenados q1 es el valor de x que es mayor a un cuarto de las mediciones y menor que el resto, q2 es la mediana y q3 es mayor a 3/4 de las mediciones y menor que el resto.
#En c3
  #la funcion range calcula el rango de la muestra, de un conjunto de n mediciones es la diferencia de la medicion mas grande y la mas chica.
  #la funcion IQR calcula el rango intercualrtil de una muestra, para un conjunto de mediciones es la diferencia entre el cuartil superior e inferior, q3 - q1.
  #la funcion sd calcula la desviascion estandar de la muestra, basicamente es la raiz cuadrada positiva de la varianza.
  #la funcion var calcula la varianza de una muestra, de n mediciones es la suma de las desviaciones cuadradas de las mediciones alrededor de la media dividida entre n-1 o es tambien la variablilidad media de una muestra.
#c4
  #la funcion quantile con dichos parametros estaria calculando los percentiles de 10% y de 50% respectivamente.
#c5
  #la funcion summary muestra un resumen de la muestra, el valor mas chico, el cuartil inferior q1, la mediana, el cualrtil superior q3 y el valor maximo.
#c6 explicado en la carpeta, es un grafico de caja que muestra el resumen de la muestra a fin de descrivir visualmente la distribucion de los datos.
#c7 la funcion stem para una muestra, genera un grafico de tall y hoja para numeros cuantitativos. Utiliza los valores reales para cada punto de datos.
#c8 la funcion hist para una muestra, genera un grafico de histograma de frecuencia relativa para la muestra. Es un grafico de barras en que la altura de la barra muestra la frecuencia de las mediciones que caen en un subintervalo en particular (eje horizontal).