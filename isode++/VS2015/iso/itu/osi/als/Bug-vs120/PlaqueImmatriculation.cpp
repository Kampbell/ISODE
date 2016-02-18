#include <iostream>
#include <string>
#include <cassert>
using namespace std;

char caractere_suivant(string& plaque, int pos) {
	char car = plaque.at(pos);
	if (car < 'Z')
		car += 1;
	else
		car = 'A';
	plaque.at(pos) = car;
	return car;
}
string plaque_suivante(string& plaque) {
	if (plaque.empty())
		return "A";

	for (int no = plaque.size(); no > 0; no--) {
		char car = caractere_suivant(plaque, no - 1);
		if (car != 'A')
			return plaque;
	}

	plaque.append(1, 'A');
	return plaque;
}

int plaque(int argc, char** argv) {
	assert(plaque_suivante(string("A"))  == "B");
	assert(plaque_suivante(string("C"))  == "D");
	assert(plaque_suivante(string("Z"))  == "AA");
	assert(plaque_suivante(string("CA")) == "CB");
	assert(plaque_suivante(string("CY")) == "CZ");
	assert(plaque_suivante(string("CZ")) == "DA");
	assert(plaque_suivante(string("ZZ")) == "AAA");
	assert(plaque_suivante(string("AAA"))== "AAB");
	assert(plaque_suivante(string("AAZ"))== "ABA");
	assert(plaque_suivante(string("ZZA"))== "ZZB");
	assert(plaque_suivante(string("ZZZ"))== "AAAA");
	assert(plaque_suivante(string("ZZY"))== "ZZZ");
	assert(plaque_suivante(string("YZZ"))== "ZAA");
	return 0;
}
