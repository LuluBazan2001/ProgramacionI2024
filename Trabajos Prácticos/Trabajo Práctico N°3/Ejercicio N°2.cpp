/*Crear el juego de “Batalla Naval”. Permitirá jugar a dos personas enfrentadas. Ubicar
3 barcos que utilizan una sola posición en una matriz de 5 x 5. Luego por turnos cada
jugador elije una posición si coincide con la del barco del contrario avisar por pantalla
que fue hundido y tiene derecho a un tiro más. El primero que acierte la posición de
los 3 barcos enemigos gana el juego.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>

void AltEnter()
{
    keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
    return;
}

void NombreJugador(char Nombre[20])
{
	printf("\t\tBIENVENIDO AL JUEGO DE BATALLA NAVAL\n");
	printf("\tIngrese su nombre:\t");
	gets(Nombre);
}

int MenuInicio()
{
	int opcion;
    printf("\t1.- Jugar Partida\n");
    printf("\t2.- Como Jugar\n");
    printf("\t3.- Salir del Juego\n");
    printf("Ingrese una opcion: ");
    scanf("%i",&opcion);
    fflush(stdin);
    return opcion;
}

void ComoJugar()
{
	printf("\t\t\t\t\t\tMODO DE JUEGO\n\n");
	printf("CADA JUGADOR COLOCARA TRES BARCOS EN DIFERENTES POSICIONES\n");
    printf("\nEL OBJETIVO ES DERRIBAR LOS BARCOS DEL OPONENTE\nATACANDO UNA POSICION [-LETRA-]\nDONDE CREAS QUE SE ENCUENTRE UN BARCO ENEMIGO\n");
    printf("\nEL JUEGO TERMINA CUANDO ALGUNO DE LOS DOS HAYA LOGRADO \nHUNDIR LOS TRES BARCOS DEL OPONENTE\n");
    printf("\nNOTA: OBSERVA QUE LA TECLA BLOQ MAYUS SE ENCUENTRE ENCENDIDA EN TODO MOMENTO\n");
}

void MatrizLetras(char MatrizJug[5][5])
{
    int i,j,LetraA=65;
    //filas fuera,columnas dentro
    for (i=0; i<5; i++)
    {
        for (j=0; j<5; j++)
        {
            MatrizJug[i][j]=LetraA++;
        }
    }

}

//imprime la matriz con las posiciones decididas en la funcion MatrizUsuario
void ImprimirMatriz(char MatrizUsuario[5][5])
{
    int i,j;
//filas afuera, columnas dentro
    for (i=0; i<5; i++)
    {
        for (j=0; j<5; j++)
        {
            printf("|%c|\t",MatrizUsuario[i][j]);


        }
        printf("\n\n");
    }
}
void MatrizUsuario(char MatrizUsuario[5][5],char Intentos[3])
{
    int i,j,LetraA=65;
    for (i=0; i<5; i++)
    {
        for (j=0; j<5; j++)
        {
                MatrizUsuario[i][j]=LetraA++;
            if (Intentos[0]==MatrizUsuario[i][j]) MatrizUsuario[i][j]=157;
            if (Intentos[1]==MatrizUsuario[i][j]) MatrizUsuario[i][j]=157;
            if (Intentos[2]==MatrizUsuario[i][j]) MatrizUsuario[i][j]=157;
        }
    }
}

void PosicionBarcos(char IntentosBarcos[3])
{
    //"a" va a ir incrementando para mostrar en pantalla barco1,barco2,barco3
    int i,a=1;
    int anterior;
    for(i=0; i<3;)
    {
        printf("INGRESA LA UBICACION DE TU BARCO %i: ",a);
        scanf("%c",&IntentosBarcos[i]);
        fflush(stdin);
        //Si las ubicaciones son las letras del abecedario...
        if (IntentosBarcos[i]>=65 && IntentosBarcos[i]<=90)
        {
            //Coloca la posicion
            if(IntentosBarcos[i]>= 65 && IntentosBarcos[i]<=90);
            //32 es espacio en blanco
            else IntentosBarcos[i]=IntentosBarcos[i]-32;
            //Esto es para 2do y 3er posicion
            if (IntentosBarcos[i]!=anterior)
            {
                //guarda en anterior la posicion anterior
                anterior=IntentosBarcos[i];
                //i incrementa el intento
                i++;
                //a incrementa el numero nada más(1,2,3)
                a++;
            }
            //Si es igual al anterior
            else printf("INGRESA UN BARCO EN OTRA POSICION \n");
        }
        //si NO ingresa una letra del abecedario
        else printf("OPCION INCORRECTA, INGRESA UNA LETRA QUE SE ENCUENTRE DENTRO DEL TABLERO\n");
    }
}

int tabla()
{
    int fallo=177;
    int asterisco=208;
    int ubic=157;
    printf("***************************************\n%c=BARCO  %c=BARCO HUNDIDO %c=TIRO FALLADO\n***************************************\n\n",ubic,asterisco,fallo);
}

void Ataques(char MatrizUsuario1[5][5],char MatrizUsuario2[5][5],char MatrizOp[5][5],char Nombre1[20],char Nombre2[20],char Intentos1[3],char Intentos2[3])
{
    char PuntoAtaque1,PuntoAtaque2,t,m,i,anterior,anterior2;
    int Opcion=0,C=0,P=0,c=0,p=0;
    do
    {
        if (Opcion==0 )
        {
            printf("*****************************\nTURNO DE JUGADOR 1: %s \n*****************************\n",Nombre1);
            printf("INGRESE EL PUNTO DONDE DESEA ATACAR: ");
            scanf("%s",&PuntoAtaque1);
            if (PuntoAtaque1>=65 && PuntoAtaque1<=90)
            {
                if(PuntoAtaque1==Intentos2[0] || PuntoAtaque1==Intentos2[1] || PuntoAtaque1==Intentos2[2] )
                {
                    if(PuntoAtaque1!=anterior)
                    {
                        printf("Barco Hundido\n");
                        C++;
                        anterior=PuntoAtaque1;
                        system("pause");
                        system("cls");
                        printf("*************************\nTU NOMBRE - JUGADOR 1: %s \n*****************************\n",Nombre1);
                        ImprimirMatriz(MatrizUsuario1);
                        tabla();
                        for (i=0; i<5; i++)
                        {
                            for (m=0; m<5; m++)
                            {
                                if(PuntoAtaque1==MatrizUsuario2[i][m]) MatrizUsuario2[i][m]=208;
                                printf("|%c|\t",MatrizUsuario2[i][m]);
                            }
                            printf("\n\n");
                        }
                        printf("*************************\nTU NOMBRE - JUGADOR 2: %s \n*****************************\n",Nombre2);
                    }
                    else printf("YA UTILIZO ESTA CORDENADA INTENTE OTRA\n");
                }
                else
                {
                    if(PuntoAtaque1!=anterior)
                    {
                        printf("No dio en el blanco\n");
                        Opcion++;
                        P++;
                        anterior=PuntoAtaque1;
                        system("pause");
                        system("cls");
                        printf("*************************\nTU NOMBRE - JUGADOR 1: %s \n*****************************\n",Nombre1);
                        ImprimirMatriz(MatrizUsuario1);
                        tabla();
                        for (i=0; i<5; i++)
                        {
                            for (m=0; m<5; m++)
                            {
                                if (PuntoAtaque1==MatrizUsuario2[i][m]) MatrizUsuario2[i][m]=177;
                                printf("|%c|\t",MatrizUsuario2[i][m]);
                            }
                            printf("\n\n");
                        }
                        printf("*************************\nTU NOMBRE - JUGADOR 2: %s \n*****************************\n",Nombre2);
                    }
                    else printf("YA UTILIZO ESTA CORDENADA INTENTE OTRA \n");
                }
            } else printf("OPCION INCORRECTA INGRESA UNA LETRA QUE SE ENCUENTRE DENTRO DEL TABLERO\n");
        }
        if(Opcion==1)
        {
            printf("*****************************\nTURNO DE JUGADOR 2: %s \n*****************************\n",Nombre2);
            printf("INGRESE EL PUNTO DONDE DESEA ATACAR: ");
            scanf("%s",&PuntoAtaque2);
            if (PuntoAtaque2>=65 && PuntoAtaque2<=90)
            {
                if(PuntoAtaque2==Intentos1[0] || PuntoAtaque2==Intentos1[1] || PuntoAtaque2==Intentos1[2] )
                {
                    if(PuntoAtaque2!=anterior2)
                    {
                        printf("Barco Hundido\n");
                        c++;
                        anterior2=PuntoAtaque2;
                        system("pause");
                        system("cls");
                        printf("*************************\nTU NOMBRE - JUGADOR 2: %s \n*****************************\n",Nombre2);
                        ImprimirMatriz(MatrizUsuario2);
                        tabla();
                        for (i=0; i<5; i++)
                        {
                            for (m=0; m<5; m++)
                            {
                                if(PuntoAtaque2==MatrizUsuario1[i][m]) MatrizUsuario1[i][m]=208;
                                printf("|%c|\t",MatrizUsuario1[i][m]);
                            }
                            printf("\n\n");
                        }
                        printf("*************************\nTU NOMBRE - JUGADOR 1: %s \n*****************************\n",Nombre1);
                    }
                    else printf("YA UTILIZO ESTA CORDENADA INTENTE OTRA\n");
                }
                else
                {
                    if(PuntoAtaque2!=anterior2)
                    {
                        printf("No dio en el blanco\n");
                        Opcion=0;
                        p++;
                        anterior2=PuntoAtaque2;
                        system("pause");
                        system("cls");
                        printf("*************************\nTU NOMBRE - JUGADOR 2: %s \n*****************************\n",Nombre2);
                        ImprimirMatriz(MatrizUsuario2);
                        tabla();
                        for (i=0; i<5; i++)
                        {
                            for (m=0; m<5; m++)
                            {
                                if (PuntoAtaque2==MatrizUsuario1[i][m]) MatrizUsuario1[i][m]=177;
                                printf("|%c|\t",MatrizUsuario1[i][m]);
                            }
                            printf("\n\n");
                        }
                        printf("*************************\nTU NOMBRE - JUGADOR 1: %s \n*****************************\n",Nombre1);
                    }
                    else printf("YA UTILIZO ESTA CORDENADA INTENTE OTRA \n");
                }
            } else printf("OPCION INCORRECTA INGRESA UNA LETRA QUE SE ENCUENTRE DENTRO DEL TABLERO\n");
        }
        while (P==3 || p==3)
        {
            for (i=0; i<10; i++)
            {
                printf("PERDISTEE !!!\n");
            }
            printf("SUERTE PARA LA PROXIMA\nTE RETO A UNA NUEVA PARTIDA\n");
            P=0;
            p=0;
            Opcion=3;
        }
        while (C==3 || c==3)
        {
            for (i=0; i<10; i++)
            {
                printf("GANASTEE !!!\n");

            }
            printf("PRESIONA SALIR\n");
            C=0;
            c=0;
            Opcion=3;
        }

    }while(Opcion!=3 );
    system("pause");
    system("cls");
}

int main (){
    AltEnter();
	char Nombre1[20],Nombre2[20],MatrizUsuario1[5][5],MatrizUsuario2[5][5],MatrizOp[5][5],Intentos1[3],Intentos2[3];
	int Opcion;
	NombreJugador(Nombre1);
	system("cls");
	NombreJugador(Nombre2);
	system("cls");

	do{
		printf("\t\t\t\tBIENVENIDO AL JUEGO DE BATALLA NAVAL\n");
		printf("\t*************************TU NOMBRE - JUGADOR 1: %s *****************************\n",Nombre1);
    	printf("\t*************************TU NOMBRE - JUGADOR 2: %s *****************************\n",Nombre2);
		Opcion=MenuInicio();
		if (Opcion==1)
		{
		    system("cls");
			printf("\t\t\tObserve que la tecla BLOQ MAYUS se encuentre encendida\n\n\t\t\t\t.............Listo...........\n\t\t\t\t\tComenzamos\n");
            system("pause>null");
            system("cls");
            //INGRESO DE DATOS DE JUGADOR 1
            printf("\n*****************************\nNOMBRE JUGADOR 1: %s \n***************************** \n\n",Nombre1);
            //Asigna las letras a cada cuadrado
            MatrizLetras(MatrizUsuario1);
            //Grafica la matriz con las letras en la pantalla y define las posiciones
            ImprimirMatriz(MatrizUsuario1);
            //Inserta Dibujo en donde decide posicionar los barcos el jugador
            MatrizUsuario(MatrizUsuario1,Intentos1);
			tabla();
			//El jugador posiciona los barcos en sus 3 intentos
			PosicionBarcos(Intentos1);
            system("pause>null");
			system("cls");


			//INGRESO DE DATOS DE JUGADOR 2
            printf("\n*****************************\nNOMBRE JUGADOR 2: %s \n***************************** \n\n",Nombre2);
            //Asigna las letras a cada cuadrado
            MatrizLetras(MatrizUsuario2);
            //Grafica la matriz con las letras en la pantalla
            ImprimirMatriz(MatrizUsuario2);
            //Inserta Dibujo en donde decide posicionar los barcos el jugador
            MatrizUsuario(MatrizUsuario2,Intentos2);
			tabla();
			//El jugador posiciona los barcos en sus 3 intentos
			PosicionBarcos(Intentos2);
            system("pause>null");
            system("cls");

            //ATAQUES
            printf("\n*****************************\nNOMBRE JUGADOR 1: %s \n***************************** \n\n",Nombre1);
            ImprimirMatriz(MatrizUsuario1);
            tabla();
            ImprimirMatriz(MatrizUsuario2);
            printf("\n*****************************\nNOMBRE JUGADOR 2: %s \n***************************** \n\n",Nombre2);
            MatrizLetras(MatrizOp);
            Ataques(MatrizUsuario1,MatrizUsuario2,MatrizOp,Nombre1,Nombre2,Intentos1,Intentos2);
            break;

		}
		if (Opcion==2)
		{
			ComoJugar();
			system("pause>null");
    		system("cls");
		}
    	if (Opcion!=3)
        {
            printf("\t\t\t\tOPCION INCORRECTA\n");
            system("pause>null");
            system("cls");
    	}
	}while(Opcion!=3);
	system("pause>null");
}
