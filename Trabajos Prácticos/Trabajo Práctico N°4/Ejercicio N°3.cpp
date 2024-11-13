#include <stdio.h>
#include <stdlib.h>

struct fecha_nac
{
   int dia,mes,anio;
};

struct datos_beneficiarios
{
   char borrado,sexo;
   char nombre[34],estado[10],direccion [24] ;
   float ingresos;
   int antiguedad, documento,hijos;
   struct fecha_nac fecha; // estructura anidada
};

typedef struct datos_beneficiarios datos;

int menu(FILE *empleado);
void cargar(FILE *empleado);
long buscar_doc (FILE *empleado, int doc);
void mostrar (FILE *empleado);
void eliminar (FILE *empleado);
void ingresos (FILE *empleado);
void cumple (FILE *empleado);
void antiguedad (FILE *empleado);


main()
{
   FILE *empleado;//declara registro
   empleado = fopen("beneficiarios.dat", "r+b"); // asocio el archivo fisico con el logico y lo abro 
   if(!empleado) empleado = fopen("beneficiarios.dat", "w+b");  // si no existe se crea
   menu(empleado);
   fclose(empleado);
}

int menu(FILE *empleado)
 {
     char opcion;
     do{
       system("cls");
       
       	printf("\t********************************************************\n");
		printf("\t*         MENU DE OPCIONES			       \n");
   		printf("\t********************************************************\n");
   		printf("\t* 1) Cargar Beneficiario			  	\n");
   		printf("\t* 2) Mostrar Beneficiarios		  		   \n");
   		printf("\t* 3) Eliminar Beneficiario		  		   \n");
   		printf("\t* 4) Empleados varones con ingresos superiores a $2500 \n");
   		printf("\t* 5) Empleados que cumplen años segun mes    \n");
   		printf("\t* 6) Entrega de aportes					   \n");
   		printf("\t* 7) Salir								   \n");
   		printf("\t********************************************************\n");
       	printf ("\t* Ingrese una Opcion:");
       	scanf (" %c", & opcion);
     switch(opcion) {
         case '1':
            cargar(empleado);
            break;
         case '2':
            mostrar(empleado);
            break;
         case '3':
          eliminar(empleado);
            break;
         case '4':
          ingresos(empleado);
            break;
         case '5':
          cumple(empleado);
            break;
         case '6':
          antiguedad(empleado);
            break;
       }
     }while (opcion != '7');
 }

void cargar(FILE *empleado)
 {
   datos beneficiarios;
   long busqueda;
   int temp;
   char continuar;
   do{
    system("cls");
    printf("\t********************************************************\n");
	printf("\t*         DOCUMENTO			      					 \n");
   	printf("\t********************************************************\n");
    scanf (" %i", &beneficiarios.documento);
    printf("\t********************************************************\n"); 
    fflush(stdin);
    busqueda = buscar_doc(empleado,beneficiarios.documento);
    if ( busqueda != -1){
    printf ("\n Beneficiario ya cargado \n\n");
    continuar == 'n';
    system("pause");
    } else // HACER COMPROBACIONES DE TIPOS
    {
    printf ("\n Apellido y Nombre \n");
    gets(beneficiarios.nombre);
    fflush(stdin);
    printf ("\n Direccion \n");
    gets (beneficiarios.direccion);
    fflush(stdin);
    printf ("\n Ingresos \n");
    scanf (" %f", &beneficiarios.ingresos);
    fflush(stdin);
    printf ("\n documento \n");
    scanf (" %i", &beneficiarios.documento);
    fflush(stdin);
    printf ("\n Antiguedad \n");
    scanf (" %i", &beneficiarios.antiguedad);
    fflush(stdin);
    beneficiarios.borrado='n';
    printf ("\n Sexo M/F \n");
    scanf (" %c", &beneficiarios.sexo);
    fflush(stdin);
    printf ("\n Estado Civil (Soltero/a,Casado/a,Divorciado/a,Viudo/a)\n");
    gets(beneficiarios.estado);
    fflush(stdin);
    printf ("\n Fecha Nacimiento \n");
    printf ("\n Dia \n");
    scanf (" %i", &beneficiarios.fecha.dia);
    fflush(stdin);
    printf ("\n Mes \n");
    scanf (" %i", &beneficiarios.fecha.mes);
    fflush(stdin);
    printf ("\n Año \n");
    scanf (" %i", &beneficiarios.fecha.anio);
    fflush(stdin);
    system("cls");
    printf ("Los datos cargados son : s/n \n\n");
    printf ("\t DNI: %d \t NOMBRE: %s \t DIRRECCION: %s \t INGRESOS: %f \n",
            	beneficiarios.documento, beneficiarios.nombre, beneficiarios.direccion,beneficiarios.ingresos );
    printf ("\t SEXO: %c \t DIA NAC: %d \t MES NAC: %d  \t AÑO NAC: %d   \n",
                beneficiarios.sexo,beneficiarios.fecha.dia,beneficiarios.fecha.mes,beneficiarios.fecha.anio);
    printf ("\n Son correctos los datos s/n \n");
    scanf (" %c", &continuar);
    } //else
    if( continuar == 's') {
        fseek(empleado, 0, SEEK_END); // Me posiciona al final del archivo
        fwrite(&beneficiarios, sizeof(datos),1, empleado); // guardo los datos en el archivo
        //trabaja con registros de longitud constante
		//Escribe en un fichero uno o varios registros de la misma longitud 
		//almacenados a partir de una dirección de memoria determinada.
    }
    system("cls");
    printf ("Desea cargar otro beneficiario s/n \n");
    scanf (" %c", & continuar);
   }while( continuar == 's');
}

