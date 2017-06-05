#include "stdafx.h"
#include <iostream>

class Koralowiec;
class Kolejka;

class Sasiad
{
public:
	Koralowiec *wskazywany;
	Sasiad *nastepny;

	Sasiad(Koralowiec *wsk = NULL, Sasiad *nast = NULL);
	~Sasiad();
	friend void kolejny_koralowiec();
};

class Koralowiec
{
public:
	int waga;
	int suma;
	int numer;
	Koralowiec *poprzedni;

	Koralowiec(int w = 1, int s = 0, int n = 0, Koralowiec *p = NULL);
	~Koralowiec();
};

class Rafa :public Koralowiec
{
public:
	int rozmiar;
	int waga_rafy;
	Koralowiec *tablica;

	void pierwszy_koralowiec();
	void kolejny_koralowiec(int i);
	void przyjmowanie(int k);
	void dodawanie();
	int calkowita_waga();
	void przetwarzanie_kolejki(Kolejka *k);
	void przeszukanie_grafu();
	int wyszukiwanie();
	Kolejka *punkty(int x, int &i);
	void wyswietlanie(Kolejka *x);
	Rafa(int w = 1, int s = 0, int n = 0, Koralowiec *p = NULL);
	~Rafa();
};

class Kolejka
{
	Sasiad *head;
	Sasiad *tail;

public:
	bool empty();
	Koralowiec *front();
	void push(Koralowiec *k);
	void pop();

	Kolejka();
	~Kolejka();
};