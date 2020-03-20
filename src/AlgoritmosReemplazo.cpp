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
bool buscar(int paginaActual, int tipo);
void iniciarMatriz();
void insertarReferencias();
void iniciarFallos();

int numPaginas;        /* No. de marcos de página. */
int numReferencias;    /* No. de referencias. */
int *referencias;      /* Arreglo que contendrá las referencias ingresadas */
int *fallos;           /* Arreglo para manejar los fallos que se generen */
int **matriz;          /* Matriz que simulará la memoria dinámica */
int *distacia;         /* Arrelgo que tendrá el No. de referencia a tomar para reemplazo
                          en el algoritmo LRU*/

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
			matriz[i] = new int[numReferencias+1];
		}
	iniciarMatriz();
	// Construiremos el arreglo de referencias que ingresará el usuario
	referencias = new int[numReferencias];
	// Construiremos el arreglo de fallos e iniciamos el vector
	fallos = new int[numReferencias+1];
	iniciarFallos();
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
			//system("PAUSE");
			break;
		}
	}while(opc!=4);
	printf("Gracias, vuelva pronto!\n");
	system("PAUSE");
}

/**
 * Inicia el vector de fallos en -1
 */
void iniciarFallos(){
	for(int i = 0; i < numReferencias+1; i++){
		fallos[i] = -1;
	}
}

/**
 * Operación que inicia la matriz en la primera columna
 * con los valores: 1, 2, 3, 4.  De lo contrario las llenar� con valor -1
 */
void iniciarMatriz(){
	for(int i = 0; i < numPaginas; i++){
		for(int j = 0; j < numReferencias+1; j++){
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
		//printf("\n");
	}
	printf("\n");
	imprimirMatriz();
}

/* Método para imprimir la matriz en pantalla */
void imprimirMatriz(){
	//Imprime el vector de las referencias
	printf("REFERENCIAS ->\t");
	for (int i = -1; i < numReferencias; i++){
		if (i != -1){
			printf("%d\t",referencias[i]);
		}else{
			printf("\t");
		}
	}
	printf("\n");
	//Imprime la matriz
	for (int i = 0; i < numPaginas; i++){
		printf(" PAGINA %d ->\t",i+1);
		for (int j = 0; j < numReferencias+1; j++){
			if (matriz[i][j] == -1){ // imprime blanco para no mostrar el -1
				printf(" \t");
			}else{
				printf("%d\t",matriz[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
	//Imprime el vector de los fallos
	printf("FALLOS ->\t");
	//printf("-\t");
	for (int i = 0; i < numReferencias+1; i++){
		if(fallos[i] == -1 ){
			printf("-\t");
		}else{
			printf("X\t");
		}
	}

	printf("\n");
	system("PAUSE");
}

/* Función para encontrar una referencia dentro de una página, dependiendo el tipo de
 * algoritmo que se le indique
 *
 */
bool buscar(int refActual, int tipo){
	bool encontrado = false;
	switch(tipo){
	case 1:
		break;
	case FIFO:
		break;
	case LRU:
		for(int i = 0; i < numPaginas; i++){
			// Si la referencia se encuentra en alguna de la pagina actual entonces
			// cambia la bandera a verdadero
			if(referencias[refActual] == matriz[i][refActual]){
				encontrado = true;
			}
		}
		break;
	}
	return encontrado;
}
/*
 * Copia la columna anterior para poder aplicar la búsqueda de cada referencia
 */
void copiarColumnaAnterior(int refActual){
	for(int i = 0; i < numPaginas; i++){
		matriz[i][refActual] = matriz[i][refActual-1];
	}
}
/*
 * Método que reemplazará el valor encontrado, dependiendo el tipo de algoritmo
 * tomará un comportamiento distinto
 */
void reemplazar(int refActual){
	bool marcoLibre = false;// Bandera de marco libre para reemplazo
	int i;
	for(i = 0; i < numPaginas; i++){
		// Si el marco es igual a -1 entonces está libre
		if(matriz[i][refActual] == -1){
			marcoLibre = true;
			break;
		}
	}
	// Si no se encontró un marco libre
	// reemplazará con el más antiguo en ser liberado
	if(!marcoLibre){

	}else{
		//copiarColumna(refActual, i);
	}
}
//============================================================================//
//                          ALGORITMOS DE REEMPLAZO                           //
//============================================================================//
/* Algoritmo Menos Usado Recientemente (Least Recently Used, LRU) */
void lru(){
	for(int j = 1; j < numReferencias+1; j++){
		// Si no lo encuentra entonces lo reemplaza
		if(!buscar(j,LRU)){
			reemplazar(j);
		}else{
			copiarColumnaAnterior(j);
		}
	}
}


