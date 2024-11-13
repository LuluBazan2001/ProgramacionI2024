/*Crear una lista con números enteros permitir mostrar los elementos de la pila sin
perder los valores pasándolas a otra pila. Luego volver los elementos a su lugar
original*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nodo {
    int dato;
    struct nodo*siguiente;
}Nodo; //Declara nodos

typedef Nodo*ptrNodo;//Declara punteros a un nodo
typedef Nodo*ptrPila;//Declara pilas a un nodo

void insertarNodo(ptrPila*pila1);
void VisualizarPilas(ptrPila pila1,ptrPila pila2);
void TrasladarPila(ptrPila pila1,ptrPila pila2);
void Intercambio(ptrPila*pila2,int x);

int  main () {
    ptrPila pila1=NULL,pila2=NULL;
	int opcionMenu = 0 ;
	do {
		system("cls");
		printf ( " \n | ------------------------------------- | " );
		printf ( " \n | \t\t   ° PILA °    \t\t | " );
		printf ( " \n | ------------------ | ---------------- | " );
		printf ( " \n | 1. Insertar \t\t\t\t | " );
		printf ( " \n | 2. Visualizar ambas pilas \t\t | " );
		printf ( " \n | 3. Trasladar Elementos y Visualizar   | " );
		printf ( " \n | 4. Salir \t\t\t\t | " );
		printf ( " \n | ------------------ | ---------------- | " );
		printf ( " \n\n Escoja una Opcion: " );
		fflush(stdin);
		scanf ( "%d",&opcionMenu);
		switch (opcionMenu) {
			case  1 :
				system("cls");
				printf ("\n\nINSERTA NODO EN LA PILA\n\n");
				insertarNodo (&pila1); 
				break;
			case  2 :
				system("cls");
				printf ( "\n\n VISUALIZAR PILAS DE NODOS \n\n " );
				VisualizarPilas(pila1,pila2);
				break;
			case 3  :
				system("cls");
				printf ( "\n\n TRASLADAR ELEMENTOS Y VISUALIZAR PILA \n\n " );
				TrasladarPila(pila1,pila2);
				break;
			case  4 :
				system("cls");
				printf ( "\n\n Programa finalizado ... " );
				break;
			default:
				printf ( "\n\n Opción No Valida \n\n");
				break;
		}
	}while(opcionMenu!=4);
	return 0;
}

void insertarNodo(ptrPila*pila1){

    ptrNodo nuevo;
	nuevo=(ptrNodo)malloc(sizeof(Nodo));
	printf ( " Ingrese el dato que contendra el nuevo Nodo: " );
	fflush(stdin);
	scanf ("%d",&nuevo->dato);
	nuevo-> siguiente = *pila1; //el nuevo nodo,conjuntamente con el puntero que apunta al nuevo nodo
								//nodo nuevo y puntero apuntan al 1er elem (*pila1)
	*pila1 = nuevo; //Pila apuntara al nodo nuevo
}

void VisualizarPilas(ptrPila pila1,ptrPila pila2){

	printf("\t\tPILA 1\n");
	if(pila1!=NULL){ //verifica que la pila no este vacia
		while(pila1!=NULL) { //repite hasta que muestre el ultimo elem, o sea, NULL
			printf ( "\n  %d \n",pila1->dato);
			pila1 = pila1 -> siguiente; //avanza al siguiente elemento
		}
	} else {
		printf ("\n La pila 1 se encuentra Vacia \n\n");
	}

	printf("\t\tPILA 2\n");
	if(pila2!=NULL){
		while(pila2!=NULL) {
			printf ( "\n  %d \n",pila2->dato);
			pila2 = pila2 -> siguiente;
		}
	} else {
		printf ("\n La pila 2 se encuentra Vacia \n\n");
	}
    system("pause>null");
}

void TrasladarPila(ptrPila pila1,ptrPila pila2){
    if(pila1!=NULL){
        while(pila1!=NULL){
            Intercambio(&pila2,pila1->dato); //envia la pila 2, y el 1er elem de la pila 1
            pila1=pila1->siguiente;
        }
        VisualizarPilas(pila1,pila2);

    }
    system("cls");
    printf("\n\n\nINTERCAMBIO DE DATOS NUEVAMENTE\n\n\n");

    if(pila2!=NULL){
        while(pila2!=NULL){
            Intercambio(&pila1,pila2->dato); //envia la pila 1, y el 1er elem de la pila 2
            pila2=pila2->siguiente;
        }
        VisualizarPilas(pila1,pila2);

    }
}

void Intercambio(ptrPila*pila,int x){
    ptrNodo nuevo;
	nuevo=(ptrNodo)malloc(sizeof(Nodo)); //crea un nuevo nodo

        nuevo->dato=x; //el primer elemento de la pila opuesta se guardara en el dato del nodo nuevo
        nuevo->siguiente=*pila; //el nuevo nodo,conjuntamente con el puntero que apunta al nuevo nodo
								//nodo nuevo y puntero apuntan al 1er elem (*pila1)
        *pila=nuevo;//pila apuntara al nodo nuevo
}
