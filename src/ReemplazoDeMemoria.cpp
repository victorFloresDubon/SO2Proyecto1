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


using namespace std;

void menu(){

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
	}while(opc!=4);
	system("PAUSE");
}



int main() {
	menu();
	return 0;
}


