//LUIS EDUARDO ROJAS CARRILLO - B86875
//HASHT.H
//MÉTODOS E IMPLEMENTACIÓN.
#ifndef HASH_CLASS
#define HASH_CLASS
#include <list>
#include <vector>
#include <iostream>
#include <String>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

template <typename T>

class hasht{
	public:
		// Constructor que especifica el numero de cubetas (entradas) 
		// en la tabla
		hasht(int nEntradas){
			numEntradas = nEntradas;
		    tabla.resize(numEntradas);
		};
			
		// Constructor copia	
		hasht(const hasht<T>& obj){ 
		};
			
		// Destructor (borra la tabla)
		~hasht(){
			for (auto &i : tabla){
				i.clear();
            }
			tabla.clear();			
		};
			
		// Retorna un puntero a la llave o NULL si no se encuentra
		T* search(const T& item){
			bool encontrado = false;
			int posicion = demePos(item);
		    list<int> valor = tabla.at(posicion);

            for (auto it=valor.begin(); ((it != valor.end()) && (encontrado==false)); ++it){
                if (item==*(it)){
                    encontrado = true;
                    return &*it;
                }
            }
			return nullptr;
		};
			
		// Inserta el elemento en la tabla
		void insert(const T& item){
			tabla[demePos(item)].push_back(item);
		};
					

	private:
		// Numero de entradas en la tabla
		int numEntradas;

		// La tabla es un vector de listas de STL
		vector<list<T> > tabla;

		int demePos(int x) {
            return (x % numEntradas);
		}
};
#endif
