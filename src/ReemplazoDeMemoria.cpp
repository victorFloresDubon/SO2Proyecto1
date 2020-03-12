//============================================================================
// Name        : ReemplazoDeMemoria.cpp
// Author(s)   : Selvin Castellanos, Victor Flores
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "AlgoritmosReemplazo.h"
#include "UtilidadesAlgoritmos.h"

using namespace std;
/* No. de marcos de página. */
int numPaginas;
/* No. de referencias. */
int numReferencias;
/* Arreglo que contendrá las referencias ingresadas */
//int *paginas;
/* Matriz que simular� la memoria dinmica, el es tamaño definido por
 * el usuario por medio de
 */

/*
void iniciarMatriz(int **matriz){
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

void imprimirMatrizPrincipal(int **matriz){
	for(int i = 0; i < numPaginas; i++){
		printf("Pagina %d -> ",i+1);
		for(int j = 0; j < numReferencias; j++){
			printf("%d\t",matriz[i][j]);
		}
		printf("\n");
	}
}

void insertaReferencia(){
	for(int i = 0; i < numPaginas; i++){
		printf("Ingrese la referencia No. %d -> ",i+1);
		scanf("%d",&paginas[i]);
	}
}
*/
void menu(){
//	int **matriz;

	int opc;
	do{
		printf("Algoritmos de Reemplazo de paginas\n");
		printf("===================================\n");
		printf("\n");
		printf("Escoja el algoritmo que desea ejecutar\n");
		printf("1.\t\t Optimo\n");
		printf("2.\t\t FIFO\n");
		printf("3.\t\t LRU\n");
		printf("4.\t\t Salir\n");
		printf("-> ");
		scanf("%d",&opc);
		if (opc != 4){
			printf("Ingrese el Numero de paginas que desea -> ");
			scanf("%d", &numPaginas);
			printf("\n");
			printf("Ingrese el Numero de referencias que desea -> ");
			scanf("%d", &numReferencias);
			printf("\n");
			switch(opc){
			case 1:

				break;
			case 2:
				break;
			case 3:
				lru(numPaginas,numReferencias);
				break;
			default:
				printf("Opcion no existe.\n;");
				system("cls");

			}
			// Llena la matriz
/*			paginas = new int [numPaginas];
			matriz = new int *[numPaginas];
			   for (int i = 0;i < numPaginas;i++ ){
				   matriz[i]= new int [numReferencias];
			   }
			iniciarMatriz(matriz);
*/
			/* Imprime la matriz */
		}else{
			printf("Gracias, vuelva pronto\n");
		}
	}while(opc!=4);
	system("PAUSE");
}



int main() {
	menu();
	return 0;
}


