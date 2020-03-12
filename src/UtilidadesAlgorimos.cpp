/*
 * Acá definimos las utilidades que nos permitirán controlar
 * las entradas y las salidas de los datos que vayamos ingresando.
 */
#include <iostream>
#include <stdio.h>
/* Definimos constantes para identificar el tipo de algoritmo a los cuales
 * serán sometidos algunos métodos en este programa
 */
const int OPT = 1;
const int FIFO = 2;
const int LRU = 3;
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
		scanf("%d",&referencias[i]);
	}
}

/**
 * Operación que inicia la matriz en la primera columna
 * con los valores: 1, 2, 3, 4.  De lo contrario las llenará con valor -1
 */
void iniciarMatriz(int **mat, int numPaginas, int numReferencias){
	for(int i = 0; i < numPaginas; i++){
		for(int j = 0; j < numReferencias; j++){
			// Inicia los valores en la referencia 1
			if (j == 0){
				switch(i){
				case 0:
					mat[i][j] = 1;
					break;
				case 1:
					mat[i][j] = 2;
					break;
				case 2:
					mat[i][j] = 3;
					break;
				case 3:
					mat[i][j] = 4;
					break;
				}
			}else{
				mat[i][j] = -1;
			}
		}
	}
}



