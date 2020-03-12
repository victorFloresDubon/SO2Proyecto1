/*
 * Acá definimos las utilidades que nos permitirán controlar
 * las entradas y las salidas de los datos que vayamos ingresando.
 */
#include <iostream>
#include <stdio.h>
/* Definimos constantes para identificar el tipo de algoritmo a los cuales
 * serán sometidos algunos métodos en este programa
 */
#define OPT  1;
#define FIFO 2;
#define LRU  3;
using namespace std;

/*
 * Método para imprimir la matriz en pantalla.
 *
 * mat        -> Apuntador a la matriz actual.
 * numPaginas -> No. de marcos de página, esto servirá como límite para las filas.
 * numPaginas -> No. de referencias, esto servirá como límite para las columnas.
 */
void imprimeMatriz(int **mat, int numPaginas, int numReferencias){
	for(int i = 0; i < numPaginas; i++){
		printf("PAGINA %d -> ",i+1);
		for(int j = 0; j < numReferencias; j++){
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
}
/*
 * Método que nos permite ir insertando las referencias.
 *
 * referencias    -> Vector al cual insertaremos dichas referencias.
 * numReferencias ->  No. de referencias, esto servirá como límite para el bucle.
 */
void insertarReferencias(int *referencias, int numReferencias){
	for(int i = 0; i < numReferencias; i++){
		printf("Inserte la referencia No. %d -> ",i+1);
		scanf("%d",referencias[i]);
	}
}


