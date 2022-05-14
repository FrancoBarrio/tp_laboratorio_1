#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int utn_getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo);
int utn_getChar(char* mensaje, char* mensajeError, char* pResultado,int reintentos);
int utn_getNombre(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);
int myGets(char *cadena, int longitud);
int esUnNombreValido(char* cadena,int limite);
int utn_getFloat(char* mensaje,char* mensajeError,float* pResultado,float minimo,float maximo,int reintentos);
int getFloat(float* pFloat);
int esFlotante(char* array,int limite);
int utn_getAviso(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);
#endif
