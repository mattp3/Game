#include "ListaStanze.hpp"
#include <iostream>
using namespace std;


List::List() {
	head = NULL;
}

List::~List() {
	while (head != NULL) {
		Node * n = head->next;
		delete head;
		head = n;
	}
}

void List::add(int x, int y){
	Node * n = new Node;
	n->a = x;
	n->b = y;
	n->next = head;
	head = n;
	cout << head->a << "," << head->b << endl;
}

void List::search(int x, int y) {
	Node * n = head;
	bool found = 0;
	while ((n != NULL) && (!found)) {
		if ((n->a == x) && (n->b == y)) {
			found = 1;
			cout << n->a << "," << n->b << endl;
		}
		n = n->next;
	}
	if (found == 0) {
		List testa;
		testa.add(x, y);
	}
}

void List::print() {
	Node * n = head;
	while (n != NULL) {
		cout << n->a << "," << n->b << endl;
		n = n->next;
	}
}