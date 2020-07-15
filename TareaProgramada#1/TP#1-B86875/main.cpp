//LUIS EDUARDO ROJAS CARRILLO B86875
//main.cpp

#include "Ordenador.h"
#include <iostream>
#include <String>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
clock_t start, end;
int tam=200000;
int vect[tam];


Ordenador orde;

orde.randomVect(vect, tam);
orde.muestre(vect, tam);
start = clock(); 
orde.heapsort(vect,tam);
end = clock();
orde.muestre(vect, tam);
double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl;
	
for(int i=1; i<tam; i++){
	if( vect[i] < vect[i -1] ){
    cout<<"¡Falló!";
	}	
}
return 0;
}
