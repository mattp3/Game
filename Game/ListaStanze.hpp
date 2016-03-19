#pragma once
#include "Nodo.hpp"

class List : protected Nodo {
protected:
	struct Node {
		int a;
		int b;
		Stanza* stanza;
		Node* next;
	};

	Node * head;

public:
	List();

	~List();

	void add(int x, int y);

	void search(int x, int y);

	void print();

};