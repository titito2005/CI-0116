//LUIS EDUARDO ROJAS CARRILLO - B86875
//BSTREE.H
//MÉTODOS E IMPLEMENTACIÓN.
#ifndef BINARY_SEARCH_Tree
#define BINARY_SEARCH_Tree
#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class node{//CLASE PARA NODOS DEL ÁRBOL.
   public:
		T key;//VALOR DEL NODO.
		
		node<T> *p, *left, *right;

		node(){//CONSTRUCTOR VACÍO DEL NODO.
			p=NULL;
			left=NULL;
			right=NULL;	
		};
		
		node(const node<T> * obj, node<T> * padre){
		}

		node(const T& k, node<T> *w = NULL, node<T> *y = NULL, node<T> *z = NULL):key(k), p(w), left(y), right(z){};
		
		~node(){//DESTRUCTOR.
		}
};

template <typename T>
class tree{//CLASE ÁRBOL PARA GUARDAR LOS NODOS.
	public:
		tree(){//CONSTRUCTOR DEL ÁRBOL.
			root= new node<T>();
		};

		tree(const tree<T>& obj){//CONSTRUCTOR POR COPIA.
		};

		~tree(){//DESTRUCTOR DEL ÁRBOL.
			destructor(root);
		};

			
		void inorderTreeWalk(node<T>* x, stack<T> & pila){//RECORRE Y MUESTRA LOS ELEMENTOS DEL ÁRBOL.
			if(x!=NULL){
				inorderTreeWalk(x->left,pila);
				pila.push(x->key);
				inorderTreeWalk(x->right,pila);
			}
		};
			
		node<T>* treeSearch(const T& k){//BUSCADOR DE ELEMENTOS RECURSIVO.
			node<T>* p =recursiveTreeSearch(root, k);
			return p;
		};

		node<T>* iterativeTreeSearch(const T& k){//BUSCADOR DE ELEMENTOS ITERATIVO.
				node<T>* p=root;
			    while (p!=NULL && k!=p->key) {
                if (k<p->key) {
                    p = p->left;
                } else {
                    p = p->right;
                }
		    }
		    return p;
		};
			
		node<T>* treeMinimum(){//BUSCA EL ELEMENTO MINIMO DE LA RAIZ.
			node<T>* p = root;
		    while(p->left!=NULL) {
                p = p->left;
		    }
		    return p;
		};

		node<T>* treeMaximum(){//BUSCA EL ELEMENTO MÁXIMO DE LA RAIZ.
		    node<T>* p = root;
		    while (p->right!=NULL) {
                p = p->right;
		    }
		    return p;
		};

		node<T>* treeSuccessor(const node<T>* x){//BUSCA EL SUCESOR DEL NODO.
			if(x->right!=nil){
				return treeMinimum(x->right);
			}
			
			node<T> *y=x->p;
			while(y!=nil && x==y->right){
				x=y;
				y=y->p;
			}
			return y;
		};

		void treeInsert(node<T>* z){//INSERTA LOS NODO AL ÁRBOL.
			node<T>* y = new node<T>();
		    node<T>* x = root;
		    while (x!=NULL) {
                y = x;
                if (z->key < x->key) {
                    x = x->left;
                } else {
                    x = x->right;
                }
		    }
            z->p = y;

            if (y->p == NULL) {
                root = z;
            } else if(z->key < y->key) {
                y->left = z;
            } else {
                y->right = z;
            }
		};
			
		node<T>* treeDelete(node<T>* z){//BORRA UN NODO DEL ÁRBOL.
			root->p=NULL;
			if (z->left==NULL) {
                transplant(z,z->right);
		    } else {
				if(z->right==NULL) {
					transplant(z,z->left);
				}else{
					node<T>* y = treeMinimum(z->right);
						if (y->p!=z) {
							transplant(y, y->right);
							y->right = z->right;
							y->right->p = y;
						}
					transplant(z,y);
					y->left = z->left;
					y->left->p = y;
				}
			}
		    return root;
		};
	
		node<T> * getRoot() const{//RETORNA LA RAIZ DEL ÁRBOL.
			return this->root;
		};
	
	private:
	
		node<T> *root;//RAIZ DEL ÁRBOL.
		
		void insertOrder(node<T>* z){//MÉTODO TRAMPA PARA INSERTAR NODOS SECUENCIAL.
			if(root->key==NULL){
				root=z;
			}else{			
			node<T> *nodo=root;
			root=z;
			z->right=nodo;
			nodo->p=z;
			}
		};
		
		void transplant(node<T>* z, node<T>* y){//TRANSPLANT PARA BORRAR NODOS.
            if (z->p==NULL){
				root=y;
			}else{ 
				if (z->p->left==z) {
					z->p->left = y;
				}else{
					if(z->p->right==z){
					z->p->right = y;
					}
				}
			}
            if (y!=NULL){
				y->p=z->p;
			}
		};
		
		node<T>* recursiveTreeSearch(node<T>* x, const T& k){//MÉTODO DE BÚSQUEDA RECURSIVO.
            if (x!=NULL && k!=x->key) {
                if (k<x->key) {
					return recursiveTreeSearch(x->left, k);
				}else{
					return recursiveTreeSearch(x->right, k);
				}
            }else{
				return x;
			} 
		};
		
		node<T>* treeMinimum(node<T>* x){//BUSCA EL MÍNIMO DE UN NODO.
			node<T>* p = x;
		    while(p->left!=NULL) {
                p = p->left;
		    }
		    return p;
		};

		node<T>* treeMaximum(node<T>* x){//BUSCA EL MÁXIMO DE UN NODO.	
		    node<T>* p = x;
		    while (p->right!=NULL) {
                p = p->right;
		    }
		    return p;
		};
		
		void destructor(node<T>* x){//DESTRUCTOR RECURSIVO.			
			if(x->left!=NULL){
				destructor(x->left);
			}
			if(x->right!=NULL){
				destructor(x->right);
			}
			delete x;
		}

};
#endif	// BINARY_SEARCH_Tree
