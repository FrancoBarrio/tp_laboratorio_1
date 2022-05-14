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
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "Funciones.h"


int main(void)
{
	setbuf(stdout,NULL);
	char seguir='s';
	int flag = 0;
	int id =1;
	Passenger pasajeros[2000];
	initPassengers(pasajeros, 2000);
	int ordenamiento;
	char name[51];
	char lastName[51];
	float price;
	int typePassenger;
	char flycode[10];

	  do
		{

			switch (menu())
			{
				case 1:
					utn_getNombre("\nIngrese un nombre: ", "\nError", name, 2, 51);
					utn_getNombre("\nIngrese un apellido: ", "\nError", lastName, 2, 51);
					utn_getFloat("\nIngrese un precio: ", "\nError", &price, 1, 5000, 2);
					utn_getInt("\nIngrese el tipo de pasajero: ", "\nError", &typePassenger, 2, 2, 0);
					utn_getNombre("\nIngrese un codigo de vuelo: ", "\nError", flycode, 2, 10);



					if(addPassenger(pasajeros, 2000, id, name, lastName, price, typePassenger, flycode)==0)
					{
						id++;
						printf("Se ingreso correctaqmente el pasajero");
						flag++;
					}else
					{
						printf("hubo un problema al ingresar el pasajero");
					}

					break;
				case 2:
					if(flag>0)
					{
						int usuarioAModificar;
						printPassenger(pasajeros, 2000);
						utn_getInt( "Que usuario deseas modificar?", "Ingrese un numero valido (0-2000)", &usuarioAModificar, 3, 2000, 0);
						if(modificarPasajero(pasajeros, 2000, usuarioAModificar)==0)
						{
							printf("Se cambio correctamente el pasajero");
						}else
						{
							printf("No hubo cambios realizados");
						}
					}

					break;
				case 3:
					if(flag>0)
					{
						int usuarioAEliminar;
						printPassenger(pasajeros, 2000);
						utn_getInt( "Que usuario deseas eliminar?", "Ingrese un numero valido (0-2000)", &usuarioAEliminar, 3, 2000, 0);
						if(removePassenger(pasajeros, 2000, usuarioAEliminar)==0)
						{
							printf("Se elimino correctamente el pasajero");
						}else
						{
							printf("hubo un problema al eliminar el pasajero");
						}

					}
					break;

				case 4:
					if(flag>0)
					{
						switch (informes())
						{
								case 1:

									utn_getInt( "Como deseas ordernar(0 de mayor a menor) (1 de menor a mayor) ?", "Ingrese un numero valido (0-1)", &ordenamiento, 3, 1, 0);
									sortPassengers(pasajeros, 2000, ordenamiento);
									printPassenger(pasajeros, 2000);

									break;
								case 2:
									informeDos(pasajeros, 2000);
									break;
								case 3:
									sortPassengersPorCodigoDeVuelo(pasajeros, 2000);
									printPassengerState(pasajeros, 2000);
									break;
								default:
									printf("\nOpcion invalida!!\n\n");
									break;
						}
					}
							break;
				case 5:
					system("cls");
					seguir='n';
				break;

					default:
					system("cls");
					printf("\nIngrese opcion correcta\n\n");
					break;

			 }
		                fflush(stdin);
		            }while (seguir=='s');

	return EXIT_SUCCESS;
}
