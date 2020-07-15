//LUIS EDUARDO ROJAS CARRILLO - B86875
//LLIST.H
//DECLARACIÓN Y DEFINICIÓN DE MÉTODOS.
#ifndef LINKED_LIST_llist
#define LINKED_LIST_llist
#include <iostream>
#include <stdio.h>

using namespace std;

template <typename T>
class llnode{//CLASE LLNODE, NODOS PARA INGRESAR EN LA LISTA.
   public:

		T key;//VALOR DEL NODO.
		llnode<T> *prev, *next;//PUNTERO AL ANTERIOR Y SIGUIENTE.
	
		llnode(){//CONSTRUCTOR VACÍO DEL NODO.	
			prev=NULL;
			next=NULL; 
		};
		
		llnode (const T& k, llnode<T> *w = NULL, llnode<T> *y = NULL):key(k), prev(w), next(y){//CONSTRUCTOR.	
		};
		
		~llnode(){//DESTRUCTOR.
		};
};

template <typename T>
class llist{//CLASE LLIST, ESTRUCTURA PARA GUARDAR NODOS.
	public:
		llist(){//CONSTRUCTOR.
			nil= new llnode<T>();
		};	
		
		llist(const llist<T>& obj){//CONSTRUCTOR POR COPIA.
		};		
		
		~llist(){//DESTRUCTOR.
			llnode<T> *p=nil;
			if(p->next!=NULL){
				p=p->next;
			}
			while(p!=nil){
				p=p->next;
				delete p->prev;
			}
			delete p;
		};						
		
		llnode<T>* listSearch(const T& k){//BUSCA UN VALOR.
			llnode<T> *p;
			p=nil->next;
			while((p!=nil)&&(p->key!=k)){
				p=p->next;
			}		
			return p;
		};		
			
		
		void listInsert(llnode<T> *x){//INSERTA UN NODO.		
			if(nil->next==NULL){
				x->next=nil;
				x->prev=nil;
				nil->next=x;
				nil->prev=nil;
			}else{
				x->next=nil->next;
				nil->next->prev=x;
				nil->next=x;
				x->prev=nil;
			}			
		};		
	
		
		llnode<T>* listDelete(llnode<T>* x){//BORRA UN NODO.
			x->prev->next=x->next;
			x->next->prev=x->prev;
			return x;
		};	
	
		
		llnode<T> * getNil() const{//RETORNA NILL.
			return this->nil;
		};
				
		private:
	
		llnode<T> *nil;//NODO CENTINELA.
};

#endif	// LINKED_LIST_llist
