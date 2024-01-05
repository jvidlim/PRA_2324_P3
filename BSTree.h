#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

using namespace std;

template <typename T> class BSTree{

	private:
		int nelem;
		BSNode<T> *root;

		BSNode<T>* search(BSNode<T>*n, T e) const{
			if(n == nullptr) throw runtime_error("Elemento no encontrado");
			else if(e < n->elem) return search(n->left, e);
			else if(e > n->elem) return search(n->right, e);
			else return n;
		}

		BSNode<T>* insert(BSNode<T>*& n, T e) {
    			if (n == nullptr) {
        			n = new BSNode<T>(e, nullptr, nullptr);
        			this->nelem++;
        			return n;
    			} else if (e > n->elem) {
        			return insert(n->right, e);
    			} else if (e < n->elem) {
        			return insert(n->left, e);
    			} else {
        			throw runtime_error("Elemento ya en el arbol");
    			}
		}		

		
		void print_inorder(ostream &out, BSNode<T> *n){
			if(n == nullptr) return;
			print_inorder(out, n->left);
			out << " ";
			out << *n;
			out << " ";
			print_inorder(out, n->right);
			out << " ";
		}

		BSNode<T>* remove(BSNode<T>*& n, T e) {
		    if (n == nullptr) {
			throw runtime_error("No existe el nodo");
		    }

		    if (e > n->elem) {
			n->right = remove(n->right, e);
		    } else if (e < n->elem) {
			n->left = remove(n->left, e);
		    } else {
			if (n->left != nullptr && n->right != nullptr) {
			    T maxLeft = max(n->left);
			    n->elem = maxLeft;
			    n->left = remove(n->left, maxLeft);
			} else {
			    BSNode<T>* temp = n;
			    n = (n->left != nullptr) ? n->left : n->right;
			    delete temp;
			    nelem--;
			}
		    }

		    return n;
		}	

		T max(BSNode<T>* n)const{
			if(n == nullptr) throw runtime_error("No existe el nodo");
			BSNode<T>* aux = n;
			if(aux->right != nullptr) return max(aux->right);
			else return aux->elem;
		}

		BSNode<T>* remove_max(BSNode<T>* n){
			if(n->right != nullptr) return remove_max(n->right);
			else return n->left;
		}

		void delete_cascade(BSNode<T>*n){
			if(n == nullptr) return;
			delete_cascade(n->left);
			delete_cascade(n->right);
			delete n;
		}


	public:
		BSTree(){
			nelem = 0;
			root = nullptr;
		}

		~BSTree(){
			delete_cascade(root);		
		}

		int size() const{
			return nelem;
		}

		T search(T e){
			BSNode<T>* res = search(root, e);
			return res->elem;			
		}

		T operator[](T e) const{
			return search(e);
		}

		void insert(T e){
			insert(root, e);
		}

		friend ostream&operator<<(ostream &out, BSTree<T> &bst){
			bst.print_inorder(out, bst.root);
			return out;
		}

		void remove(T e){
			remove(root, e);
		}

};


#endif
