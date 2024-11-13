Algoritmo sin_titulo
	Definir Nombre,Apellido Como Caracter
	Definir Repeticion,DiaNacimiento,MesNacimiento,AnioNacimiento,DiaActual,MesActual,AnioActual,EdadPersona Como Entero
	Escribir 'Ingresar dia actual[1-31]'
	Leer DiaActual
	Escribir 'Ingresar mes actual [1-12]'
	Leer MesActual
	Escribir 'ingresar año actual:'
	Leer AnioActual
	Para Repeticion<-1 Hasta 15 Hacer
		Escribir 'Ingresar nombre:'
		Leer Nombre
		Escribir 'Ingresar apellido:'
		Leer Apellido
		Escribir 'ingresar dia de nacimiento[1-31]:'
		Leer DiaNacimiento
		Escribir 'ingresar mes de nacimiento[1-12]:'
		Leer MesNacimiento
		Escribir 'ingresar año de nacimiento:'
		Leer AnioNacimiento
		EdadPersona <- AnioActual-AnioNacimiento
		Si MesActual<MesNacimiento Entonces
			EdadPersona = EdadPersona-1
		FinSi
		Si MesActual=MesNacimiento Entonces
			Si DiaActual<DiaNacimiento Entonces
				EdadPersona = EdadPersona-1
			FinSi
		FinSi
		Si EdadPersona>=18 Entonces
			Escribir "Su nombre es:",Nombre
			Escribir "Su Apellido es:",Apellido
			Escribir "Su edad es:",EdadPersona
		FinSi
	FinPara
FinAlgoritmo
