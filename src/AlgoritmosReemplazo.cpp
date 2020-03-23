/*
 * En esta parte del código definiremos todos los algoritmos, junto con algunas
 * funcionalidades necesarias.
 */

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <windows.h>
#include "AlgoritmosReemplazo.h"

using namespace std;

int numPaginas;        /* No. de marcos de página. */
int numReferencias;    /* No. de referencias. */
int *referencias;      /* Arreglo que contendrá las referencias ingresadas */
int *fallos;           /* Arreglo para manejar los fallos que se generen */
int **matriz;          /* Matriz que simulará la memoria dinámica */
int *distancia;        /* Arreglo contador de distancia entre páginas para LRU*/
int pagSiguiente = 0;  /* Variable que inicia en la primera página para el algoritmo FIFO */
bool libre = false;    /* Bandera para indicar que un bloque se encuentra libre */


void algoritmosReemplazo(){
	system("color F");
	do{
		printf("Ingrese el Numero de paginas que desea -> ");
		scanf("%d", &numPaginas);
		if(numPaginas <= 0){
			printf("Debe ingresar numero mayor que cero\n");
		}
	}while(numPaginas <= 0);
	printf("\n");
	do{
		printf("Ingrese el Numero de referencias que desea -> ");
		scanf("%d", &numReferencias);
	}while(numReferencias <= 0);
	printf("\n");
	// Construiremos las matriz con los datos dados por el usuario
	matriz = new int *[numPaginas]; // Filas
		for(int i = 0; i < numPaginas; i++){ // Columnas
			// añadimos +1 a las columnas debido a la columna inicializada
			// que se manejará, esto va para la matriz como para los fallos
			matriz[i] = new int[numReferencias+1];
		}
	// Construiremos el arreglo de referencias que ingresará el usuario
	referencias = new int[numReferencias];
	// Construiremos el arreglo de fallos e iniciamos el vector
	fallos = new int[numReferencias+1];
	// Iniciamos el contador de distancias
	distancia = new int[numPaginas];

	iniciarMatriz();
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
			optimo();
			break;
		case FIFO:
			system("cls");
			printf("Algoritmo Ultimo en Entrar Primero en Salir (FIFO)\n");
			printf("======================================================\n");
			insertarReferencias();
			fifo();
			break;
		case LRU:
			system("cls");
			printf("Algoritmo Ultimo Recientemente Usado (LRU)\n");
			printf("==================================================\n");
			insertarReferencias();
			lru();
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
 * Operación que inicia la matriz en todas sus
 * posiciones en: 1, 2, 3 y 4
 */
void iniciarMatriz(){
	for(int i = 0; i < numPaginas; i++){
		for(int j = 0; j < numReferencias+1; j++){
			// Inicia los valores en las páginas respectivas
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
			default:
				matriz[i][j] = -1;
			}
		}
	}
	iniciarFallos();
}

/*
 * Método que nos permite ir insertando las referencias.
 *
 */
void insertarReferencias(){
	for(int i = 0; i < numReferencias; i++){
		printf("Inserte la referencia No. %d -> ",i+1);
		scanf("%d",&referencias[i]);
	}
	printf("\n");
}

