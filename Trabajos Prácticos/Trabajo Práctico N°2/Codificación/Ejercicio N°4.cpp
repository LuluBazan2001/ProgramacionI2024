/*Ingresado números enteros, determinar para cada uno de ellos 
si son números positivos o negativos retornando “Positivo” y 
“Negativo” respectivamente. (La función deberá retornar las 
respectivas cadenas de caracteres según sea el caso)*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *imprimir(int NumeroIng,char a[])
{
	if (NumeroIng>0)
	{
		return(a="Positivo \n");
	}
	if(NumeroIng<0)
	{
		return(a="Negativo \n");
	}
	if(NumeroIng==0)
	{
		return(a="Nulo \n");
	}
}

int main()
{
	int Numero;
	char arreglo[10],*palabra[10];
	char Repeticion;
	do {
			system("cls");
			printf("Ingrese el numero en cuestion:\n");
			scanf("%d",&Numero);
			fflush(stdin);
	
			*palabra=imprimir(Numero,arreglo);
			printf("El numero ingresado es:%s\n",*palabra);
			printf("¿Desea ingresar otro numero? s/n \n");
			scanf("%c",&Repeticion);
			fflush(stdin);
	}while(Repeticion!='n');
	return 0;
}
