#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "Funciones.h"

//&pResultado
//*Resultado

int utn_getInt(char* mensaje,char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo)
{
	int retorno = -1;
	int bufferInt;
	int resultadoScanf;
	if(
			mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			maximo >= minimo)
	{
		do
		{
			printf("%s",mensaje);
			resultadoScanf = scanf("%d" , &bufferInt);
			if(resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

int utn_getChar(char* mensaje, char* mensajeError, char* pResultado,int reintentos)
{
	int retorno = -1;
	char bufferChar;
	int resultadoScanf;
	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 )
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin); // fflush // __fpurge
			resultadoScanf = scanf("%c" , &bufferChar);
			if(resultadoScanf == 1 && (bufferChar == 's' || bufferChar == 'n'))
			{
				retorno = 0;
				*pResultado = bufferChar;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}


int utn_getNombre(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite)
{
	char bufferString[51];
	int retorno = -1;

	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			limite > 0)
	{
		do
		{
			printf("%s",mensaje);
			if( myGets(bufferString,51) == 0 &&
				strnlen(bufferString,sizeof(bufferString)-1)<= limite &&
				esUnNombreValido(bufferString,limite) != 0 )
			{
				retorno = 0;
				//NO EXISTE pResultado = bufferString;
				strncpy(pResultado,bufferString,limite);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);

	}
	return retorno;
}
	int myGets(char *cadena, int longitud)
	{
		fflush(stdin);
		fgets (cadena, longitud, stdin);
		cadena[strlen (cadena) - 1] = '\0';
		return 0;
	}

	int esUnNombreValido(char* cadena,int limite)
	{
		int respuesta = 1; // TODO OK
		for(int i=0; i<=limite && cadena[i] != '\0';i++)
		{
			//esta mal <----- A - Z -----> Esta mal
			if(	(cadena[i] < 'A' || cadena[i] > 'Z') &&
				(cadena[i] < 'a' || cadena[i] > 'z') &&
				cadena[i] != '.')
			{
				respuesta = 0;
				break;
			}
		}
		return respuesta;
	}

	int utn_getFloat(char* mensaje,char* mensajeError,float* pResultado,float minimo,float maximo,int reintentos)
	{
		int retorno = -1;
		float bufferFloat;
		int resultadoScan;
		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0){
			do{
				printf("%s", mensaje);
				fflush(stdin);
				resultadoScan = getFloat(&bufferFloat);
				if(resultadoScan && minimo <= bufferFloat && maximo >= bufferFloat){
					*pResultado = bufferFloat;
					retorno = 0;
					break;
				}else{
					printf("%s", mensajeError);
					printf("\n-REINTENTOS: %d \n",reintentos);
					reintentos--;
				}

			}while(reintentos >= 0);
		}
		return retorno;
	}

	int getFloat(float* pFloat){
		int retorno = 0;
		char bufferFloat[64];
		if(pFloat != NULL){
			fflush(stdin);

			if(!myGets(bufferFloat,sizeof(bufferFloat)) && esFlotante(bufferFloat,sizeof(bufferFloat)))
			{
				*pFloat = atof(bufferFloat);
				retorno = 1;
			}
		}
		return retorno;
	}

	int esFlotante(char* array,int limite){
		int retorno = -1;
		int i = 0;
		int contadorDePuntos = 0;

		if(array != NULL && limite > 0){
			retorno = 1;
			if(array[0] != '+' || array[0] != '-'){
				i = 1;
			}
			while(array[i] != '\0'){
				if((array[i] < '0' || array[i] > '9') && array[i] != '.'){
					retorno = 0;
					break;
				}
				if(array[i] == '.'){
					contadorDePuntos++;
					if(contadorDePuntos > 1){
						retorno = 0;
						break;
					}
				}
				i++;
			}
		}
		return retorno;
	}
	int utn_getAviso(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite)
	{
		char bufferString[51];
		int retorno = -1;

		if(		mensaje != NULL &&
				mensajeError != NULL &&
				pResultado != NULL &&
				reintentos >= 0 &&
				limite > 0)
		{
			do
			{
				printf("%s",mensaje);
				if( myGets(bufferString,51) == 0 &&
					strnlen(bufferString,sizeof(bufferString)-1)<= limite
					)
				{
					retorno = 0;
					//NO EXISTE pResultado = bufferString;
					strncpy(pResultado,bufferString,limite);
					break;
				}
				else
				{
					printf("%s",mensajeError);
					reintentos--;
				}
			}while(reintentos >= 0);

		}
		return retorno;

	}
