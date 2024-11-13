/*Realice un programa para obtener el resultado del escrutinio en las elecciones de 
delegados del centro de estudiantes, considerar que hay 160 electores y se han 
presentado 3 candidatos, todos votaron, el algoritmo debe declarar al ganador 
por mayoría simple*/

#include<stdio.h>

main () {
	
	int voto, votantes, contador1, contador2, contador3;
	
	for (votantes=1;votantes<=5;votantes++) {
		
		printf ("Selecione que candidato desea votar: \n");
		printf ("Candidato 1: presione 1,\n Candidato 2: presione 2,\n Candidato 3: presione 3: \n");
		printf ("......\n");
		scanf("%d",&voto);
		printf ("......\n");
		
		if (voto==1) {
			contador1=contador1+1;
		}else if (voto==2) {
			contador2=contador2+1;
		 }else if (voto==3) {
			contador3=contador3+1;
		  }else 
		     printf ("Numero Erroneo");
	}
	if (contador1>contador2 && contador1>contador3) {
		
		printf ("El primer candidato fue el ganador");
	}else if (contador2>contador1 && contador2>contador3) {
		
		printf ("El segundo candidato fue el ganador");
	}else if (contador3>contador1 && contador3>contador2) {
		
		printf ("El tercer candidato fue el ganador");
	}
}

