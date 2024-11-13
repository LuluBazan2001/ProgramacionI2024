/*Realizar un programa que ingresado n cantidad de precios, 
calcule sobre estos, un aumento del 20% para aquellos 
menores de 60 pesos, 15% menores a 100 pesos y 10% para 
el resto. Mostrar el precio actualizado como así también el 
aumento aplicado y el porcentaje que se aplicó. Todos los 
cálculos hacerlos dentro de un procedimiento. Para realizar este 
ejercicio utilice su propia librería.*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

float calculoprecio(float *precio,float *Aumento,float *aumentodelprecio)
{
    
    if(*precio<60)
    {
        *Aumento=(*precio*0.2);
        *aumentodelprecio=((*precio*120)/100);

    }
    if(*precio < 100 && *precio >=60)
    {
    *Aumento=(*precio*0.15);
    *aumentodelprecio=((*precio*115)/100);

    }
    if (*precio>=100)
	{
	*Aumento=(*precio*0.1);
	*aumentodelprecio=((*precio*110)/100);
    }
    return(*Aumento,*aumentodelprecio);
}

int main()
{
    float precio=0;
    char desea='s';
    float Aumento,aumentodelprecio;
    do{
    printf("Ingrese el precio:\n");
    scanf("%f", &precio);
    calculoprecio(&precio,&Aumento,&aumentodelprecio);

    printf("\nEl precio actualizado es: $%5.2f\n",aumentodelprecio);
    printf("\nEL aumento que se aplico fue del 20%%\n");
    printf("\nEl aumento que se genero es de: $%5.2f\n",Aumento);

    scanf("%c", &desea);
    printf("\nPara ingresar otro precio digite (s), de lo contario, si digita (n) el programa cierra:\n");

    scanf("%c", &desea);
    system("cls");
    }while(desea=='s' || desea=='S');
    return 0;
}
