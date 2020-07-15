//LUIS EDUARDO ROJAS CARRILLO B86875
//Ordenador.cpp

#include "Ordenador.h"
#define INFINITO 99999

Ordenador::Ordenador(){
}

Ordenador::~Ordenador(){
}

void Ordenador::seleccion(int *arreglo, int tamano){//ORDENAMIENTO POR SELECCIÓN.
  for(int i=0; i<tamano-1;i++){
	  int menor=i;
	  for(int j=i+1; j<tamano; j++){
		  if(arreglo[j]<arreglo[menor]){
			  menor=j;
		    }
	    }
	  int temp=arreglo[i];
	  arreglo[i]=arreglo[menor];
	  arreglo[menor]=temp;
    } 
}

void Ordenador::insercion(int *arreglo, int tamano){//ORDENAMIENTO POR INSERCIÓN.
    for(int j=1; j<tamano; j++){
        int llave=arreglo[j];
		int i=j-1;
        while(i>=0 && arreglo[i]>llave){
            arreglo[i+1]=arreglo[i];           
            i=i-1;
        }
		arreglo[i+1]=llave;
    }
}

void Ordenador::mergesort(int *arreglo, int tamano){//MÉTODO QUE INICIA MERGESORT.
	MergeSort(arreglo,0,tamano-1);
}

void Ordenador::MergeSort(int *arreglo, int p, int r){//ORDENAMIENTO POR MERGESORT.
	if(p<r){
		int q=((p+r)/2);
		MergeSort(arreglo,p,q);
		MergeSort(arreglo,q+1,r);
		Merge(arreglo,p,q,r);				
	}
}

void Ordenador::Merge(int *arreglo, int p, int q, int r){//MÉTODO MERGE.
	int n1=q-p+1;
	int n2=r-q;
	
	int izq[n1+1];	
	int der[n2+1];

	izq[n1]=INFINITO;
	der[n2]=INFINITO;
	
	for(int i=0; i<n1; i++){
	    izq[i]=arreglo[p+i];
	}
	
	for(int i=0; i<n2; i++){
		der[i]=arreglo[q+i+1];
	}
	
	int i=0;
	int j=0;
	
	for(int k=p;k<=r;k++){
		
		if(izq[i]<der[j]){
			arreglo[k]=izq[i];
			i++;
		}else{
			arreglo[k]=der[j];
			j++;
		}
	}	
}

void Ordenador::heapsort(int *arreglo, int tamano){//MÉTODO HEAPSORT
	monticularizar(arreglo,tamano-1);
	int i=tamano-1;
	while(i>=0){
		arreglo[i]=extraer_max(arreglo,i);
		i--;
	}
	
}

void Ordenador::corregir_cima(int *arreglo, int k, int n){//CORREGIR CIMA PARA HEAPSORT
	int j;
	if(arreglo[2*k]>arreglo[2*k+1]){
		j=2*k;
	}else{
		j=2*k+1;
	}
	
	if(arreglo[j]>arreglo[k]){
		int temp=arreglo[k];
		arreglo[k]=arreglo[j];
		arreglo[j]=temp;
		if(j*2+1<=n){
		corregir_cima(arreglo,j,n);
		}
	}
}
	
void Ordenador::monticularizar(int *arreglo, int n){//MONTICULARIZAR PARA HEAPSORT
	for(int i=(n/2);i>=0;i--){
		corregir_cima(arreglo,i,n);
	}
}

int Ordenador::extraer_max(int *arreglo, int n){//EXTRAER MÁXIMO PARA HEAPSORT
	int m;
	m=arreglo[0];
	arreglo[0] = arreglo[n];
	corregir_cima(arreglo, 0, n);
    return m;
}

int Ordenador::partition(int * arreglo, int p, int r){//PARTITION PARA QUICKSORT
    int x = arreglo[r];
    int i = p-1;
    for (int j=p; j<=r-1; j++) {
        if (arreglo[j]<=x) {
            i++;
            int t1 = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = t1;
        }
    }
    int t2 = arreglo[i+1];
    arreglo[i+1] = arreglo[r];
    arreglo[r] = t2;
    return (i + 1);
}

void Ordenador::Quicksort(int * arreglo, int p, int r){//MÉTODO ALGORITMO QUICKSORT
    if (p<r) {
        int q = partition(arreglo, p, r);
        Quicksort(arreglo,p, q-1);
        Quicksort(arreglo, q+1, r);
    }

}

void Ordenador::quicksort(int * arreglo, int tamano){//MÉTODO QUEE INICIALIZA QUICKSORT
    Quicksort(arreglo, 0, tamano-1);
}

int Ordenador::obtenerMinimo(int *arreglo, int n){//OBTENER MÍNIMO PARA RADIXSORT
    int menor=arreglo[0];
    for(int i=1;i<n;i++){
        if(menor>arreglo[i]){
            menor=arreglo[i];
        }

    }
    return menor;
}

int Ordenador::getMax(int *arreglo, int n) { //GET MAX PARA RADIXSORT
    int max=arreglo[0]; 
    for (int i = 1; i < n; i++){ 
        if (arreglo[i] > max){ 
            max = arreglo[i]; 
		}		
	}	
    return max; 
} 
  
void Ordenador::countsort(int *arreglo, int n, int exp){//COUNTSORT PARA RADIXSORT
    int output[n];
    int i, count[10] = {0}; 
    for (i = 0; i < n; i++){
        count[ (arreglo[i]/exp)%10 ]++; 
	}
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1]; 
	}
    for (i = n - 1; i >= 0; i--) { 
        output[count[ (arreglo[i]/exp)%10 ] - 1] = arreglo[i]; 
        count[ (arreglo[i]/exp)%10 ]--; 
    }  
    for (i = 0; i < n; i++) {
        arreglo[i] = output[i]; 
	}
} 
  

void Ordenador::radixsort(int* arreglo, int tamano){//MÉTODO RADIXSORT
   int valor= abs(obtenerMinimo(arreglo,tamano));
    for(int i=0;i<tamano;i++){
        arreglo[i]=arreglo[i]+valor;
	}
    int m = getMax(arreglo, tamano); 
    for (int exp = 1; m/exp > 0; exp *= 10) {	
        countsort(arreglo, tamano, exp); 
	}
    for(int i=0;i<tamano;i++){
        arreglo[i]=arreglo[i]-valor;
	}
}
///Métodos Extra::

void Ordenador::muestre(int *arreglo, int tamano){//ADICIONAL, MUESTRA LOS VECTORES.
    for (int i=0; i<tamano; i++){
        printf("%i  \n",arreglo[i]);
    }
    printf("\n");
}

void Ordenador::randomVect(int *arreglo, int tamano){//ADICIONAL, GENERA VECTORES CON VALORES ALEATORIOS ENTRE -1000 Y 1000.
    srand (time(NULL));
    for (int i=0; i<tamano; i++){
        arreglo[i]=(-1000)+(int)(((1000-(-1000)+1.0)*rand())/(RAND_MAX+1.0));
    }
}
