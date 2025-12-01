// ProyectoIntroduccionCompu.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
/*****************************************************************************************************************
	UNIVERSIDAD NACIONAL AUTONOMA DE MEXICO
	FACULTAD DE ESTUDIOS SUPERIORES -ARAGON-

	Computadoras y programacion.
	(c) Ponga su nombre y numero de cuenta aqui.

	Quiso decir: Programa principal de la aplicacion de la distancia de Levenstein.

******************************************************************************************************************/


#include "stdafx.h"
#include <string.h>
#include "corrector.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ALFABETO 32


//Funciones publicas del proyecto
/*****************************************************************************************************************
	DICCIONARIO: Esta funcion crea el diccionario completo
	char *	szNombre				:	Nombre del archivo de donde se sacaran las palabras del diccionario
	char	szPalabras[][TAMTOKEN]	:	Arreglo con las palabras completas del diccionario
	int		iEstadisticas[]			:	Arreglo con el numero de veces que aparecen las palabras en el diccionario
	int &	iNumElementos			:	Numero de elementos en el diccionario
******************************************************************************************************************/
void	Diccionario(char* szNombre, char szPalabras[NUMPALABRAS][TAMTOKEN], int iEstadisticas[NUMPALABRAS], int& iNumElementos)
{
	FILE* stream;
	char szRecibePalabras[NUMPALABRAS][TAMTOKEN];
	char szControl[TAMTOKEN];
	int  szCaracter, i, j, iSegurofin, iControl;

	fopen_s(&stream, szNombre, "r");
	if (stream == NULL)
		exit(0);