long buscar_doc (FILE *empleado , int doc)
{
	datos beneficiarios;
 	long encontrado =-1;
 	long posicion = ftell(empleado);  // guardo la posicion actual en el archivo
 	//ftell averigua la posición actual del cursor de lectura/excritura de un fichero
 	//Retorna esa posicion, o -1 si hay algun error.
 	printf("\tPosicion:      %f \n", posicion);
  	system("pause");
 	fseek (empleado, 0,0); // posiciona al principio del archivo
 	while( (fread/*retorna el numero de registros leídos*/(&beneficiarios, sizeof(struct datos_beneficiarios), 1, empleado)) && (encontrado==-1)  ){
    if (beneficiarios.documento ==doc){
        encontrado=ftell(empleado) - sizeof(struct datos_beneficiarios);
    }
   }
   fseek (empleado, posicion * sizeof(struct datos_beneficiarios), 0); // pongo la posicion desde la que llame
   return encontrado;
}

void mostrar (FILE *empleado)
{
   datos  beneficiarios;
   rewind(empleado); //situa el cursor de lectura/escritura al principio del archivo
   system("cls");
   printf("DNI      	   Apellido y Nombre		      Direccion  \n\n");
   while(fread/*retorna el numero de registros leídos*/(&beneficiarios, sizeof(struct datos_beneficiarios), 1, empleado))
      {
        if(beneficiarios.borrado == 'n')
          printf("%i    	%s           	 %c  \n\n",
		  beneficiarios.documento,beneficiarios.nombre,beneficiarios.direccion);
      }
      system("PAUSE");
}

void eliminar (FILE *empleado)
{
   datos  beneficiarios;
   int aux;
   char continuar='s';
   system("cls");
   printf("Eliminar registro: \n");
   printf("DNI: ");
   scanf("%d",&aux);
   long numero = buscar_doc(empleado,aux);
   //Si el registro del empleado no existe...
   if (numero!=-1)
    {
        fseek(empleado, numero, SEEK_SET);//posiciona al empleado ingresado
        fread(&beneficiarios, sizeof(struct datos_beneficiarios), 1, empleado);/*numero de registros leídos*/
        printf("\nESTA SEGURO DE ELIMINAR A:  %s  s/n\n", beneficiarios.nombre );
        fflush(stdin);
        scanf("%c", &continuar);
        if(continuar=='s')
        {
             beneficiarios.borrado = 's';
             fseek(empleado, numero, SEEK_SET);//posiciona al empleado ingresado
             fwrite(&beneficiarios, sizeof(struct datos_beneficiarios), 1, empleado);
             printf ("beneficiario eliminado \n");
        } else printf ("beneficiario no eliminado\n");
    }else {printf ("DNI no encontrado\n\n");}
     system("PAUSE");
}

void ingresos (FILE *empleado)
{
   datos  beneficiarios;
   rewind(empleado);//situa el cursor de lectura/escritura al principio del archivo
   system("cls");
   printf(" \tAPELLIDO Y NOMBRE \t DOCUMENTO \n\t___________________________________\n\n");
   while(fread(&beneficiarios, sizeof(struct datos_beneficiarios), 1, empleado))
      {
        if(beneficiarios.borrado == 'n' && beneficiarios.sexo == 'M' && beneficiarios.ingresos>='2500')
          printf("\t%s   %i \n\n", beneficiarios.nombre, beneficiarios.documento);
      }
      system("PAUSE");
}


void cumple (FILE *empleado)
{
   int mes;
   datos beneficiarios;
   rewind(empleado);
   system("cls");
   printf("INGRESE EL MES QUE DESEA LISTAR\n");
   scanf("%d", &mes);
   printf("\t MES: %d \n", mes);
   printf(" \tApellido y Nombre\t   DIA \n\t___________________________________\n\n");
   while(fread(&beneficiarios, sizeof(struct datos_beneficiarios), 1, empleado))
      {
        if(beneficiarios.borrado == 'n' && beneficiarios.fecha.mes == mes)
          printf("\t%s   %15d \n\n", beneficiarios.nombre, beneficiarios.fecha.dia);
      }
      system("PAUSE");
}


void antiguedad (FILE *empleado)
{


   datos  beneficiarios;
   rewind(empleado);
   system("cls");
   printf(" \tApellido y Nombre 	 SUELDO 	 PORCENTAJE 	 ANTIGUEDAD 	 BONIFICACION \n");
   printf(" \t_________________________________________________________________\n\n");
   while(fread(&beneficiarios, sizeof(struct datos_beneficiarios), 1, empleado))
      {
        int por=0;
        float bonif;
        if (beneficiarios.antiguedad >= 0 && beneficiarios.antiguedad <= 1)
            por = 5;
        if (beneficiarios.antiguedad >= 2 && beneficiarios.antiguedad <= 3)
            por = 8;
        if (beneficiarios.antiguedad >= 4 && beneficiarios.antiguedad <= 6)
            por = 10;
        if (beneficiarios.antiguedad >= 7 && beneficiarios.antiguedad <= 10)
            por = 25;
        if (beneficiarios.antiguedad >= 10)
            por = 35;
        bonif =  (por * beneficiarios.ingresos) / 100;
        if(beneficiarios.borrado == 'n')
          printf("\t%s         %f         %d         %d          %f \n\n",beneficiarios.nombre, beneficiarios.ingresos, por,beneficiarios.antiguedad, bonif);
      }
      system("PAUSE");
}
