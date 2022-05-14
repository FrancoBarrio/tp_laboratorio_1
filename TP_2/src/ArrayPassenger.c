#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "Funciones.h"

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int initPassengers(Passenger* list, int len)
{
	int retorno = -1;

	if(len>0 && list != NULL)
	{
		for (int i = 0; i < len ; i++)
		{
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok*/

int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[])
{
	int retorno = -1;
	int espacioLibre;
	if(len>0 && list != NULL)
	{
		if(buscarLibre(list,len)!=-1)
		{
			espacioLibre = buscarLibre(list, len);
			list[espacioLibre].id=id;
			strncpy(list[espacioLibre].name,name,51);
			strncpy(list[espacioLibre].lastName,lastName,51);
			list[espacioLibre].price = price;
			list[espacioLibre].typePassenger = typePassenger;
			list[espacioLibre].statusFlight =0;
			strncpy(list[espacioLibre].flycode,flycode,10);
			list[espacioLibre].isEmpty=0;
			retorno =0;
		}
	}
	return retorno;
}

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id)
{
	int retorno = -1;
	if(len>0 && list != NULL)
	{
		for(int i = 0; i<len ; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id)
{
	int retorno = -1;
	if(len>0 && list != NULL && id > 0)
	{
		char borrar;
		if(findPassengerById(list, len, id)!=-1)
		{
			int IdPasajero = findPassengerById(list, len, id);
			mostrarPasajero(list, IdPasajero);
			utn_getChar("Deseas borrar este pasajero? s-n: ", "Ingrese un caracter correcto", &borrar, 3);
			if(borrar=='s')
			{
				list[IdPasajero].isEmpty=1;
			}
			retorno=0;
		}
	}
	return retorno;
}

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int sortPassengers(Passenger* list, int len, int order)
{
	int retorno = -1;
	int i;
	Passenger bufferPassenger;
	int flagSwap = 1;
	if(list != NULL && len > 0)
	    {
			while(flagSwap)
			{
	            flagSwap = 0;
	            for (i = 0; i < (len - 1); i++)
	            {
	                if(list[i].isEmpty || list[i+1].isEmpty)
	                {
	                    continue;
	                }
	                if(order==1)
	                {
	                	 if(strncmp(list[i].lastName, list[i+1].lastName,51) > 0 ||
						(strncmp(list[i].lastName, list[i+1].lastName,51) == 0 &&
						list[i].typePassenger > list[i+1].typePassenger))
						{
							bufferPassenger = list[i];
							list[i] = list[i+1];
							list[i+1] = bufferPassenger;
							flagSwap = 1;
						}
	                }
	                if(order==0)
					{
						 if( strncmp(list[i].lastName, list[i+1].lastName,51) < 0 ||
						(strncmp(list[i].lastName, list[i+1].lastName,51) == 0 &&
						list[i].typePassenger > list[i+1].typePassenger))
						{
							bufferPassenger = list[i];
							list[i] = list[i+1];
							list[i+1] = bufferPassenger;
							flagSwap = 1;
						}
					}

	             }
	         }
	        retorno = 0;
	    }
	    return retorno;
}

int sortPassengersPorCodigoDeVuelo(Passenger* list, int len)
{
	int retorno = -1;
	int i;
	Passenger bufferPassenger;
	int flagSwap = 1;
	if(list != NULL && len > 0)
	    {
			while(flagSwap)
			{
	            flagSwap = 0;
	            for (i = 0; i < (len - 1); i++)
	            {
	                if(list[i].isEmpty || list[i+1].isEmpty)
	                {
	                    continue;
	                }

	                if(strncmp(list[i].flycode, list[i+1].flycode,51) > 0)
					{
						bufferPassenger = list[i];
						list[i] = list[i+1];
						list[i+1] = bufferPassenger;
						flagSwap = 1;
					}
	            }
	            retorno=0;
			 }
		 }
		return retorno;
}


/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/


int printPassenger(Passenger* list, int length)
{
	int retorno=-1;
	if(list != NULL && length >= 0 )
	{
		for(int i = 0; i < length; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				mostrarPasajero(list,i);
				retorno =0;
			}
		}
	}
	return retorno;
}


int mostrarPasajero(Passenger* list,int indice)
{
	int retorno = -1;

	if(list != NULL && indice >= 0 )
	{
		if(list[indice].isEmpty==0)
		{
			printf("Id:%d - Nombre: %s - apellido: %s - precio :%.2f - flycode: %s typePassenger:%d ",
			list[indice].id,list[indice].name,list[indice].lastName,list[indice].price,list[indice].flycode,list[indice].typePassenger);
			if(list[indice].statusFlight == 0)
				printf("estado de vuelo: Desactivado \n");
			else
				printf("estado de vuelo: Activo  \n");
			retorno = 0;
		}
	}
	return retorno;
}



int buscarLibre(Passenger* list, int len)
{
	int retorno = -1;

	if(len>0 && list != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/*

	MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
	o Precio o Tipo de pasajero o Código de vuelo
 */



int modificarPasajero(Passenger* list,int len, int id)
{
	int retorno = -1;
	int switchNumber;
	Passenger bufferPassenger;
	int auxId;


	if(list != NULL && len >= 0 && id>0)
	{
			auxId=findPassengerById(list, len, id);

			if(auxId!=-1)
			{
				mostrarPasajero(list, auxId);
				bufferPassenger = list[auxId];
				printf("Test");
				printf("\nQue desea cambiar\n1-Nombre\n2-apellido\n3-precio\n4-Tipo de pasajero\n5-Codigo de vuelo\n6-salir");
				fflush(stdin);
				printf("Test");
				scanf("%d",&switchNumber);

				switch (switchNumber)
				{
					case 1:
						if(utn_getNombre("\nIngrese nombre = ","\nError ingrese un nombre correcto",bufferPassenger.name,2,51)==0)
						{
							strncpy(list[auxId].name , bufferPassenger.name,51);
							retorno =0;
						}
						break;
					case 2:
						if(utn_getNombre("\nIngrese apellido = ","\nError ingrese un apellido correcto",bufferPassenger.lastName,2,51) == 0 )
						{
							strncpy(list[auxId].lastName ,bufferPassenger.lastName,51);
							retorno =0;
						}
						break;
					case 3:
						if(utn_getFloat("\nIngrese un precio = ", "\nError ingrese un valor correcto (0-9999999)", &bufferPassenger.price, 0, 9999999, 2)== 0)
						{
							list[auxId].price = bufferPassenger.price;
							retorno =0;
						}
						break;
					case 4:
						if(utn_getInt("\nIngrese el Tipo de pasajero = ", "\n", &bufferPassenger.typePassenger, 2, 2, 0) ==0)
						{
							list[auxId].typePassenger = bufferPassenger.typePassenger;
							retorno =0;
						}
						break;
					case 5:
						if(utn_getNombre("\nIngrese un codigo de vuelo = ","\nError ingrese un codigo de vuelo correcto",bufferPassenger.flycode,2,10) ==0)
						{
							strncpy(list[auxId].flycode , bufferPassenger.flycode,10);
							retorno =0;
						}
						break;
					case 6:
						printf("salio exitosamente del modificar\n ");
						break;
					default:
						printf("\nOpcion invalida!!\n\n");
						break;
				}
		}
	}
	return retorno;
}




/*
 *
 *
 * 2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
promedio.
 */


int informeDos(Passenger* list,int len)
{

	int retorno = -1;
	int total=0;
	int cantidadDePasajeros=0;
	int pasajerosPorAribaDelPromedio=0;
	if(len>0 && list != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				total= total + list[i].price;
				cantidadDePasajeros++;
			}
		}

		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].price>(total/cantidadDePasajeros))
			{
				pasajerosPorAribaDelPromedio++;
			}
		}

		printf("La ganancia total es: %d\n", total);
		printf("El promedio de los precios de los pasajes es: %d\n", total/cantidadDePasajeros);
		printf("Los pasajeros por arriba del promedio son: %d\n", pasajerosPorAribaDelPromedio);

	}
	return retorno;
}


int printPassengerState(Passenger* list, int length)
{
	int retorno=-1;
	if(list != NULL && length >= 0 )
	{
		for(int i = 0; i < length; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].statusFlight==1)
			{
				mostrarPasajero(list,i);
				retorno =0;
			}
		}
	}
	return retorno;
}







int menu()
{
    int opcion;
    printf("\n----------------------------------------");
    printf("\n                Menu                      \n");
    printf("1-Ingresar pasajero\n");
    printf("2-Modificar pasajero\n");
    printf("3-Baja pasajero\n");
    printf("4-Informes\n");
    printf("5-Salir\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int informes()
{
    int respuesta;

    printf("                INFORMES                \n\n");
    printf("1-Listado de pasajeros\n");
    printf("2-Total y promedio salarios\n");
    printf("3-Pasajeros por codigo de vuelo y vuelos activos\n");
    printf("4-Salir\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &respuesta);

    return respuesta;
}




