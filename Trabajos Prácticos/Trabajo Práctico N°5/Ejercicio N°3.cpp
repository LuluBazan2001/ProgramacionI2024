/*Realizar mediante una lista el ingreso de productos con los campos código,
descripción, precio y cantidad. Ingresar a la lista por un solo lugar. Dar una opción de
ordenar la lista. Mostrar los elementos de la lista.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Producto
{
    int Codigo;
    char Descripcion[50];
    float Precio;
    int Cantidad;
}Prod;

typedef struct NodoNuevo
{
    Prod Cadena;
    struct NodoNuevo*PuntSiguiente;
}Nodo;

Nodo*Actual;
Nodo*Cabeza;
Nodo*Nuevo;
Nodo*Anterior;

int menu();
void CargarProducto(Nodo **Cabeza);
void InsertarNodo(Prod Auxiliar, Nodo **Cabeza);
void OrdenarLista(Nodo **Cabeza,Prod Auxiliar);
void Mostrar(Nodo **Cabeza);

int main(){
    int OpcionMenu;

	do{
    	OpcionMenu=menu();
    	switch (OpcionMenu){
			case 1: CargarProducto(&Cabeza);
    				break;
			case 2: Mostrar(&Cabeza);
    				break;
			case 3: system("cls");
    				printf("\n\tSalio del programa...");
    				system("pause");
    				system("cls");
    				break;
			default:printf("\n\tIngreso incorrectamente.");
    	}
	}while(OpcionMenu!=3);
}

int menu(){

    int opcion=0;
    system("cls");
    printf ("\n\n\n\t\t ***** BIENVENIDOS AL PROGRAMA *****");
	printf ("\n\n\t\t ------------------------------------");
	printf ("\n\n\t\t * 1- Cargar Productos");
	printf ("\n\n\t\t * 2- Visualizar Productos");
	printf ("\n\n\t\t * 3- Salir");
	printf ("\n\n\t\t ------------------------------------");
    printf("\n\tIngrese una opcion: ");
    scanf("%d.", &opcion);
    fflush(stdin);

    return opcion;
}

void CargarProducto(Nodo **Cabeza)
{
    int OpcionOrden;
	Prod Auxiliar;
    	system("cls");
    	printf("\n\tIngrese el Codigo del Producto:  ");
    	fflush(stdin);
    	scanf("%d", &Auxiliar.Codigo);
    	printf("\n\n\tIngrese la Descripcion del Producto:  ");
    	fflush(stdin);
    	gets(Auxiliar.Descripcion);
    	printf("\n\n\tIngrese el Precio del Producto:  ");
    	fflush(stdin);
    	scanf("%f.", &Auxiliar.Precio);
    	printf("\n\n\tIngrese la Cantidad de Productos:  ");
    	fflush(stdin);
    	scanf("%d.", &Auxiliar.Cantidad);
    	printf("\n\nDesea ordenar la lista de Productos ingresados? (1)Si/ (2)No:  ");
    	scanf("%i",&OpcionOrden);
    	fflush(stdin);
    	system("cls");
    	switch(OpcionOrden){
    		case 1: OrdenarLista(Cabeza,Auxiliar);
					break;
					
    		case 2:	InsertarNodo(Auxiliar,Cabeza);
					break;
		}
    		
}

void OrdenarLista(Nodo **Cabeza,Prod Auxiliar)
{
    Anterior=Actual= *Cabeza;

    printf("\n\tOrdenando Productos...");
    system("pause");
    system("cls");
    
    while (Actual != NULL && Actual->Cadena.Codigo < Auxiliar.Codigo){
		    Anterior = Actual;
            Actual = Actual->PuntSiguiente;
     }
     
     Nuevo = (Nodo*) malloc(sizeof(struct NodoNuevo));
     Nuevo->Cadena = Auxiliar;

      if (Anterior == NULL || Anterior == Actual){ 
            Nuevo->PuntSiguiente = Anterior;
            *Cabeza = Nuevo; 
      }else{                        
            Nuevo->PuntSiguiente = Actual;
            Anterior->PuntSiguiente= Nuevo;
      } 
      printf("\n\tProductos ordenados...");
      system("pause");
      system("cls");
}

void InsertarNodo(Prod Auxiliar, Nodo **Cabeza)
{     
     Anterior=Actual= *Cabeza;
     
    while (Actual != NULL) {      
			Anterior = Actual;
            Actual = Actual->PuntSiguiente;
     }

     Nuevo = (Nodo*) malloc(sizeof(struct NodoNuevo));
     Nuevo->Cadena = Auxiliar;

      if (Anterior == NULL || Anterior == Actual){ 
            Nuevo->PuntSiguiente = Anterior;
            *Cabeza = Nuevo;  
      }else{                   
            Nuevo->PuntSiguiente = Actual;
            Anterior->PuntSiguiente= Nuevo;
      }
}

void Mostrar(Nodo **Cabeza)
{
    system ("cls");
     Nodo*Nuevo;
     Nuevo=*Cabeza;
     printf ("*******************************************************************\n");
     printf ("Codigo      Descripcion                         Cantidad         Precio \n");
     printf ("*******************************************************************\n");
     while (Nuevo!=NULL){
        printf ("%d         %s                            %d           %f         \n "
			,Nuevo->Cadena.Codigo,Nuevo->Cadena.Descripcion,Nuevo->Cadena.Cantidad,Nuevo->Cadena.Precio);
        
		Nuevo=Nuevo->PuntSiguiente;
     };
     system("pause>null");

}
