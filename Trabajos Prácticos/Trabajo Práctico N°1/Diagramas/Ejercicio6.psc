Algoritmo Ejercicio6
	Definir Valor_1,n,suma_1 Como Real
	n <- 1
	Escribir 'Ingrese un valor: '
	Leer Valor_1
	Repetir
		Escribir n
		n <- (n*10)+1
		suma_1 <- n
	Hasta Que n > Valor_1
	Escribir 'El valor de la sumatoria de la serie es: ',suma_1
FinAlgoritmo
