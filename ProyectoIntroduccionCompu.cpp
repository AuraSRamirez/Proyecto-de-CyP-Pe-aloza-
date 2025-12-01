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
    * 
    * 3
    */
        else
        {
            strcpy_s(szSuggest[1], szPalabraLeida);
        }

    /* 3. Sustitución */

    for (i = 0; i < iSize; i++)
    {
        for (n = 0; n < ALFABETO; n++)
        {
            strcpy_s(szSuggest[iNumSNeto], szPalabraLeida);
            szSuggest[iNumSNeto][i] = szLetras[n];
            iNumSNeto++;
        }
    }



    /* 4. Adición */

    for (i = 0; i < iSize + 1; i++)
    {
        for (n = 0; n < ALFABETO; n++)
        {
            szSuggest[iNumSNeto][i] = szLetras[n];
            k = 0;
            for (j = 0; j < iSize + 2; j++)
            {
                if (j == iSize + 1)
                    szSuggest[iNumSNeto][j] = '\0';
                else
                {
                    if (j != i)
                    {
                        szSuggest[iNumSNeto][j] = szPalabraLeida[k];
                        k++;
                    }
                }
            }
            iNumSNeto++;
        }
    }

    /* Reducción de terminos antes de ordenar */
/*
    for (i = 0; i < iNumSNeto; i++)
    {
        iSize = strlen(szSuggest[i]);
        for (n = 0; n < iSize; n++)
        {
            if (n != iSize - 1)
                szSuggest[i][n] = szSuggest[i][n + 1];
            else
                szSuggest[i][n] = '\0';
        }
    }
*/
/* ------------El paso de reducción no deberia existir----------- */

/* Ordenar Resultados */
    iNumRep = 0;
    iNumSugeridas = 0;
    bLogrep = 0;
    /*  Buscar repetidos, llenar la cadena sin dichos términos y contar el total de términos   */

    for (i = 0; i < iNumSNeto; i++)//Bucle for que va de 0 (el primer valor de un arreglo) al numero total de elementos
    {
        //Evaluador de términos repetidos en el bucle local
        for (n = 0; n < iNumRep; n++)//Bucle for de 0 al número de términos repetidos
        {                                       //Nos permite agilizar y hacer eficiente la busqueda de términos iguales
            if (i == m_a[n])//En caso de que se repitan
            {
                bLogrep = bLogrep + 1;//bLog_rep es la variable que va de 0 a 1 y nos indica si hay terminos reoetidos
                n = iNumRep;//al detectar que el término evaluado en el for global es un termino repetido detiene el bucle local
            }
            else
                bLogrep = 0;
        }
        //El código solo va a modificar valores cuando estos no se repitan
        if (bLogrep == 0)//==0 indica que el valor con posición del contador global no es repetido
        {

            //Compara el término en la posición de la variable local con todos los demás del arreglo
            for (n = i + 1; n < iNumSNeto; n++)//bucle que va de el término en variable global +1 al numero total de terminos
            {                                         //de esta manera evitamos volver a evaluar términos  

                if (szSuggest[i][0] == '\0')//En caso de que ambos términos seain iguales
                {
                    m_a[iNumRep] = n;//se guarda la posición del termino repetido en el arreglo maestro
                    iNumRep = iNumRep + 1;//variable que guarda la cantidad de terminos repetidos
                }
            }
            strcpy_s(szPalabrasSugeridas[iNumSugeridas], szSuggest[i]);
            iNumSugeridas = iNumSugeridas + 1;//Lleva la cuenta de los términos
        }
    }

    /*  Ordenar de menor a mayor   */

    for (i = 0; i < iNumSugeridas - 1; i++)//bucle que va de 0 a n-1 términos
    {
        k = 0;//La variable n nos va a permitir detectar si el proceso de ordenamiento terminó antes de n-1 repeticiones
        for (n = 0; n < iNumSugeridas - 1; n++)//bucle que va de 0 a n-1 términos
        {
            if (strcmp(szPalabrasSugeridas[n + 1], szPalabrasSugeridas[n]) < 0)//comparacion de ambos terminis
            {   //si el término en n+1 es menor que el termino en n:
               //Se cambian de lugar
                strcpy_s(szPalabra, szPalabrasSugeridas[n + 1]);
                strcpy_s(szPalabrasSugeridas[n + 1], szPalabrasSugeridas[n]);
                strcpy_s(szPalabrasSugeridas[n], szPalabra);
            }
            else//en caso de no ser menor se le agrega una unidad a la variable n
                k += 1;
        }
        if (k == iNumSugeridas - 1)//cuando la variable n tenga el mismo valor que terminos-1 el arreglo se ha ordenado
            i = iNumSugeridas - 1;//y por lo tanto el proceso puede terminarse
    }

    /*
    *
    for (i = 0; i < iNumSugeridas; i++)
    {
        printf("\n%s", szPalabrasSugeridas[i]);
    }
    printf("\n%i", iNumSugeridas);
    //Sustituya estas lineas por su código
    strcpy(szPalabrasSugeridas[0], szPalabraLeida); //lo que sea que se capture, es sugerencia
    iNumSugeridas = 1;							//Una sola palabra sugerida */
}