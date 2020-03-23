/*
 * Esta interfaz nos permitirá implementar los métodos en
 * cualquier archivo donde se importen
 */

#ifndef ALGORITMOSREEMPLAZO_H_
#define ALGORITMOSREEMPLAZO_H_

const int OPT = 1;      /* Constante para identificar el algoritmo óptimo */
const int FIFO = 2;     /* Constante para identificar el algoritmo FIFO */
const int LRU = 3;      /* Constante para identificar el algoritmo LRU */
const int BROJO = 12;   /* Constante para el color Rojo */
const int BCYAN = 11;   /* Constante para el color Cyan */
const int NORMAL = 15;  /* Constante para el color por defecto */
void algoritmosReemplazo();
void menu();
void imprimirMatriz();
bool buscar(int paginaActual, int tipo);
void reemplazar(int refActual, int tipo, bool encontrado);
void iniciarMatriz();
void insertarReferencias();
void iniciarFallos();
void copiarEnFila(int pagActual,int refActual);
int masLejanaPasado(int refActual);
int masLejanaFuturo(int refActual);
void printColor(int idColor);
void optimo();
void fifo();
void lru();

#endif /* ALGORITMOSREEMPLAZO_H_ */
