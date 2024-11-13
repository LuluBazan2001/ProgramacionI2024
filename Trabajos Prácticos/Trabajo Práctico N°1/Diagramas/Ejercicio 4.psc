Algoritmo sin_titulo
	Definir Numero,Contador,i Como Entero
	Contador <- 0
	Repetir
		Escribir 'Ingrese un numero'
		Leer Numero
		Para i<-1 Hasta Numero Hacer
			Si Numero MOD i=0 Entonces
				Contador <- Contador+1
			FinSi
		FinPara
		Si Contador=2 Entonces
			Escribir 'Es un numero primo'
		SiNo
			Escribir 'No es un numero primo'
		FinSi
	Hasta Que Numero=0
FinAlgoritmo
