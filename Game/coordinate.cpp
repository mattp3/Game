#include "coordinate.hpp"
#include "Stanza.hpp"
#include <iostream>
using namespace std;


coordinate::coordinate() {
    a = 0;
    b = 0;
    room = NULL;
    pros = NULL;
}

coordinate::~coordinate() {
	cout<<"Rimossa stanza x:"<<a<<" y:"<<b<<endl;
    delete room;
}


coordinate *coordinate::add(coordinate *& testa, coordinate * precedenti, int direzione) {
    if (testa->room == NULL) {
        testa->room = new Stanza;
        testa->pros = NULL;
        precedenti = testa;
    }
    else {
        coordinate * p = new coordinate;
        p->room = new Stanza;
        p->room = p->room->Aggiungi_Stanza(precedenti->room, p->room, direzione);
        p->pros = testa;
        testa = p;
        precedenti = testa;
    }
    return (precedenti);
}

coordinate * coordinate::search(coordinate *& testa, coordinate * precedenti, int direzione) {
    bool found = 0;
    coordinate * p = testa;
    int x, y;
    x = precedenti->a;
    y = precedenti->b;
    move(x, y, direzione);
    while ((p != NULL) && (found == 0)) {
        if ((x == p->a) && (y == p->b)) {
            found = 1;
            p->room = p->room->Aggiungi_Stanza(precedenti->room, p->room, direzione);
            precedenti = p;
        }
        else {
            p = p->pros;
        }
    }
    if (found == 0) {
        precedenti = add(testa, precedenti, direzione);
        precedenti->a = x;
        precedenti->b = y;
        //precedenti->printNode(precedenti);
    }
    //Qui manca il caso di found=1
    return (precedenti);
}

void coordinate::move(int &a, int &b, int direzione) {
    if (direzione == 8) {
        b = b + 1;
    }
    else if (direzione == 6) {
        a = a + 1;
    }
    else if (direzione == 4) {
        a = a - 1;
    }
    else if (direzione == 2) {
        b = b - 1;
    }
}

void coordinate::rem(coordinate *& c) {
    if (c->pros != NULL) {
        rem(c->pros);
    }
    delete c;
}

bool coordinate::findMap(coordinate * testa, int i, int j){
	coordinate * f = testa;
	int found = 0;
	while ((f != NULL) && (!found)){
		if ((i == f->a) && (j == f->b)){
			found = 1;
		}
		f = f->pros;
	}
	return (found);
}

void coordinate::printList(coordinate * testa) {
    cout << "Lista:" << endl;
    coordinate * s = testa;
    while (s != NULL) {
        cout << s->a << endl;
        cout << s->b << endl;
        s = s->pros;
    }
}

void coordinate::printNode(coordinate * precedente) {
    cout << "\nNodo:" << endl;
    cout << precedente->a << endl;
    cout << precedente->b << endl;
}


Stanza* coordinate::getRoom(){
    return(room);
}

int coordinate::getCoordinatex(){
    return(a);
}

int coordinate::getCoordinatey(){
    return(b);
}