/* Método para imprimir la matriz en pantalla */
void imprimirMatriz(){
	//Imprime el vector de las referencias
	printf("REFERENCIAS ->\t");
	for (int i = -1; i < numReferencias; i++){
		if (i != -1){
			printColor(BCYAN);
			printf("%d\t",referencias[i]);
			printColor(NORMAL);
		}else{
			printf("\t");
		}
	}
	printf("\n");printf("\n");
	//Imprime la matriz
	for (int i = 0; i < numPaginas; i++){
		printf(" PAGINA %d ->\t",i+1);
		for (int j = 0; j < numReferencias+1; j++){
			if (matriz[i][j] == -1){ // imprime blanco para no mostrar el -1
				printf(" \t");
			}else{
				// Pintamos el cambio de página
				if (j != 0 && matriz[i][j] != matriz[i][j-1]){
					printColor(BROJO);
					printf("%d\t",matriz[i][j]);
					printColor(NORMAL);
				}else{
					printf("%d\t",matriz[i][j]);
				}
			}
		}
		printf("\n");
	}
	printf("\n");
	//Imprime el vector de los fallos
	printf("FALLOS ->\t");
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

/* Función para encontrar una referencia dentro de una página.
 *
 */
bool buscar(int refActual){
	bool encontrado = false;
	//Recorre las páginas
	for(int i = 0; i < numPaginas; i++){
		// Si la referencia se encuentra en alguna de las páginas
		// la bandera cambia su estado a verdadero.
		if(referencias[refActual] == matriz[i][refActual+1]){
			encontrado = true;
		}
	}
	return encontrado;
}
/*
 * Método que reemplazará el valor encontrado, dependiendo el tipo de algoritmo
 * tomará un comportamiento distinto.  Además de agregar una bandera con valor
 * por defecto en falso, esto servirá para el algoritmo FIFO
 */
void reemplazar(int refActual, int tipo, bool encontrado = false){
	int i;
	switch(tipo){
	case OPT:
		libre = false;
		//Buscamos un espacio libre en las páginas
		for(i = 0; i < numPaginas; i++){
			if(matriz[i][refActual+1] == -1){
				libre = true;
//				break;
			}
		}
		if(libre){
			copiarEnFila(i-1,refActual);
		}else{
			// Verificamos que tengamos las referencias suficientes
			// para las páginas que manejamos
			if(!((numReferencias-refActual)<numPaginas)){
				// Si se cumple, entonces aplicamos el cambio
				copiarEnFila(masLejanaFuturo(refActual),refActual);
			}else{
				// Sino copiaremos la que tiene más tiempo en ejecución
				copiarEnFila(masLejanaPasado(refActual),refActual);
			}
		}
		//Registra el fallo de la memoria
		fallos[refActual+1] = 0;
		break;
	case FIFO:
		libre = false;
		// Si no se encontró la referencia entonces aplica el reemplazo
		// desde la referencia actual.
		if (!encontrado){
			// Si existe un espacio libre entonces llena la fila
			for(i = 0; i < numPaginas; i++){
				if(matriz[i][refActual+1] == -1){
					libre = true;
					break;
				}
			}
			if (libre){
				// Si encuentra un marco libre lo copia en la fila
				for(int j = refActual; j < numReferencias; j++){
					matriz[i][j+1] = referencias[refActual];
				}

			}else{
				for(int j = refActual; j < numReferencias; j++){
					matriz[pagSiguiente][j+1] = referencias[refActual];
				}
				// Mueve a la siguiente página
				pagSiguiente++;
				// Si ya se recorrió todas las páginas volvemos a la primera
				if(pagSiguiente==numPaginas){
					pagSiguiente = 0;
				}
			}
			//Registra el fallo de la memoria
			fallos[refActual+1] = 0;
		}
		break;
	case LRU:
		libre = false;
		//Buscamos un espacio libre en las páginas
		for(i = 0; i < numPaginas; i++){
			if(matriz[i][refActual+1] == -1){
				libre = true;
//				break;
			}
		}
		// Si encontramos un espacio libre entonces
		// llenaremos la fila entera con la referencia ingresada,
		// a la página se le quirará -1 para evitar desbordamiento.
		if (libre){
			copiarEnFila(i-1,refActual);
		}else{
			// Sino reemplazará la página menos usada recientemente a partir
			// de la referencia actual.
			copiarEnFila(masLejanaPasado(refActual),refActual);
		}
		//Registra el fallo de la memoria
		fallos[refActual+1] = 0;
		break;
	}
}
/*
 * Copia la fila desde la página y marco de referencia actual
 */
void copiarEnFila(int pagActual,int refActual){
	for(int j = refActual; j < numReferencias; j++){
		matriz[pagActual][j+1] = referencias[refActual];
	}
}

/*
 * Éste método retornará la referencia más antigua en ser liberada
 */
int masLejanaPasado(int refActual){
	int refMasAntigua = 0;
	// Recorre las páginas
	for(int i = 0; i < numPaginas; i++){
		// Retrocede en las referencias pasadas a partir de la actual
		for(int j = refActual; j >= 0; j--){
			if(matriz[i][refActual+1] == referencias[j]){
				// Guarda en memoria la distancia entre la referencia actual
				// y la anterior usada.
				distancia[i] = refActual-j;
				break;
			}else{
				distancia[i] = j;
			}
		}
	}
	// Compara la distancia de la página más antigua
	for(int i = 0; i < numPaginas; i++){
		if(distancia[i]>distancia[refMasAntigua]){
			refMasAntigua = i;
		}
	}
	return refMasAntigua;
}
/*
 * Este método retorna la página más lejana a ser referenciada a futuro
 */
int masLejanaFuturo(int refActual){
	int paginaFutura = 0;
	// Recorre las páginas
	for (int i = 0; i < numPaginas; i++){
		// Recorre las referencias a partir de la actual, en adelante
		for(int j = refActual; j < numReferencias; j++){
			if(matriz[i][refActual+1] == referencias[j]){
				// Guarda la distancia entre la referencia futura y la actual
				distancia[i] = j-refActual;
				break;
			}
		}
	}
	//Encuentra la página más distante a futuro
	for(int i = 0; i < numPaginas; i++){
		if(distancia[i] > distancia[paginaFutura]){
			paginaFutura = i;
		}
	}
	return paginaFutura;
}

void printColor(int idColor){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), idColor);
}
//============================================================================//
//                          ALGORITMOS DE REEMPLAZO                           //
//============================================================================//
/* Algoritmo Óptimo */
void optimo(){
	for(int j = 0; j < numReferencias; j++){
		if (!buscar(j)){
			reemplazar(j,OPT);
		}
	}
	imprimirMatriz();
	iniciarMatriz();
}
/* Algoritmo Primero en Entrar, Primero en Salir (First In First Out, FIFO) */
void fifo(){
	for(int j = 0; j < numReferencias; j++){
		reemplazar(j,FIFO,buscar(j));
	}
	imprimirMatriz();
	iniciarMatriz();
}
/* Algoritmo Menos Usado Recientemente (Least Recently Used, LRU) */
void lru(){
	for(int j = 0; j < numReferencias; j++){
		// Si no lo encuentra entonces lo reemplaza
		if(!buscar(j)){
			reemplazar(j,LRU);
		}
	}
	imprimirMatriz();
	iniciarMatriz();
}
