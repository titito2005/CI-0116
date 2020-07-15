//LUIS EDUARDO ROJAS CARRILLO B86875
//Ordenador.h

#ifndef ORDENADOR_H
#define ORDENADOR_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "time.h"
#include <String>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INFINITO 99999

using namespace std;

class Ordenador{
	public:

	Ordenador();
	~Ordenador();
	void seleccion(int *arreglo, int tamano);
	void insercion(int *arreglo, int tamano);
	void mergesort(int *arreglo, int tamano);	
	void heapsort(int *arreglo, int tamano);
	void quicksort(int *arreglo, int tamano);	
	void radixsort(int *arreglo, int tamano);
	int mediana(int *arreglo, int tamano);
	
///Métodos Adicionales..	
	//private:
	void Merge(int *arreglo, int p, int q, int r);
	void MergeSort(int *arreglo, int p, int r);
	
	void corregir_cima(int *arreglo, int k, int n);
	void monticularizar(int *arreglo, int n);
	int extraer_max(int *arreglo, int n);
	
	void Quicksort(int *arreglo, int p, int q);
	int partition(int *arreglo, int p, int q);
	
	int obtenerMinimo(int *arreglo, int n);
	int getMax(int* arreglo, int n);
	void countsort(int *arreglo, int n, int p);
	
	void muestre(int *arreglo, int tamano);
	void randomVect(int *arreglo, int tamano);	
};
#endif

