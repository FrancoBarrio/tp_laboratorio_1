/*
 * funciones.c
 *
 *  Created on: Apr 15, 2022
 *      Author: Franc
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void MostrarResultados(float kilometros,float precioAerolineas,float descuentoDebitoAero,float aumentoCreditoAero,
						float precioBtcAero,float precioUnitarioAero,float precioLatam,float descuentoDebitoLatam,
						float aumentoCreditoLatam,float precioBtcLatam,float precioUnitarioLatam,float diferenciaPrecio)
{
	printf("\n KMs Ingresados: (%.2f)",kilometros);
	printf("\n\n Precio Aerolineas: ($%.2f)",precioAerolineas);
	printf("\n a) Precio con tarjeta de debito: ($%.2f)",descuentoDebitoAero);
	printf("\n b) Precio con tarjeta de credito: ($%.2f)",aumentoCreditoAero);
	printf("\n c) Precio pagado con bitcoin: (%.6f BTC)",precioBtcAero);
	printf("\n d) Mostrar precio unitario: ($%.2f)",precioUnitarioAero);

	printf("\n\n Precio Latam: ($%.2f)",precioLatam);
	printf("\n a) Precio con tarjeta de debito: ($%.2f)",descuentoDebitoLatam);
	printf("\n b) Precio con tarjeta de credito: ($%.2f)",aumentoCreditoLatam);
	printf("\n c) Precio pagado con bitcoin: (%.6f BTC)",precioBtcLatam);
	printf("\n d) Mostrar precio unitario: ($%.2f)",precioUnitarioLatam);

	printf("\n\n La diferencia de precio es: ($%.2f)",diferenciaPrecio);
}


float IngresarNumero(char* string, float minimo, float maximo)
{
	float aux = 0;
	float resultado = -1;
	printf("%s",string);
	int check = scanf("%f", &aux);

	if(check == 1 &&( aux > minimo && aux < maximo))
	{
		resultado = aux;
	}
	return resultado;
}
