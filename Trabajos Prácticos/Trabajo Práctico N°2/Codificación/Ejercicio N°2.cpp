/*Un importador necesita transformar precios que pueden estar 
en Euro, Dólar, Real, Yen, Yuan, Libra Británica y Nuevo Sol a
su equivalente en moneda nacional. Si el precio obtenido en 
pesos es mayor a 20.000 adicionarle un 2% de retención. 
Mostrar el valor obtenido por pantalla. (No hacer ningún cálculo 
en la función principal)*/

#include <stdio.h>
#include <stdlib.h>

//FUNCION CALCULO
float calculo (int opcion1, float precio, float cotizacioneuro, float cotizaciondolar, float cotizacionreal, float cotizacionyen, float cotizacionyuan, float cotizacionlibrabritanica, float cotizacionnuevosol);

//FUNCION PRINCIPAL
main()
{	
	
	float valor,precio,cotizacioneuro,cotizaciondolar,cotizacionreal,cotizacionyen,cotizacionyuan,cotizacionlibrabritanica,cotizacionnuevosol;
	int opcion;
	bool repetir=true;
	
	//BIENVENIDA AL PROGRAMA
	printf ("\n\n\t ***** BIENVENIDOS AL PROGRAMA DE CONVERSION DE MONEDAS *****");
	system ("pause>null");
	system ("cls");
	
	//INGRESO DE COTIZACIONES
	printf ("\n\n\t***** INGRESE COTIZACION DEL EURO *****\n\n\t\t");
	printf (" Cotizacion: %c ",36);
	fflush(stdin);
	scanf ("%f",&cotizacioneuro);
	system("cls");
	printf ("\n\n\t***** INGRESE COTIZACION DEL DOLAR *****\n\n\t\t");
	printf (" Cotizacion: %c ",36);
	fflush(stdin);
	scanf ("%f",&cotizaciondolar);
	system("cls");
	printf ("\n\n\t***** INGRESE COTIZACION DEL REAL *****\n\n\t\t");
	printf (" Cotizacion: %c ",36);
	fflush(stdin);
	scanf ("%f",&cotizacionreal);
	system("cls");
	printf ("\n\n\t***** INGRESE COTIZACION DEL YEN *****\n\n\t\t");
	printf (" Cotizacion: %c ",36);
	fflush(stdin);
	scanf ("%f",&cotizacionyen);
	system("cls");
	printf ("\n\n\t***** INGRESE COTIZACION DEL YUAN *****\n\n\t\t");
	printf (" Cotizacion: %c ",36);
	fflush(stdin);
	scanf ("%f",&cotizacionyuan);
	system("cls");
	printf ("\n\n\t***** INGRESE COTIZACION DE LA LIBRA BRITANICA *****\n\n\t\t");
	printf (" Cotizacion: %c ",36);
	fflush(stdin);
	scanf ("%f",&cotizacionlibrabritanica);
	system("cls");
	printf ("\n\n\t***** INGRESE COTIZACION DEL NUEVO SOL *****\n\n\t\t");
	printf (" Cotizacion: %c ",36);
	fflush(stdin);
	scanf ("%f", &cotizacionnuevosol);
	
	do {
	
	system("cls");
	
	
	//MENU PRINCIPAL
	printf ("\n\n\t******* Seleccione la moneda ******* \n\n ");
	printf ("\t************************************\n");
	printf ("\t* 1) EURO        5) YUAN           *\n");
	printf ("\t* 2) DOLAR       6) LIBRA BRITANICA*\n");
	printf ("\t* 3) REAL        7) NUEVO SOL      *\n");
	printf ("\t* 4) YEN         8) SALIR          *\n");
	printf ("\t************************************\n\n");
	
	//INGRESO POR EL USUARIO DE LA OPCION ELEGIDA
	printf ("\tMoneda: ");
	fflush(stdin);
	scanf ("%d",&opcion);
	if(opcion==8)
	{
		break;
	}
	
	system ("cls");
	
	//INGRESO POR EL USUARIO DEL MONTO A CONVERTIR
	printf ("\n\tIngrese el monto a convertir: %c",36);
	fflush(stdin);
    scanf ("%f", &precio);
	
	switch (opcion){
		case 1: printf ("\n\n\t\t ***** EURO ***** \n");
		        valor= calculo(opcion, precio, cotizacioneuro, cotizaciondolar, cotizacionreal, cotizacionyen, cotizacionyuan, cotizacionlibrabritanica, cotizacionnuevosol);
                printf ("\n\tEl valor es: %c%0.2f pesos \n",36,valor); 
				break;
                
		case 2: printf ("\n\n\t\t ***** DOLAR ***** \n");
		        valor= calculo(opcion,precio,cotizacioneuro,cotizaciondolar,cotizacionreal,cotizacionyen,cotizacionyuan,cotizacionlibrabritanica,cotizacionnuevosol);
		        printf ("\n\tEl valor es: %c%0.2f pesos \n",36,valor); 
				break;
		        
		case 3: printf ("\n\n\t\t ***** REAL ***** \n");
		        valor= calculo(opcion,precio,cotizacioneuro,cotizaciondolar,cotizacionreal,cotizacionyen,cotizacionyuan,cotizacionlibrabritanica,cotizacionnuevosol);
		        printf ("\n\tEl valor es: %c%0.2f pesos \n",36,valor);
		        
		case 4: printf ("\n\n\t\t ***** YEN ***** \n");
		        valor= calculo(opcion,precio,cotizacioneuro,cotizaciondolar,cotizacionreal,cotizacionyen,cotizacionyuan,cotizacionlibrabritanica,cotizacionnuevosol);
		        printf ("\n\tEl valor es: %c%0.2f pesos \n",36,valor); 
				break;
		        
		case 5: printf ("\n\n\t\t ***** YUAN ***** \n");
		        valor= calculo(opcion,precio,cotizacioneuro,cotizaciondolar,cotizacionreal,cotizacionyen,cotizacionyuan,cotizacionlibrabritanica,cotizacionnuevosol);
		        printf ("\n\tEl valor es: %c%0.2f pesos \n",36,valor); 
				break;
		        
		case 6: printf ("\n\n\t\t ***** LIBRA BRITANICA ***** \n");
		        valor= calculo(opcion,precio,cotizacioneuro,cotizaciondolar,cotizacionreal,cotizacionyen,cotizacionyuan,cotizacionlibrabritanica,cotizacionnuevosol);
		        printf ("\n\tEl valor es: %c%0.2f pesos \n",36,valor); 
				break;
		        
		case 7: printf ("\n\n\t\t ***** NUEVO SOL ***** \n");
		        valor= calculo(opcion,precio,cotizacioneuro,cotizaciondolar,cotizacionreal,cotizacionyen,cotizacionyuan,cotizacionlibrabritanica,cotizacionnuevosol);
		        printf ("\n\tEl valor es: %c%0.2f pesos \n",36,valor); 
				break;
		case 8: repetir=false;
		        break;        
		default: printf ("\n\n\t*** INGRESO INCORRECTAMENTE ***");
	}
	
	if (opcion!=8)
	{
	system ("pause>null");
    } 

}while (repetir);


    //MENSAJE PARA FINALIZAR EL PROGRAMA
	system("cls");
	printf ("\n\n\t\t GRACIAS POR USAR NUESTRO PROGRAMA"); 
	system("pause>null");
}



//FUNCION CALCULO
float calculo (int opcion1, float precio, float cotizacioneuro, float cotizaciondolar, float cotizacionreal, float cotizacionyen, float cotizacionyuan, float cotizacionlibrabritanica, float cotizacionnuevosol)
{
	float valorobtenido;
	const int retencion=2;
	
	//CALCULO DE LA CONVERSION SEGUN MONEDA ELEGIDA
	switch (opcion1)
	{
	case 1: valorobtenido= precio*cotizacioneuro;
	break;
	case 2: valorobtenido= precio*cotizaciondolar;
	break;
	case 3: valorobtenido= precio*cotizacionreal;
	break;
	case 4: valorobtenido= precio*cotizacionyen;
	break;
	case 5: valorobtenido= precio*cotizacionyuan;
	break;
	case 6: valorobtenido= precio*cotizacionlibrabritanica;
	break;
	case 7:	valorobtenido= precio*cotizacionnuevosol;
	break;
}

	//CALCULO DE LA RETENCION DE DINERO EN CASO DE SER MAYOR A 10000
	if (valorobtenido>10000){
		valorobtenido= valorobtenido-(valorobtenido*retencion)/100;
	}
	return (valorobtenido);
}
