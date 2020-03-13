/*
 * En esta parte del código definiremos todos los algoritmos, junto con algunas
 * funcionalidades necesarias.
 */

#include <iostream>
#include <stdlib.h>
#include "UtilidadesAlgoritmos.h"

const int OPT = 1;   /* Constante para identificar el algoritmo óptimo */
const int FIFO = 2;  /* Constante para identificar el algoritmo FIFO */
const int LRU = 3;   /* Constante para identificar el algoritmo LRU */

using namespace std;


int numPaginas;        /* No. de marcos de página. */
int numReferencias;    /* No. de referencias. */
int *referencias       /* Arreglo que contendrá las referencias ingresadas */
int *fallos;           /* Arreglo para manejar los fallos que se generen */
int **matriz;          /* Matriz que simulará la memoria dinámica */


void algoritmosReemplazo(){
	int opcion;
	printf("Ingrese el Numero de paginas que desea -> ");
	scanf("%d", &numPaginas);
	printf("\n");
	printf("Ingrese el Numero de referencias que desea -> ");
	scanf("%d", &numReferencias);
	printf("\n");
	// Construiremos las matriz con los datos dados por el usuario
	matriz = new int *[numPaginas]; // Filas
		for(int i = 0; i < numPaginas; i++){ // Columnas
			matriz[i] = new int[numReferencias];
		}
	// Construiremos el arreglo de referencias que ingresará el usuario
	referencias = new int[numReferencias];
	// Construiremos el arreglo de fallos
	fallos = new int[numReferencias];
}

/* Método para imprimir la matriz en pantalla */
void imprimeMatriz(){
	for (int i = 0; i < numPaginas; i++){
		printf("PAGINA %d -> ",i+1);
		for (int j = 0; j < numReferencias; j++){
			if (matriz[i][j] == -1){ // imprime blanco para no mostrar el -1
				printf(" \t");
			}else{
				printf("%d\t",matriz[i][j]);
			}
		}
		printf("\n");
	}
}

/* Función para encontrar una referencia dentro de una página (LRU)*/
bool buscar(int paginaActual){
	bool encontrado = false;
	for(int i = 0; i < numPaginas; i++){
		// Si la referencia se encuentra en alguna de la pagina actual entonces
		// cambia la bandera a verdadero
		if(referencias[paginaActual] == matriz[i][paginaActual]){
			encontrado = true;
		}
	}
	return encontrado;
}


