/*Llenar un vector de 15 estructuras cuyos elementos son nombre, apellido y edad,
posteriormente utilizando punteros mostrar nombres y apellidos de las personas
mayores de edad y las posiciones en memoria de esas estructuras mostradas.*/

#include <string.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#define c 3

struct Personas{
	char nombre[30];
	char apellido[30];
	int edad;
}VectorDatos[c];

void gotoxy(int x, int y);
void menu();
int IngresoDatos(struct Personas VectorDatos[]);
void Seleccion(struct Personas VectorDatos[],int *DireccionEdad);

int main(){

	menu();
	return 0;
}

void menu(){
	
	int Direccion,opcion;
	do{
		system("cls");
		gotoxy (16,4);printf("\tBIENVENIDO/A AL MENU DE OPCIONES DEL PROGRAMA\n");
		gotoxy (16,6);printf("\t1) Ingrese los datos de las 15 personas\n");
		gotoxy (16,7);printf("\t2) Mostrar los mayores de edad y posicion de memoria\n\n");
		gotoxy (16,8);printf("\t3) Salir");
		gotoxy (16,9);printf("\tSeleccione opcion \n");
		gotoxy (16,10);scanf("%i",&opcion);
		fflush(stdin);
			switch (opcion){
			case 1: 	
					system("cls");
					Direccion=IngresoDatos(VectorDatos);
					break;
			case 2: 
					system("cls");
					Seleccion(VectorDatos,&Direccion);
					break;
			case 3:
					break;
		}
	}while(opcion<3);
}

void gotoxy(int x, int y){
  HANDLE hcon;
  hcon=GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwpos;
  dwpos.X=x;
  dwpos.Y=y;
  SetConsoleCursorPosition(hcon,dwpos);
}

int IngresoDatos(struct Personas VectorDatos[]){
	
	int i,edad,*DireccionEdad;
	for(i=0;i<c;i++){
		system("cls");
		gotoxy(16,3);printf ("\t Ingrese Nombre Persona Nro %i: \n",i+1);
    	gotoxy(16,4);gets(VectorDatos[i].nombre);
    	fflush(stdin);
    	gotoxy(16,5);printf ("\t Ingrese Apellido Persona Nro %i: \n",i+1);
    	gotoxy(16,6);gets(VectorDatos[i].apellido);
    	fflush(stdin);
    	gotoxy(16,7);printf ("\t Ingrese Edad Persona Nro %i: \n",i+1);
    	gotoxy(16,8);scanf (" %d",&VectorDatos[i].edad);
    	fflush(stdin);
    	DireccionEdad=&VectorDatos[i].edad;
	}
	system("pause>null");
	system("cls");
	return (*DireccionEdad);
}

void Seleccion(struct Personas VectorDatos[],int *DireccionEdad){
	int i;
		for(i=0;i<c;i++){
			if(VectorDatos[i].edad>=18){
				gotoxy(16,3+i);printf("\tNombre y Apellido:%s %s \t Posicion de memoria: %p \n"
											,VectorDatos[i].nombre,VectorDatos[i].apellido,DireccionEdad);
			}
			DireccionEdad++;
		}
	system("pause");
}
