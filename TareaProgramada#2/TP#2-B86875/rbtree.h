//LUIS EDUARDO ROJAS CARRILLO - B86875
//RBTREE.H
//MÉTODOS E IMPLEMENTACIÓN.
#ifndef RED_BLACK_rbtree
#define RED_BLACK_rbtree
#include <stack>
#include <iostream>
#include <String>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

enum colors {RED, BLACK};

template <typename T>
class rbnode{
   public:
		T key;
		rbnode<T> *p, *left, *right;
		
		enum colors color;
		
		rbnode(){
			p=NULL;
			left=NULL;
			right=NULL;
		};

		rbnode(const rbnode<T> * obj, const rbnode<T> * objNil, rbnode<T> * parent, rbnode<T> * nilPtr){
		}

		rbnode (const T& k, rbnode<T> *w = NULL, rbnode<T> *y = NULL, 
				 rbnode<T> *z = NULL, enum colors c = RED):
					key(k), p(w), left(y), right(z), color(c)
		{};
		
		~rbnode(){

		}
};

template <typename T>
class rbtree{
	public:
		rbtree(){
			root= new rbnode<T> ();
			nil= new rbnode<T>();
			nil->color=BLACK;
			root=nil;
			root->p=nil;
			root->left=nil;
			root->right=nil;
			root->color=BLACK;
		};

		rbtree(const rbtree<T>& obj){ 
		};

		~rbtree(){
			destructor(root);
			delete nil;
		};
		
		void inorderTreeWalk(rbnode<T>* x, stack<T> & pila){
				if(x!=nil){
				inorderTreeWalk(x->left,pila);
				if(x->color==BLACK){
					pila.push(1);
				}else{
					pila.push(0);
				}
				pila.push(x->key);
				inorderTreeWalk(x->right,pila);
			}
		};
            

		rbnode<T>* treeSearch(const T& k){
			rbnode<T>* p =recursiveTreeSearch(root, k);
			return p;
		};
			
		rbnode<T>* iterativeTreeSearch(const T& k){
				rbnode<T>* p=root;
			    while (p!=nil && k!=p->key) {
                if (k<p->key) {
                    p = p->left;
                } else {
                    p = p->right;
                }
		    }
		    return p;			
		};
				
		rbnode<T>* treeMinimum(){
			rbnode<T>* p = root;
		    while(p->left!=nil) {
                p = p->left;
		    }
		    return p;
		};
			
		rbnode<T>* treeMaximum(){
		    rbnode<T>* p = root;
		    while (p->right!=nil) {
                p = p->right;
		    }
		    return p;
		};
			
		rbnode<T>* treeSuccessor(const rbnode<T>* x){
			if(x->right!=nil){
				return treeMinimum(x->right);
			}
			
			rbnode<T> *y=x->p;
			while(y!=nil && x==y->right){
				x=y;
				y=y->p;
			}
			return y;
		};
			
		void treeInsert(rbnode<T>* z){
		rbnode<T>* y=nil;
		rbnode<T>* x=root;
		
			while(x!=nil){
				y=x;
				if(z->key<x->key){
					x=x->left;
				}else{
					x=x->right;
				}
			}
		z->p=y;
		
			if(y==nil){
				root=z;
			}else{
				if(z->key<y->key){
					y->left=z;
				}else{
					y->right=z;
				}
			}
			z->left=nil;
			z->right=nil;
			z->color=RED;
			insert_fixup(z);
		};
			
		rbnode<T>* treeDelete(rbnode<T>* z){
		};
			
		rbnode<T> * getRoot() const{
			return this->root;
		};
		
		rbnode<T> * getNil() const{
			return this->nil;
		};
		
			
		private:
	
		rbnode<T> *root;	// raiz del arbol
		rbnode<T> *nil;	    // nodo nil (hoja) del arbol
		
		void leftRotate(rbnode<int> *x){
			rbnode<T> *y;
			y=x->right;
			x->right = y->left;
			if(y->left != nil){
					y->left->p=x;
			}
			y->p=x->p;
			if(x->p==nil){
				root=y;
			}else{
				if(x==x->p->left){
					x->p->left=y;
				}else{
					x->p->right=y;
				}
			}
			y->left=x;
			x->p=y;
		};
		
		void rightRotate(rbnode<int> *x){
			rbnode<T> *y;
			y=x->left;
			x->left = y->right;
			if(y->right != nil){
					y->right->p=x;
			}
			y->p=x->p;
			if(x->p==nil){
				root=y;
			}else{
				if(x==x->p->right){
					x->p->right=y;
				}else{
					x->p->left=y;
				}
			}
			y->right=x;
			x->p=y;
		};
		
		void insert_fixup(rbnode<T> *z){
		rbnode<T>* y=nil;
			while((z->p != nil) && (z->p->color==RED)){
				if(z->p==z->p->p->left){
					y=z->p->p->right;
					if(y->color==RED){
						z->p->color=BLACK;
						y->color=BLACK;
						z->p->p->color=RED;
						z=z->p->p;
					}else{
						if(z==z->p->right){
							z=z->p;
							leftRotate(z);
						}
					z->p->color=BLACK;
					z->p->p->color=RED;
					rightRotate(z->p->p);
					}
				}else{
					y=z->p->p->left;
					if(y->color==RED){
						z->p->color=BLACK;
						y->color=BLACK;
						z->p->p->color=RED;
						z=z->p->p;
					}else{
						if(z==z->p->left){
							z=z->p;
							rightRotate(z);
						}
						z->p->color=BLACK;
						z->p->p->color=RED;
						leftRotate(z->p->p);
					}
						
				}
			}
			root->color=BLACK;
		};
		
		rbnode<T>* recursiveTreeSearch(rbnode<T>* x, const T& k){//MÉTODO DE BÚSQUEDA RECURSIVO.
            if (x!=nil && k!=x->key) {
                if (k<x->key) {
					return recursiveTreeSearch(x->left, k);
				}else{
					return recursiveTreeSearch(x->right, k);
				}
            }else{
				return x;
			} 
		};
		
		rbnode<T>* treeMinimum(rbnode<T>* x){//BUSCA EL MÍNIMO DE UN NODO.
			rbnode<T>* p = x;
		    while(p->left!=nil) {
                p = p->left;
		    }
		    return p;
		};

		rbnode<T>* treeMaximum(rbnode<T>* x){//BUSCA EL MÁXIMO DE UN NODO.	
		    rbnode<T>* p = x;
		    while (p->right!=nil) {
                p = p->right;
		    }
		    return p;
		};
		
		void destructor(rbnode<T>* x){//DESTRUCTOR RECURSIVO.			
			if(x->left!=nil){
				destructor(x->left);
			}
			if(x->right!=nil){
				destructor(x->right);
			}
			delete x;
		};
};

#endif	// RED_BLACK_rbtree
