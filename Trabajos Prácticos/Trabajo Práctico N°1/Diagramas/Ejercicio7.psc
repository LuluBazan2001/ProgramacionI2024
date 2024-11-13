Algoritmo Ejercicio7
	definir opcion_, precpizza_1, precpizza_2, precpizza_3, ingredientes como entero
	ingredientes = 100
	precpizza_1 = 500
	precpizza_2 = 800
	precpizza_3 = 1200
	Repetir
		Escribir "Hola, que tamaño de pizza desea 1, 2 o 3?"
		Leer opcion_
	Hasta Que opcion_ <= 3
	Si opcion_ = 1 Entonces
		precio_final = precpizza_1
	SiNo
		Si opcion_ = 2 Entonces
			precio_final = precpizza_2
		SiNo
			Si opcion_ = 3 Entonces
				precio_final = precpizza_3
			FinSi
		FinSi
	FinSi
	Escribir "Genial!!, ahora ingresa la cantidad de ingrediente que le quieres añadir: "
	Leer cantidad_ing
	precio_final = precio_final + (ingredientes* cantidad_ing)
	Si precio_final > 700 Entonces
		Si precio_final >= 700 y precio_final <=1000 Entonces
			Si precio_final > 1000 Entonces
				Escribir "El monto a pagar es de $" precio_final " por lo cual debera abonar mediante tarjeta de debito/credito"
			SiNo
				Escribir "El monto a pagar es de $" precio_final " por ende debera abonar mediante tarjeta de debito/credito"
			FinSi
		SiNo
			Escribir "El monto a pagar es de $" precio_final " lo cual debera abonar por celular (dinero electronico)"
		FinSi
	SiNo
		Escribir "El precio final es $" precio_final " lo cual tiene que pagar en efectivo"
	FinSi
FinAlgoritmo