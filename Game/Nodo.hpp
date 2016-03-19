#pragma once

class Nodo {
protected:
	struct Stanza {
		Stanza* left;
		Stanza* up;
		Stanza* right;
		Stanza* down;
		
		Stanza* next;
	};

	Stanza * testa;

public:
	Nodo();

	~Nodo();

	Stanza addLeft();

	Stanza addUp();

	Stanza addRight();

	Stanza addDown();
};