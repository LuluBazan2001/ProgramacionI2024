/*Se organiza un recital cuya venta de entradas se organiza por etapas. En la primera etapa
se venderán 10 entradas a 200 pesos. Luego en una segunda etapa se venderán 10 más
a 300 pesos y por último se venderá a la cantidad de personas que vayan a comprar ese
día a 400 pesos. Se desea registrar el nombre de la persona junto a lo que pagó por la
entrada. Permitir Registrar a partir de la primera venta. Mostrar por pantalla el listado
completo al final de cada etapa*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Cliente{
	char dato;
	struct Cliente*siguiente;
}Cliente;

Cliente*primero=NULL;
Cliente*ultimo=NULL;

void etapa1();
void etapa2();
void etapafin();
void visualizar();

int main(){
	
	etapa1();
	etapa2();
	etapafin();
	visualizar();

	return 0;
}

void etapa1(){
	
	/*FILE *clientes;
    clientes=fopen("clientes.txt","r+t");//asocia el archivo fisico con el logico y lo abre
    if(!clientes)clientes=fopen("clientes.txt","w+t"); //si no existe se crea*/
	int entradas;
	Cliente*nuevo=(Cliente*)malloc(sizeof(Cliente));
	
	for(entradas=1;entradas<=10;entradas++){
		printf("Ingrese nombre del cliente:\n");
		fflush(stdin);
		scanf ("%d",&nuevo->dato);
		
		if (primero == NULL){ //si es el primer elemento a ingresar
			primero = nuevo; //el nuevo elem se posicionara como primero
			primero-> siguiente = NULL ; //el primer elem apuntara a NULL
			ultimo = nuevo; //el nuevo elem se posicionara como ultimo
			//fprintf(clientes,"\n %s Paga 200 \n",ultimo);
		}else{ //Si no es el primer elem a ingresar
			ultimo-> siguiente = nuevo; //el nuevo elem apuntara al ultimo numero ingresado
			nuevo-> siguiente = NULL ;
			ultimo = nuevo;
			//fprintf(clientes,"\n %s Paga 200 \n",ultimo);
		}
			
	}
    //fclose(clientes);
}

void etapa2(){
	
	/*FILE *clientes;
    clientes=fopen("clientes.txt","r+t");//asocia el archivo fisico con el logico y lo abre
    if(!clientes)clientes=fopen("clientes.txt","w+t"); //si no existe se crea*/
	int entradas;
	Cliente*nuevo=(Cliente*)malloc(sizeof(Cliente));
	
	for(entradas=1;entradas<=10;entradas++){
		printf("Ingrese nombre del cliente:\n");
		fflush(stdin);
		scanf ("%d",&nuevo->dato);
		
		if (primero == NULL){ //si es el primer elemento a ingresar
			primero = nuevo; //el nuevo elem se posicionara como primero
			primero-> siguiente = NULL ; //el primer elem apuntara a NULL
			ultimo = nuevo; //el nuevo elem se posicionara como ultimo
			//fprintf(clientes,"\n %s Paga 300 \n",ultimo);
		
		}else{ //Si no es el primer elem a ingresar
			ultimo-> siguiente = nuevo; //el nuevo elem apuntara al ultimo numero ingresado
			nuevo-> siguiente = NULL ;
			ultimo = nuevo;
			//fprintf(clientes,"\n %s Paga 300 \n",ultimo);
		}
	}
    //fclose(clientes);
}

void etapafin(){
	
	/*FILE *clientes;
    clientes=fopen("clientes.txt","r+t");//asocia el archivo fisico con el logico y lo abre
    if(!clientes)clientes=fopen("clientes.txt","w+t"); //si no existe se crea*/
	int entradas;
	Cliente*nuevo=(Cliente*)malloc(sizeof(Cliente));
	
	do{
		printf("Ingrese nombre del cliente:\n");
		fflush(stdin);
		scanf ("%d",&nuevo->dato);
		
		if (primero == NULL){ //si es el primer elemento a ingresar
			primero = nuevo; //el nuevo elem se posicionara como primero
			primero-> siguiente = NULL ; //el primer elem apuntara a NULL
			ultimo = nuevo; //el nuevo elem se posicionara como ultimo
			//fprintf(clientes,"\n %s Paga 400 \n",ultimo);
		
		}else{ //Si no es el primer elem a ingresar
			ultimo-> siguiente = nuevo; //el nuevo elem apuntara al ultimo numero ingresado
			nuevo-> siguiente = NULL ;
			ultimo = nuevo;
			//fprintf(clientes,"\n %s Paga 400 \n",ultimo);
		}
		printf("Desea ingresar otro cliente? SI(1)/NO(2)");
		fflush(stdin);
		scanf("%i",&entradas);
		system("pause");
	}while(entradas=='1');
    //fclose(clientes);
}

void visualizar(){
	
	printf("\t\tCLIENTES DEL RECITAL\n");
	int entradas;
	Cliente*actual = (Cliente*)malloc(sizeof(Cliente));
	actual = primero;
	if (primero != NULL){
		while (actual != NULL){
			for(entradas=1;entradas<=10;entradas++){
				printf ( "\n\t  %d paga 200" ,actual->dato);
				actual = actual->siguiente;
			}
			for(entradas=1;entradas<=10;entradas++){
				printf ( "\n\t  %d paga 300" ,actual->dato);
				actual = actual->siguiente;
			}
			printf ( "\n\t  %d paga 400" ,actual->dato);
			actual = actual->siguiente;
		}
	}else{
		printf (" \n NO HAY CLIENTES EN EL RECITAL \n \n ");
	}
}
