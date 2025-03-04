Compilamos primero la implementación:
-----------------
$ gcc -c SList.c
$
-----------------

Si todo anduvo bien, generó un SList.o en el directorio.

Luego, podemos compilar el archivo main.c, dándole
de nombre "main" al binario (en lugar de "a.out"),
y diciendole que tiene que pegar algunas funciones
de SList.o:
----------------------------
$ gcc -o main main.c SList.o
$
----------------------------

Ejecutamos "main" para verificar que haga lo esperado:
---------
$ ./main
3 2 1 4
$
---------
