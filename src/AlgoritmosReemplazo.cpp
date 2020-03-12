/*
 * AlgoritmosReemplazo.cpp
 *
 *  Created on: 11/03/2020
 *      Author: Rolando
 */

#include <iostream>
#include <stdlib.h>
#include "UtilidadesAlgoritmos.h"

using namespace std;

int **matriz,*paginas,*fallos;

void lru(int numPaginas,int numReferencias){
	/* Creamos la matriz que representa la memoria asignada */
	matriz = new int *[numPaginas];
	for (int i = 0; i < numPaginas; i++){
		matriz[i] = new int[numReferencias];
	}
	/* Seguidamente creamos las referencias que vayamos a ingresar */
	paginas = new int[numReferencias];
	/* Adicional, también creamos el vector para manejar los fallos */
	fallos = new int[numReferencias];
	/* Insertamos las referencias*/
	insertarReferencias(paginas,numReferencias);
	imprimeMatriz(matriz,numPaginas,numReferencias);

}


