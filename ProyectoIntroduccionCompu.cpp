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

    iNumElementos = 0; j = 0;
    szCaracter = fgetc(stream);
    while (feof(stream) == 0)
    {
        if (!((szCaracter == 9) || (szCaracter == 10) || (szCaracter == 13) || (szCaracter == 32) || (szCaracter == 41) || (szCaracter == 44) || (szCaracter == 46) || (szCaracter == 59) || (szCaracter == 40)))
        {
            szRecibePalabras[iNumElementos][j] = tolower((char)szCaracter);
            szCaracter = fgetc(stream);
            j++;

        }
        else
        {
            if (j > 0)
            {
                szRecibePalabras[iNumElementos][j] = '\0';
                iEstadisticas[iNumElementos] = 1;

                if (iNumElementos > 0)
                {
                    for (i = 0; i < iNumElementos; i++)
                        if (strcmp(szRecibePalabras[i], szRecibePalabras[iNumElementos]) == 0)
                        {
                            iEstadisticas[i] = iEstadisticas[i] + 1;
                            i = iNumElementos;
                            iNumElementos = iNumElementos - 1;
                        }
                }

                iNumElementos++;
                j = 0;
            }
            szCaracter = fgetc(stream);
        }
    }
    fclose(stream);

    szRecibePalabras[iNumElementos][j] = '\0';
    iEstadisticas[iNumElementos] = 1;

    for (i = 0; i < iNumElementos; i++)
        if (strcmp(szRecibePalabras[i], szRecibePalabras[iNumElementos]) == 0)
        {
            iEstadisticas[i] = iEstadisticas[i] + 1;
            strcpy_s(szRecibePalabras[iNumElementos], "");
            i = iNumElementos;
        }

    for (i = 0; i < iNumElementos; i++)
    {
        iSegurofin = 0;
        for (j = 0; j < iNumElementos; j++)
        {
            if (strcmp(szRecibePalabras[j + 1], szRecibePalabras[j]) < 0)
            {
                strcpy_s(szControl, szRecibePalabras[j]);
                iControl = iEstadisticas[j];
                strcpy_s(szRecibePalabras[j], szRecibePalabras[j + 1]);
                iEstadisticas[j] = iEstadisticas[j + 1];
                strcpy_s(szRecibePalabras[j + 1], szControl);
                iEstadisticas[j + 1] = iControl;
            }
            else
                iSegurofin += 1;
        }
        if (iSegurofin == iNumElementos)
            i = iNumElementos;
    }

    if (strcmp(szRecibePalabras[0], "") == 0)
    {
        for (i = 0; i < iNumElementos; i++)
        {
            strcpy_s(szPalabras[i], szRecibePalabras[i + 1]);
            iEstadisticas[i] = iEstadisticas[i + 1];
        }
        iEstadisticas[i] = '\0';
    }
    else
    {
        iNumElementos++;
        for (i = 0; i < iNumElementos; i++)
            strcpy_s(szPalabras[i], szRecibePalabras[i]);
    }
    /*
        printf("Elementos en el diccionario: %i", iNumElementos);

        fopen_s(&stream, "datos.csv", "w");
        if (stream == NULL)
            exit(0);

        for(i=0;i<iNumElementos;i++)
            fprintf(stream,"\n%s, %i", szPalabras[i],iEstadisticas[i]);

        fclose(stream);
    */
    //Sustituya estas lineas por su código
    /*