SubAlgoritmo valorobtenido <- euro (precio,retencion)
	
	Definir valorobtenido, cotizacion como Real
	Escribir "Ingrese la cotizacion del EURO"
	Leer cotizacion
	valorobtenido= precio*cotizacion
	
	Si valorobtenido>10000 Entonces
		valorobtenido = valorobtenido-(valorobtenido*retencion)/100
	FinSi
	
Fin SubAlgoritmo

SubAlgoritmo valorobtenido <- dolar (precio por valor,retencion por valor)
	
	Definir valorobtenido, cotizacion como Real
	Escribir "Ingrese la cotizacion del DOLAR"
	Leer cotizacion
	valorobtenido= precio*cotizacion
	
	Si valorobtenido>10000 Entonces
		valorobtenido = valorobtenido-(valorobtenido*retencion)/100
	FinSi
	
Fin SubAlgoritmo

SubAlgoritmo valorobtenido <- eal (precio por valor,retencion por valor)
	
	Definir valorobtenido, cotizacion como Real
	Escribir "Ingrese la cotizacion del REAL"
	Leer cotizacion
	valorobtenido= precio*cotizacion
	
	Si valorobtenido>10000 Entonces
		valorobtenido = valorobtenido-(valorobtenido*retencion)/100
	FinSi
	
Fin SubAlgoritmo

SubAlgoritmo valorobtenido <- yen (precio por valor,retencion por valor)
	
	Definir valorobtenido, cotizacion como Real
	Escribir "Ingrese la cotizacion del YEN"
	Leer cotizacion
	valorobtenido= precio*cotizacion
	
	Si valorobtenido>10000 Entonces
		valorobtenido = valorobtenido-(valorobtenido*retencion)/100
	FinSi
	
Fin SubAlgoritmo

SubAlgoritmo valorobtenido <- yuan (precio por valor,retencion por valor)
	
	Definir valorobtenido, cotizacion como Real
	Escribir "Ingrese la cotizacion del YUAN"
	Leer cotizacion
	valorobtenido= precio*cotizacion
	
	Si valorobtenido>10000 Entonces
		valorobtenido = valorobtenido-(valorobtenido*retencion)/100
	FinSi
	
Fin SubAlgoritmo

SubAlgoritmo valorobtenido <- librabritanica (precio por valor,retencion por valor)
	
	Definir valorobtenido, cotizacion como Real
	Escribir "Ingrese la cotizacion de la LIBRA BRITANICA"
	Leer cotizacion
	valorobtenido= precio*cotizacion
	
	Si valorobtenido>10000 Entonces
		valorobtenido = valorobtenido-(valorobtenido*retencion)/100
	FinSi
	
Fin SubAlgoritmo

SubAlgoritmo valorobtenido <- nuevosol (precio por valor,retencion por valor)
	
	Definir valorobtenido, cotizacion como Real
	Escribir "Ingrese la cotizacion del NUEVO SOL"
	Leer cotizacion
	valorobtenido= precio*cotizacion
	
	Si valorobtenido>10000 Entonces
		valorobtenido = valorobtenido-(valorobtenido*retencion)/100
	FinSi
	
Fin SubAlgoritmo



Algoritmo ConvertidorDeDivisas
	Definir precio, retencion, valoreuro, valordolar, valoreal, valoryen, valoryuan, valorlibrabritanica, valornuevosol Como Real
	Definir moneda Como Entero
	
	retencion=2

	Repetir
		Escribir '**** Para finalizar ingrese 0 ****'
		
		Escribir "**********************************"
		Escribir '****** Seleccione la moneda ******'
		Escribir '**********************************'
		Escribir '* 1)EURO        5)YUAN           *'
		Escribir '* 2)DOLAR       6)LIBRA BRITANICA*'
		Escribir '* 3)REAL        7)NUEVO SOL      *'
		Escribir '* 4)YEN                          *'
		Escribir '**********************************'
		
		Leer moneda
		
		Segun moneda hacer
			1: Escribir "Ingrese el monto a convertir"
				Leer precio
				valoreuro= euro(precio,retencion)
				Escribir "El valor es:", valoreuro, "pesos"
			2:Escribir "Ingrese el monto a convertir"
				Leer precio
				valordolar= dolar(precio,retencion)
				Escribir "El valor es:", valordolar, "pesos"
			3: Escribir "Ingrese el monto a convertir"
				Leer precio
				valoreal= eal(precio,retencion)
				Escribir "El valor es:", valoreal, "pesos"
			4: Escribir "Ingrese el monto a convertir"
				Leer precio
				valoryen= yen(precio,retencion)
				Escribir "El valor es:", valoryen, "pesos"
			5:Escribir "Ingrese el monto a convertir"
				Leer precio
				valoryuan= yuan(precio,retencion)
				Escribir "El valor es:", valoryuan, "pesos"
			6: Escribir "Ingrese el monto a convertir"
				Leer precio
				valorlibrabritanica= librabritanica(precio,retencion)
				Escribir "El valor es:", valorlibrabritanica, "pesos"
			7: Escribir "Ingrese el monto a convertir"
				Leer precio
				valornuevosol= nuevosol(precio,retencion)
				Escribir "El valor es:", valornuevosol, "pesos"
				
		FinSegun

	
	Hasta Que precio=0
	
FinAlgoritmo

