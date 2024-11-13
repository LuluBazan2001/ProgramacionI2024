/*Dada la siguiente estructura:
Cod.Producto
Detalle
Precio
Stock
Ubicación
Ingresar 15 productos y guardarlos en un vector. Generar un segundo vector con los
productos ordenados por cod.Producto.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define f (3)

struct productos{
	int codigo;
	char detalle[30];
	float precio;
	int stock;
	char ubicacion[30];
}pro[f], pro2[f]; 

void agregar(struct productos pro[]);
void copiar(struct productos pro[]);
void ordenar(struct productos pro2[]);
void visualizar(struct productos pro2[]);

main(){
	
	int opcion, repeticion = 1;
	struct productos pro[f];
	struct productos pro2[f];
	
	do{
		
	printf ("\n\n\n\t\t ***** BIENVENIDOS AL PROGRAMA *****");
	printf ("\n\n\t\t ------------------------------------");
	printf ("\n\n\t\t * 1- Cargar Productos");
	printf ("\n\n\t\t * 2- Ordenar Productos por Codigo");
	printf ("\n\n\t\t * 3- Visualizar Productos Ordenados");
	printf ("\n\n\t\t * 4- Salir");
	printf ("\n\n\t\t ------------------------------------");
	printf ("\n\n\t\t * Opcion: ");
	scanf ("%d", &opcion);
	
	system ("cls");
	
	switch(opcion){
		case 1: agregar(pro); copiar(pro); break;
		case 2: ordenar(pro2); break;
		case 3: visualizar(pro2); break;
		case 4: printf ("\n\n\t\t ***** GRACIAS POR USAR NUESTRO PROGRAMA *****");
		        repeticion = 0; break;
		default: printf ("\n\n\t\t ***** INGRESO INCORRECTAMENTE *****");
	}
	
	}while(repeticion == 1);

    return 0;
	
}

	void agregar(struct productos pro[]){
		
	int fila;
		
	for (fila = 0; fila < f; fila++){

			printf ("\n\n\t\t * Ingrese los siguientes datos del Producto N: %d *", fila+1);
			printf ("\n\n\t\t --------------------------------------------------");
			
			printf ("\n\n\t\t * Codigo del Producto: ");
			fflush(stdin);
			scanf ("%d", &pro[fila].codigo);	
					
			printf ("\n\t\t * Detalle del Producto: ");
			fflush(stdin);
			gets(pro[fila].detalle);
						
			printf ("\n\t\t * Precio del Producto: %c" ,36 );
			fflush(stdin);
			scanf ("%f", &pro[fila].precio);
						
			printf ("\n\t\t * Stock del Producto: ");
			fflush(stdin);
			scanf ("%d", &pro[fila].stock);		
				
			printf ("\n\t\t * Ubicacion del Producto: ");
			fflush(stdin);
			gets(pro[fila].ubicacion);
			
			system("pause>null");
			system("cls");
		}
    }

void copiar(struct productos pro[]){
	
	int fila,col;
	
	for (fila = 0; fila < f; fila++){
			pro2[fila].codigo = pro[fila].codigo;			
			strcpy(pro2[fila].detalle, pro[fila].detalle);			
			pro2[fila].precio = pro[fila].precio;			
			pro2[fila].stock = pro[fila].stock;			
			strcpy(pro2[fila].ubicacion, pro[fila].ubicacion);			
		}
	}

void ordenar(struct productos pro[]){
	
	int fila, pasada;
	int interruptor = 1;
	int aux1, aux4;
	float aux3;
	char aux2[50], aux5[50];
	
	for (pasada = 1; pasada < f; pasada++){
		
		interruptor = 0;
		
		for (fila = f-1; fila >= pasada; fila--){
			
			if (pro2[fila-1].codigo > pro2[fila].codigo){
				
				aux1 = pro2[fila-1].codigo;
				pro2[fila-1].codigo = pro2[fila].codigo;
				pro2[fila].codigo = aux1;
				
				strcpy(aux2, pro2[fila-1].detalle);
				strcpy(pro2[fila-1].detalle, pro2[fila].detalle);
				strcpy(pro2[fila].detalle, aux2);
				
				aux3 = pro2[fila-1].precio;
				pro2[fila-1].precio = pro2[fila].precio;
				pro2[fila].precio = aux3;
				
				aux4 = pro2[fila-1].stock;
				pro2[fila-1].stock = pro2[fila].stock;
				pro2[fila].stock = aux4;
				
				strcpy(aux5, pro2[fila-1].ubicacion);
				strcpy(pro2[fila-1].ubicacion, pro2[fila].ubicacion);
				strcpy(pro2[fila].ubicacion, aux5);
				
			}
		}
	}
	
	printf ("\n\n\n\t\t ***** PRODUCTOS ORDENADOS *****");
			
}

void visualizar(struct productos pro[]){
	
	int fila;

	for (fila = 0; fila < f; fila++){
		
		printf ("\n\t\t * PRODUCTO N: %d", fila+1);
		printf ("\n\t\t ----------------------------");
		printf ("\n\n\t\t * Codigo: %d", pro2[fila].codigo);
		printf ("\n\t\t * Detalle: ");puts(pro2[fila].detalle);
		printf ("\n\t\t * Precio: %c %0.2f", 36, pro2[fila].precio);
		printf ("\n\t\t * Stock: %d", pro2[fila].stock);
		printf ("\n\t\t * Ubicacion: ");puts(pro2[fila].ubicacion);
		printf ("\n\t\t ----------------------------");
		
	}
	
	system("pause>null");
	system("cls");
}
