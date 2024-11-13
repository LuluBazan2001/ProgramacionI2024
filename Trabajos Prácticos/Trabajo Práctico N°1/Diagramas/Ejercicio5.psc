Algoritmo Punto5
	Definir a_quien_desea_dar_el_voto,cont_candidato1,cont_candidato2,i,cont_candidato3 Como Entero
	Definir candidato1,candidato2,candidato3 Como Caracter
	cont_candidato1 <- 0
	cont_candidato2 <- 0
	cont_candidato3 <- 0
	i <- 0
	Escribir 'Nombre del primer candidato: '
	Leer candidato1
	Escribir 'Nombre del segundo candidato: '
	Leer candidato2
	Escribir 'Nombre del tercer candidato: '
	Leer candidato3
	Mientras i<4 Hacer
		Escribir 'A quien desea dar el voto?(candidato 1, candidato 2, candidato 3) Seleccione uno: '
		Leer a_quien_desea_dar_el_voto
		Si a_quien_desea_dar_el_voto==1 Entonces
			cont_candidato1 <- cont_candidato1+1
			i <- i+1
		SiNo
			Si a_quien_desea_dar_el_voto=2 Entonces
				cont_candidato2 <- cont_candidato2+1
				i <- i+1
			SiNo
				Si a_quien_desea_dar_el_voto=3 Entonces
					cont_candidato3 <- cont_candidato3+1
					i <- i+1
				SiNo
					Escribir 'Error, vuelva a intentarlo'
				FinSi
			FinSi
		FinSi
	FinMientras
	Si cont_candidato1>cont_candidato2 Y cont_candidato1>cont_candidato3 Entonces
		Escribir 'El ganador es ',candidato1,' con la cantidad de',cont_candidato1,' voto/s'
	SiNo
		Si cont_candidato2>cont_candidato1 Y cont_candidato2>cont_candidato3 Entonces
			Escribir 'El ganador es: ',candidato2,' con la cantidad de',cont_candidato2,' voto/s'
		SiNo
			Si cont_candidato3>cont_candidato1 Y cont_candidato3>cont_candidato2 Entonces
				Escribir 'El ganador es: ',candidato3,' con la cantidad de',cont_candidato3,' voto/s'
			FinSi
		FinSi
	FinSi
FinAlgoritmo
