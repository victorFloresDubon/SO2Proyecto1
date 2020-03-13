/*
 * En esta parte del código definiremos todos los algoritmos, junto con algunas
 * funcionalidades necesarias.
 */

#include <iostream>
#include <stdlib.h>
#include "AlgoritmosReemplazo.h"


using namespace std;

void menu();
void imprimirMatriz();
bool buscar(int paginaActual);
void iniciarMatriz();
void insertarReferencias();

int numPaginas;        /* No. de marcos de página. */
int numReferencias;    /* No. de referencias. */
int *referencias;      /* Arreglo que contendrá las referencias ingresadas */
int *fallos;           /* Arreglo para manejar los fallos que se generen */
int **matriz;          /* Matriz que simulará la memoria dinámica */


void algoritmosReemplazo(){
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
	iniciarMatriz();
	// Construiremos el arreglo de referencias que ingresará el usuario
	referencias = new int[numReferencias];
	// Construiremos el arreglo de fallos
	fallos = new int[numReferencias];

	menu();
}

/* Muestra el menú de selección */
void menu(){
	int opc;
	do{
		system("cls");
		printf("Algoritmos de Reemplazo de paginas\n");
		printf("===================================\n");
		printf("\n");
		printf("Escoja el algoritmo que desea ejecutar\n");
		printf("\t1. Optimo\n");
		printf("\t2. FIFO\n");
		printf("\t3. LRU\n");
		printf("\t4. Salir\n");
		printf("\t-> ");
		scanf("%d",&opc);
		switch(opc){
		case OPT: //Algoritmo Optimo
			system("cls");
			printf("Algoritmo Optimo\n");
			printf("===============================\n");
			insertarReferencias();
			break;
		case FIFO:
			system("cls");
			printf("\t\tAlgoritmo Ultimo en Entrar Primero en Salir (FIFO)\n");
			printf("======================================================\n");
			insertarReferencias();
			break;
		case LRU:
			system("cls");
			printf("Algoritmo Ultimo Recientemente Usado (LRU)\n");
			printf("==================================================\n");
			insertarReferencias();
			break;
		}
	}while(opc!=4);
	printf("Gracias, vuelva pronto!\n");
	system("PAUSE");
}

/* Método para imprimir la matriz en pantalla */
void imprimirMatriz(){
	//Imprime el vector de las referencias
	printf("REFERENCIAS -> ");
	for (int i = 0; i < numReferencias; i++){
		printf("%d\t",referencias[i]);
	}
	printf("\n");
	//Imprime la matriz
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
	printf("\n");
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

/**
 * Operación que inicia la matriz en la primera columna
 * con los valores: 1, 2, 3, 4.  De lo contrario las llenar� con valor -1
 */
void iniciarMatriz(){
	for(int i = 0; i < numPaginas; i++){
		for(int j = 0; j < numReferencias; j++){
			// Inicia los valores en la referencia 1
			if (j == 0){
				switch(i){
				case 0:
					matriz[i][j] = 1;
					break;
				case 1:
					matriz[i][j] = 2;
					break;
				case 2:
					matriz[i][j] = 3;
					break;
				case 3:
					matriz[i][j] = 4;
					break;
				}
			}else{
				matriz[i][j] = -1;
			}
		}
	}
}

/*
 * Método que nos permite ir insertando las referencias.
 *
 */
void insertarReferencias(){
	for(int i = 0; i < numReferencias; i++){
		printf("Inserte la referencia No. %d -> ",i+1);
		scanf("%d",&referencias[i]);
		printf("\n");
		imprimirMatriz();
	}
}

