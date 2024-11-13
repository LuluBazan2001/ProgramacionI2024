SubAlgoritmo num_primo(numer por referencia)
	Definir contador,i Como Entero
	contador <- 0
	Para i<-1 Hasta numer Hacer
		Si numer MOD i=0 Entonces
			contador <- contador+1 // contara las veces que el resto de la vision de 0 hasta el num ingresado 
		FinSi
	FinPara
	Si contador=2 Entonces // la cantidad de veces que el resto da 0 son dos veces 
		numer <- 1
	SiNo
		numer <- 2
	FinSi
FinSubAlgoritmo

Algoritmo primo
	Definir num,rtdo Como Entero
	Escribir 'Ingresando s sale del algoritmo'
	Escribir 'Ingrese un numero entero positivo'
	Repetir
		Leer num
		Si num>1 Entonces
			num_primo(num)
		SiNo
			Escribir 'Numero ingresado incorrecto'
		FinSi
		Si num=1 Entonces
			Escribir 'El numero es primo'
		SiNo
			Escribir 'El nunmero no es primo'
		FinSi
	Hasta Que num=0
FinAlgoritmo
