/*Realizar un programa que luego de ingresar una palabra, se genere una palabra nueva
con todas las letras de la primera pero sin repetir las letras. (Ejem. CATAMARCA –
CATMR). Una vez realizado, ver cuantas veces se repiten las letras de esta, en una
segunda palabra ingresada (Ejem. CATMR – CORDOBA /
C=1,A=1,T=0,M=0,R=1). Considere el ingreso de 10 pares de palabras.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int verificalongitud(char*ppalabra)
{
	int resultadofinal;
	resultadofinal=strlen(ppalabra);
	return resultadofinal;
}
main(){
	//char ppalabra[50];
	//char letra[30]="";
	int i,slongitud,longitud,p=1,l=1,a,repite=0;

	for(i=0;i<=10;i++)
	{
    	char letra[30]="",ppalabra[50]="";
		system("cls");
		printf("\n\tIngresar la 1era palabra:  ");
		fflush(stdin);
		scanf("%s",ppalabra);
		longitud=verificalongitud(ppalabra);
		//primera letra
		letra[0]=ppalabra[0];
    	printf("\tLa palabra sin repetir letras es:%c",ppalabra[0]);
    	for(p=1;p<longitud;p++)
		{
        	//solo muestra la palabra sin repetir letras
			for(a=0;a<p;a++)
			{
            	//muestra la palabra repitiendo todo
				if (ppalabra[p]==ppalabra[a])
				{
					repite++;
				}

        	}
        	//con la muestra anterior corta la palabra para que repita una sola vez
			//las letras
    		if(repite==0)
			{
            	printf("%c",ppalabra[p]);
            	letra[l]=ppalabra[p]; l++;
    		}
    		repite=0;
    	}
    	fflush(stdin);
    	printf("\n\tIngresar la segunda palabra: ");
    	scanf("%s",ppalabra);
    	fflush(stdin);
    	longitud=verificalongitud(letra);
   		slongitud=verificalongitud(ppalabra);
    	for(l=0;l<longitud;l++)
		{
        	//verifica cuantas letras hay comparado a la 2da palabra
			for(a=0;a<slongitud;a++)
			{
            	if (letra[l]==ppalabra[a]) repite++;
        	}
    		printf("\n\t%c=%d\n",letra[l],repite);
    		repite=0;

    	}
    	system("PAUSE");
		fflush(stdin);
	}

}
