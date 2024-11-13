Algoritmo sin_titulo
	Definir minimo,maximo,numeroDefinido,numeroPrueba,repeticion Como Entero
	minimo <- 1
	maximo <- 10
	Definir VolverJugar Como Caracter
	Repetir
		Repetir
			Escribir 'Ingresar numero a adivinar:'
			Leer numeroDefinido
		Hasta Que (numeroDefinido>minimo) Y (numeroDefinido<maximo)
		Para repeticion<-1 Hasta 3 Hacer
			Escribir 'Ingrese otro numero tratando de acertar el definido:'
			Leer numeroPrueba
			Si numeroPrueba=numeroDefinido Entonces
				Escribir 'Felicidades!! Acertaste!!'
			SiNo
				Si numeroPrueba>numeroDefinido Entonces
					Escribir 'El numero que ingresaste es mayor que el numero definido'
				SiNo
					Escribir 'El numero que ingresaste es menor al numero definido'
				FinSi
			FinSi
		FinPara
		Escribir 'Desea volver a jugar?'
		Leer VolverJugar
	Hasta Que VolverJugar='No'
FinAlgoritmo
