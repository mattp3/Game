#include "Nodo.hpp"
#include <iostream>
using namespace std;

Nodo::Nodo() {
	testa = NULL;
}

Nodo::~Nodo() {
	while (testa != NULL) {
		Stanza * n = testa->next;
		delete testa;
		testa = n;
	}
}

Nodo::Stanza Nodo::addLeft(){
	testa->left = new Stanza;
	testa->next = testa->left;
	testa = testa->next;
	return (*testa->left);
}

Nodo::Stanza Nodo::addUp(){
	testa->up = new Stanza;
	testa->next = testa->up;
	testa = testa->next;
	return (*testa->up);
}

Nodo::Stanza Nodo::addRight(){
	testa->right = new Stanza;
	testa->next = testa->right;
	testa = testa->next;
	return (*testa->right);
}

Nodo::Stanza Nodo::addDown(){
	testa->down = new Stanza;
	testa->next = testa->down;
	testa = testa->next;
	return (*testa->down);
}