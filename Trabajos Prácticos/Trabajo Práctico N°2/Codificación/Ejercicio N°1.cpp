/*Escriba una función cuyo parámetro de entrada sea un entero 
positivo y retorne 1 si es primo y 0 en caso contrario. Mostrar 
en el cuerpo principal del programa si es primo o no. Realizar 
esto n veces.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int envioparametros(int NumIngresado)
{
	int Contador,i,RetornoParametro;
	Contador=0;
	for (i=1;i<=NumIngresado;i++)
	{
		if (NumIngresado%i==0)
		{
			Contador++;
		}
	}
	if (Contador==2)
	{
		RetornoParametro=1;
	}
	else
	{
		RetornoParametro=0;
	}
	return(RetornoParametro);
}

 main (){
	int Numero,i;
	char ingreso;
	
	do
	{
		system("cls");
		
		printf("Ingrese un numero: ");
		scanf("%d",&Numero);
		printf("\n***********************");
		printf("\n*  RETORNO DE VALOR   *");
		printf("\n***********************");
		printf("\n*  Es Primo = 1       *");
		printf("\n*  No es Primo = 0    *");
		printf("\n***********************");
		printf("\n*  Retorno Final = %d *",envioparametros(Numero));
		printf("\n***********************");
		
		printf("\nDesea ingresar otro numero? s/n\n");
		fflush(stdin);
		scanf("%c",&ingreso);	
	} while (ingreso!='n');
	
	return 0;
}
