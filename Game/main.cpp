// Labirinto.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "ListaStanze.hpp"


int main()
{
	List testa;
	testa.add(0,0);
	testa.add(1,1);
	testa.add(2,2);
	testa.search(1, 1);
    return 0;
}

