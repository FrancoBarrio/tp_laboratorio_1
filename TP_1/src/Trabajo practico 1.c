/*
 ============================================================================
 Name        : Trabajo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main(void)
{
	setbuf(stdout,NULL);

	float kilometros = 0;
	int numero = 0;
	int bandera = 0;
	float auxKilometraje = 0;
	float auxLatam = 0;
	float auxAerolineas = 0;
	float precioLatam = 0;
	float precioAerolineas = 0;
	int banderaCase2=0;
	int banderaCase3=0;
	float descuentoDebitoLatam = 0;
	float aumentoCreditoLatam = 0;
	float btc = 4606954.55;
	float precioBtcLatam = 0;
	float precioUnitarioLatam = 0;
	float diferenciaPrecio = 0;

	float descuentoDebitoAero = 0;
	float aumentoCreditoAero = 0;
	float precioBtcAero = 0;
	float precioUnitarioAero = 0;

	while(bandera==0)
	{

		printf("\nIngrese un numero del 1-6 \n");
		printf("1-Para ingresar kilometros (%.2f KM)\n",kilometros);
		printf("2-Para ingresar precio de vuelos Aerolineas:($%.2f) - Latam:($%.2f)\n",precioAerolineas, precioLatam);
		printf("3-Para calcular las operaciones\n");
		printf("4-Para informar los resultados\n");
		printf("5-Carga forzada de datos\n");
		printf("6-Salir\n");

		numero= IngresarNumeroInt("Numero a ingresar: ", 1, 6);
		fflush(stdin);

	    switch(numero)
	    {
	        case 1:
	        	auxKilometraje = IngresarNumeroFloat("Ingresar kilometros: ",0,999999);
	        	if(auxKilometraje>0)
	        	{
	        		kilometros=auxKilometraje;
	        	}
	        	else
	        	{
	        		printf("Ingrese un kilometraje correcto \n");
	        	}
	        break;
	        case 2:
	        	auxAerolineas = IngresarNumeroFloat("Ingresar Precio Aerolineas:",0,999999);
	        	auxLatam = IngresarNumeroFloat("Ingresar Precio Latam: ",0,999999 );

	        	if(auxLatam>0 && auxAerolineas>0)
	        	{
	        		precioLatam = auxLatam;
	        		precioAerolineas = auxAerolineas;
	        		banderaCase2++;
	        	}
	        	else
	        	{
	        		printf("\nSe ingreso un precio de vuelo invalido\n");
	        	}

	        break;
	        case 3:
	        	if(banderaCase2>0)
	        	{
	        		descuentoDebitoLatam = precioLatam * 0.90;
	        		aumentoCreditoLatam = precioLatam * 1.25;
	        		precioBtcLatam  = precioLatam / btc;
	        		precioUnitarioLatam = precioLatam / kilometros;
	        		diferenciaPrecio = precioLatam - precioAerolineas;

	        		descuentoDebitoAero = precioAerolineas * 0.90;
	        		aumentoCreditoAero = precioAerolineas * 1.25;
	        		precioBtcAero  = precioAerolineas / btc;
	             	precioUnitarioAero = precioAerolineas / kilometros;

	        		banderaCase3++;
	        		printf("Se calcularon los precios correctamente, ahora precione 4\n\n");
	        	}
	        	else
	        	{
	        		printf("\n Ingresar precios de vuelos");
	        	}

	        break;
	        case 4:
	        	if(banderaCase3 == 1)
	        	{
	        		MostrarResultados(kilometros,precioAerolineas,descuentoDebitoAero,aumentoCreditoAero,precioBtcAero,
									  precioUnitarioAero,precioLatam,descuentoDebitoLatam,aumentoCreditoLatam,precioBtcLatam,
									  precioUnitarioLatam,diferenciaPrecio);
	        	}
	        	else
	        	{
	        		printf("\n Ingrese los precios o calculelos antes");
	        	}

			break;
	        case 5:
	        		kilometros = 7090;
	        		precioAerolineas = 162965;
	        		precioLatam = 159339;

					descuentoDebitoLatam = precioLatam * 0.90;
					aumentoCreditoLatam = precioLatam * 1.25;
					precioBtcLatam  = precioLatam / btc;
					precioUnitarioLatam = precioLatam / kilometros;
					diferenciaPrecio = precioLatam - precioAerolineas;

					descuentoDebitoAero = precioAerolineas * 0.90;
					aumentoCreditoAero = precioAerolineas * 1.25;
					precioBtcAero  = precioAerolineas / btc;
					precioUnitarioAero = precioAerolineas / kilometros;

					MostrarResultados(kilometros,precioAerolineas,descuentoDebitoAero,aumentoCreditoAero,precioBtcAero,
									  precioUnitarioAero,precioLatam,descuentoDebitoLatam,aumentoCreditoLatam,precioBtcLatam,
									  precioUnitarioLatam,diferenciaPrecio);

	        	break;
	        case 6:
				bandera=1;
				break;

			default:
				printf("\nIngrese un dato correcto entre 1-6\n");
				break;
	    }
	}
}



















