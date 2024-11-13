/*Realizar el juego del ahorcado: Jugador 1 ingresa una palabra sin que vea jugador 2.
El ordenador indica a jugador 2 cuantas letras tiene la palabra a descubrir. Jugador 2
ira ingresando letras de las cuales, si existen en la palabra a descifrar, se irán
descubriendo. En caso de acertar todas las letras gana el juego caso contrario al 6to
intento fallido perderá el juego.*/
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>

#define INGRESODELETRAS (palabra[i]>=48&&palabra[i]<=57)||(palabra[i]>=0&&palabra[i]<=32)||(palabra[i]>=97&&palabra[i]<=122)

void gotoxy(int x, int y){
  HANDLE hcon;
  hcon=GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwpos;
  dwpos.X=x;
  dwpos.Y=y;
  SetConsoleCursorPosition(hcon,dwpos);
}
int verificarletras(char* palabra){
    int result;
    result=strlen(palabra);
    return result;

}
main(){
    char palabra[50]="",letra,letrasacertadas[30]="",letramal[6]="-----";
    int i=0,salida=0,gana=0,cantletras,oportunidad=6,falla=0,l=0;
//INGRESO DE LA PALABRA A ADIVINAR
	printf("La palabra debe contener unicamente letras may%csculas\n",163);
    printf("Ingrese la palabra a adivinar: ");
    scanf("%s",&palabra);
    cantletras=verificarletras(palabra);
    do{
        for(i=0;i<cantletras;i++)
            if(INGRESODELETRAS) falla++;
        if(falla!=0){
            system("cls");
            printf("La palabra debe contener unicamente letras may%csculas\n",163);
            printf("Ingrese la palabra a adivinar: ");
            fflush(stdin);
            scanf("%s",&palabra);
            cantletras=verificarletras(palabra);
        }
        else salida=1;
        falla=0;
    }while(salida==0);
    for(i=0;i<cantletras;i++)
        letrasacertadas[i]='-';
        
        //DIBUJA EL AHORCADO
    while(salida&&oportunidad>0){
        system("cls");
        if(oportunidad<6){
            gotoxy(40,1); printf("O");
        }
        if(oportunidad<5){
            gotoxy(40,2); printf("|");
        }
        if(oportunidad<4){
            gotoxy(41,2); printf("%c",92);
        }
        if(oportunidad<3){
            gotoxy(39,2); printf("/");
        }
        if(oportunidad<2){
            gotoxy(41,3); printf("%c",92);
        }

        gotoxy(10,0);
        printf("La palabra tiene %d letras",cantletras);
        gotoxy(10,2);
        printf("%s",letrasacertadas);
        gotoxy(12,5);
        printf("Letras ya ingresadas: %s",letramal);
        gotoxy(12,7);
        printf("Ingrese una letra: ");
        fflush(stdin);
        scanf("%c",&letra);
        if((letra>=65&&letra<=90))
		{
            for(i=0;i<cantletras;i++)
			{
                if(letra==palabra[i])
                    letrasacertadas[i]=letra;
                else falla++;
            }
            for(i=0;i<6;i++)
                    if(letra==letramal[i]||letra==' ') falla--;
            if(falla==cantletras){
                letramal[l]=letra; oportunidad--; l++;
            }
            falla=0;
            if(strcmp(letrasacertadas,palabra)==0){
                salida=0;
            fflush(stdin);
            }
        }
    }
    system("cls");
    if (salida==1){
        gotoxy(31,4); printf("o---%c",186);
        gotoxy(31,5); printf("|   %c",186);
        gotoxy(30,6); printf("0/   %c",186);
        gotoxy(30,7); printf("|    %c",186);
        gotoxy(31,7); printf("%c   %c",92,186);
        gotoxy(29,7); printf("/");
        gotoxy(31,8); printf("%c   %c",92,186);
        gotoxy(29,8); printf("/");
        gotoxy(35,9); printf("%c",186);
        gotoxy(25,10); printf("PERDISTE %c%c%c",178,178,178);
        gotoxy(18,12); printf("La palabra era: '%s'",palabra);
    }
    else{
        gotoxy(29,6); printf("%cO/",92);
        gotoxy(30,7); printf("|");
        gotoxy(31,8); printf("%c",92);
        gotoxy(29,8); printf("/");
        gotoxy(27,10); printf("GANASTE");
        gotoxy(15,12); printf("La palabra era: '%s'",palabra);
    }
}
