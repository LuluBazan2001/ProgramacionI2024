/*El precio de una pizza depende de su tamaño según la siguiente tabla:
TAMAÑO      PRECIO
1           $500
2           $800
3           $1200
Cada ingrediente adicional cuesta $100. 
Escriba un programa que lea el tamaño de la pizza y el número de ingredientes 
adicionales y muestre el precio que debe pagar y la forma de pago.
Si la cuenta es menor a $700 pago en efectivo. Sinó, si es de $700 hasta $1000 
pagara con el celular (dinero electrónico). Pero si es mayor a 1000 hasta $1500, 
usara la tarjeta de débito. Caso contrario, pagara con la tarjeta de crédito.*/

#include <stdio.h>

int main()
{
	int opcion1,opcion2,cant_ingredientes,preciofinal=0,preciopizz1=500,preciopizz2=800,preciopizz3=1200,ingred_adic=100;
	do
	{
		printf("Bienvenido al programa de venta de pizzas, ingrese el tama%co de la pizza que quiere a continuaci%cn: 1(Pizza chica $500), 2 (Pizza mediana $800),3 (Pizza grande $1200)\n",164,162);
		scanf("%d",&opcion1);
		if(opcion1<1 or opcion1>3)
		printf("ERROR Ingrese un numero v%clido\n",160);
	}while(opcion1<1 or opcion1>3);
	
	switch(opcion1)
	{
		case 1: preciofinal=preciofinal+preciopizz1; printf("Precio total: \t$%d",preciofinal);
		break;
		case 2: preciofinal=preciofinal+preciopizz2; printf("Precio total: \t$%d",preciofinal);
		break;
		case 3: preciofinal=preciofinal+preciopizz3; printf("Precio total: \t$%d",preciofinal);
		break;
	default: printf("\n ERROR fuera de rango.");
	return 0;
	}
	printf("\nPerfecto, ahora ingrese la cantidad de ingredientes adicionales ingresados\n");
	scanf("%d",&cant_ingredientes);
	preciofinal=preciofinal+(ingred_adic*cant_ingredientes);
	if(preciofinal<=700)
	opcion2=1;
	else
		if(preciofinal<=1000)
		opcion2=2;
		else
			if(preciofinal<=1500)
			opcion2=3;
			else
			opcion2=4;
	switch(opcion2)
	{
		case 1: printf("El monto a pagar es de: $%d y la forma de pago es en efectivo",preciofinal);
		break;
		case 2: printf("El monto a pagar es de: $%d y la forma de pago es con dinero electronico(Telefono)",preciofinal);
		break;
		case 3: printf("El monto a pagar es de: $%d y la forma de pago es con tarjeta de debito",preciofinal);
		break;
		case 4: printf("El monto a pagar es de: $%d y la forma de pago es con tarjeta de credito",preciofinal);
		break;
	default: printf("\n ERROR fuera de rango.");
	return 0;
	}
}

