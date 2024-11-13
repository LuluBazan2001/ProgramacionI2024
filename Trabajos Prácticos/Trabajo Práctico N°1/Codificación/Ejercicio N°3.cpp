/*Ingresar nombre, apellido y fecha de nacimiento para 15 personas. Mostrar por
pantalla solo los nombres, apellidos y edades de las personas mayores de edad.*/

#include<stdio.h>

int main(){
	char nombre[50];
	char apellido[50];
	int repeticion,diaNacimiento,mesNacimiento,anioNacimiento,diaActual,mesActual,anioActual,edadPersona;
	
	printf("Ingresar dia actual[1-31]:\n");
	scanf("%d",&diaActual);
	printf("Ingresar mes actual[1-12]:\n");
	scanf("%d",&mesActual);
	printf("Ingresar anio actual:\n");
	scanf("%d",&anioActual);
	
	for(repeticion=0;repeticion<=15;repeticion+=1)
	{
		printf("Ingresa tu nombre:\n");
		scanf("%s",nombre);
		printf("Ingresa tu apellido:\n");
		scanf("%s",apellido);
		printf("Ingresa tu dia de nacimiento [1-31]:\n");
		scanf("%d",&diaNacimiento);
		printf("Ingresa tu mes de nacimiento[1-12]:\n");
		scanf("%d",&mesNacimiento);
		printf("Ingresa anio de nacimiento:\n");
		scanf("%d",&anioNacimiento);
		
		edadPersona=anioActual-anioNacimiento;
		
		if (mesActual<mesNacimiento)
		{
			edadPersona=edadPersona-1;
		}
		if (mesActual=mesNacimiento)
		{
			if(diaActual<diaNacimiento)
			{
				edadPersona=edadPersona;
			}
		}
		if(edadPersona>=18)
		{
			printf("su nombre es:%s\n",nombre);
			printf("su apellido es::%s\n",apellido);
			printf("su edad es:%d\n",edadPersona);
		}	
	}
		
	return 0;
}
