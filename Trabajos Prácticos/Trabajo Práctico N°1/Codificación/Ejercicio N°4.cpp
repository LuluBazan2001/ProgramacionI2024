/*Realice un programa donde se permita ingresar un número mayor a 1 y se determine
si ese número ingresado es primo o no. Repetir el proceso hasta que se ingrese el nro.
0 (cero)*/

#include<stdio.h>

int main(){
	int numero,i;
	int contador=0;
	
	do
	{
	
		printf("Ingrese un numero:");
		scanf("%d",&numero);
		
			for(i=1;i<=numero;i+=1)
			{
				if (numero%i==0)
				{
				contador=contador+1;
				}	
			}
			if (contador==2)
			{
				printf("Es un numero primo\n");
			}
			else
			{
				printf("No es un numero primo\n");
			}
	}while(numero!=0);
	return 0;
	
}
