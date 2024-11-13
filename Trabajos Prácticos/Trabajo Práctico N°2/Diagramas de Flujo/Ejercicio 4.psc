SubAlgoritmo ImprimirCadena <- CadenaNumero (numero)
	Definir ImprimirCadena como Caracter
	Si numero>0 Entonces
		ImprimirCadena <- 'POSITIVO'
	SiNo
		Si numero<0 Entonces
			ImprimirCadena <- 'NEGATIVO'
		SiNo
			Si numero=0 Entonces
				ImprimirCadena <- 'NULO'
			FinSi
		FinSi
	FinSi
FinSubAlgoritmo

Algoritmo Ejercicio4
	Definir CantidadNumeros,numero,Repeticion Como Entero
	Escribir 'Ingrese la cantidad de numeros a verificar'
	Leer CantidadNumeros
	Para Repeticion<-1 Hasta CantidadNumeros Hacer
		Escribir 'Ingrese el numero en cuestion: '
		Leer numero
		Escribir 'El numero ingresado es: ',CadenaNumero[numero]
	FinPara
FinAlgoritmo
