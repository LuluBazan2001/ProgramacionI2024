/*Programar el siguiente juego: Un usuario ingresa un n�mero entre 1 y 10. Otro usuario
tiene 3 intentos para dar con ese n�mero. Como pista por pantalla se muestra cada
vez que ingresa un n�mero si es mayor o menor. Si acierta felicitar al jugador de lo
contrario comunicarle el fracaso. Dar la opci�n de volver a jugar*/

#include<stdio.h>
#include <stdlib.h>

int main(){
	int minimo,maximo,numeroPrueba,numeroDefinido,repeticion;
	minimo=1;
	maximo=10;
	char VolverJugar;
	
	do 
	{
		do 
		{
		printf("ingresar numero a adivinar:\n");
		scanf("%d",&numeroDefinido);		
		}while ((numeroDefinido<minimo)||(numeroDefinido>maximo));
		
		system("cls");
		
		for (repeticion=1;repeticion<=3;repeticion+=1) 
		{
		printf("Ingrese otro numero tratando de acertar el definido:\n");
		fflush(stdin);
		scanf("%d",&numeroPrueba);
		
		if (numeroPrueba!=numeroDefinido) 
		{
			if (numeroPrueba>numeroDefinido)
			{
				printf("el numero que ingresaste es mayor que el numero definido\n");
			} 
			else
			{
				printf("el numero que ingresaste es menor que el numero definido\n");
			}
		}
		else 
		{
		printf("Felicidades!! Acertaste al numero definido!!\n");
		break;	
		}
		}
		printf("Desea volver a jugar?\n");
		fflush(stdin);
		scanf("%c",&VolverJugar);
	}while (VolverJugar!='n');
	return 0;
}
