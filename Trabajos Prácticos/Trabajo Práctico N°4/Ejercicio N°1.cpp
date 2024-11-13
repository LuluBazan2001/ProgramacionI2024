/*Realizar un cuento interactivo al estilo “Elije tu Propia Aventura”. Al final de cada párrafo
el lector podrá elegir entre 2 o más opciones. El cuento podrá tener 1 o más finales (mismo
Práctico 1) Mientras que se vaya creando un registro (.log) en un archivo los textos y las
opciones ingresadas. Dar la posibilidad de mostrar ese archivo*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void parte1selec(int opcion1);
char opcombo(char opcombo);
char opindiv(char indiv);
void impcuento();

main(){

	char opcion1,opcombo1,indiv;
	impcuento();
   	printf("\n*************************************");
	printf("\n*       PARQUE DE DIVERSIONES       *");
   	printf("\n*************************************");
   	printf("\n* 1)COMBOS            2)JUEGO INDIV *");
   	printf("\n* 3)FINALIZAR                       *");
   	printf("\n*************************************");
   	printf("\n");
   	fflush(stdin);
   	scanf("\n* Elige Opcion: %i                  *",opcion1);
   	parte1selec(opcion1);
   	switch(opcion1)
	{
   		case'1':
   			system("cls");
   			opcombo(opcombo1);


	   	case'2':
	   		system("cls");
	   		opindiv(indiv);


	   	case'3':
		   break;
	}
   	system("pause>null");
}


void parte1selec(int opcion){

	FILE*cuento;
cuento=fopen("cuento.log","at");
   	if(opcion=='1'){
   		fprintf(cuento,"Selecciono la opcion 1");
	} if (opcion == '2'){
	   	fprintf(cuento,"Selecciono la opcion 2");
	}
	fclose(cuento);

}

char opcombo(char opcombo1){

	FILE *cuento;
    cuento= fopen("cuento.log","at+");
   	printf("\n\n*******************************************************");
	printf("\n*       			PARQUE DE DIVERSIONES		        *");
   	printf("\n*******************************************************");
   	printf("\n* 1)Montaña Rusa+Parque Acuatico       *  1)	$80		*");
	printf("\n* 2)La Casa del Terror+Montaña Rusa    *  2)  $50     *");
   	printf("\n* 3)Autos Chocadores+Parque Acuatico   *  3)  $40     *");
   	printf("\n* 4)Parque Acuatico+La Casa del Terror *  4)  $40     *");
   	printf("\n* 5)Combo 4 Juegos                     *  5)  $140    *");
   	printf("\n*******************************************************");
   	fflush(stdin);
   	scanf("\n* Elige Opcion: %c                                    *",opcombo1);
   	printf("\n*******************************************************");
   	printf("\n");
   	if(opcombo1=='a'){
   		fprintf(cuento,"Selecciono la opcion combos");
	   } if (opcombo1 == 'b'){
	   	fprintf(cuento,"Selecciono la opcion Juego Individual");
	   }
   	return(opcombo1);
	fclose(cuento);

}

char opindiv(char indiv){

	FILE *cuento;
    cuento= fopen("cuento.log","at+");
   	printf("\n\n*******************************************************");
	printf("\n*       			PARQUE DE DIVERSIONES		        *");
   	printf("\n*******************************************************");
   	printf("\n* 1)Montaña Rusa				       	 *  1)	$60		*");
	printf("\n* 2)La Casa del Terror				 *  2)  $60     *");
   	printf("\n* 3)Autos Chocadores				     *  3)  $30     *");
   	printf("\n* 4)Parque Acuatico					 *  4)  $30     *");
   	printf("\n*******************************************************");
   	scanf("\n* Elige Opcion: %c                                    *",indiv);
   	printf("\n*******************************************************");
   	printf("\n");
   	return(indiv);
	fclose(cuento);

}

void impcuento(){

	int opcion1;
	FILE *cuento;
    cuento= fopen("cuento.log","wt");
    fprintf(cuento,"\n********************************************************************************************\n");
    fprintf(cuento,"\n Habia una vez un parque al que iban muchos ninos a jugar.");
	fprintf(cuento,"\n Aquel parque era fantastico. Era muy grande y tenia muchisimas atracciones.");
    fprintf(cuento,"\n Un joven asiste a aquel parque, entusiasmado por querer jugar.");
    fprintf(cuento,"\n Al llegar, y observar la cantidad de juegos que poseia el parque,");
    fprintf(cuento,"\n No vio las horas de poder subirse a alguno de los juegos.");
    fprintf(cuento,"\n");
    fprintf(cuento,"\n Se acerco a la boleteria,");
	fprintf(cuento,"\n Donde le preguntaron si deseaba comprar combos con descuentos incluidos (Opcion 1),");
    fprintf(cuento,"\n O bien, pagar de manera individual alguno de los juegos,");
	fprintf(cuento,"\n Porque solo deseaba subirse a uno de todos ellos (Opcion 2)");
    fprintf(cuento,"\n\n******************************************************************************************\n");
    fprintf(cuento,"\n");
    system("pause>null");
    system("cls");
	fclose(cuento);
}
