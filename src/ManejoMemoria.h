/*
 * Esta interfaz nos permitirá implementar las variables que
 * se usarán en cada uno de los algoritmos, ya que todas inician con
 *
 *
 *  - Número de Marcos en memoria o referencias
 *  - Número de páginas
 *  - Páginas reservadas en memoria
 *  - La memoria reservada para los marcos o
 */

#ifndef MANEJOMEMORIA_H_
#define MANEJOMEMORIA_H_

int numPaginas, numMarcos, paginas [], memoria[][], fallos[];

void lru();
bool buscar(int referencia, int mat[][]);
void imprimirMatriz(int matriz[][]);
#endif /* MANEJOMEMORIA_H_ */
