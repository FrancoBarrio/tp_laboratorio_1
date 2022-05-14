

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#define TRUE 1
#define FALSE 0


typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;


int menu();
int informes();
int initPassengers(Passenger* list, int len);
int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[]);
int findPassengerById(Passenger* list, int len,int id);
int mostrarPasajero(Passenger* list,int indice);
int removePassenger(Passenger* list, int len, int id);
int printPassenger(Passenger* list, int length);
int modificarPasajero(Passenger* list,int len, int id);
int buscarLibre(Passenger* list, int len);
int informeDos(Passenger* list,int len);
int sortPassengers(Passenger* list, int len, int order);
int sortPassengersPorCodigoDeVuelo(Passenger* list, int len);
int printPassengerState(Passenger* list, int length);
#endif
