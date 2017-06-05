#include "stdafx.h"
#include "baza.h"

Sasiad::Sasiad(Koralowiec *wsk, Sasiad *nast)
{
	wskazywany = wsk;
	nastepny = nast;
}

Sasiad::~Sasiad()
{
}

Koralowiec::Koralowiec(int w, int s, int n, Koralowiec *p)
{
	waga = w;

	suma = s;
	numer = n;
	poprzedni = p;
}

Koralowiec::~Koralowiec()
{}

void Rafa::pierwszy_koralowiec()
{
	std::cin >> tablica[0].waga;
	tablica[0].numer = 0;
}

void Rafa::kolejny_koralowiec(int i)
{
	int x;

	std::cin >> tablica[i].waga >> x;

	tablica[i].poprzedni = &tablica[x];
}

void Rafa::przyjmowanie(int k)
{
	pierwszy_koralowiec();

	for (int i = 1; i < k; ++i)
	{
		kolejny_koralowiec(i);
		tablica[i].numer = i;
	}
}

int Rafa::calkowita_waga()
{
	int suma = 0;
	for (int i = 0; i < rozmiar; ++i)
	{
		suma += tablica[i].waga;
	}

	return suma;
}

void Rafa::przetwarzanie_kolejki(Kolejka *k)
{
	while (!(k->empty()))
	{
		k->front()->poprzedni->suma += k->front()->suma;
		k->pop();
	}
}

void Rafa::przeszukanie_grafu()
{
	for (int i = 0; i < rozmiar; ++i)
	{
		tablica[i].suma = tablica[i].waga;
	}

	for (int i = rozmiar - 1; i>0; --i)
	{
		tablica[i].poprzedni->suma += tablica[i].suma;
	}
}

int Rafa::wyszukiwanie()
{
	int a, b, r, r2 = waga_rafy;

	for (int i = 1; i < rozmiar; ++i)
	{
		a = tablica[i].suma;
		b = waga_rafy - a;

		if (a>b) r = a - b;
		else r = b - a;

		if (r < r2) r2 = r;
	}

	return r2;
}

Kolejka *Rafa::punkty(int x, int &i)
{
	int ile = 0;
	Kolejka *k1 = new Kolejka;
	int a, b, r;

	for (int i = 0; i < rozmiar; i++)
	{
		a = tablica[i].suma;
		b = waga_rafy - a;
		r = a - b;

		if (r>0)
		{
			if (r == x)
			{
				++ile;
				k1->push(&tablica[i]);
			}
		}
		else
		{
			if (r == -x)
			{
				++ile;
				k1->push(&tablica[i]);
			}
		}
	}

	i = ile;
	return k1;
}

void Rafa::wyswietlanie(Kolejka *x)
{
	while (!(x->empty()))
	{
		std::cout << x->front()->poprzedni->numer << " " << x->front()->numer << "\n";
		x->pop();
	}
}

Rafa::Rafa(int w, int s, int n, Koralowiec *p)
:Koralowiec(w, s, n, p)
{
	int x;
	std::cin >> x;
	rozmiar = x;

	Koralowiec *tab = new Koralowiec[x];
	tablica = tab;

	przyjmowanie(x);
	waga_rafy = calkowita_waga();
	przeszukanie_grafu();
	int najmniejsza_roznica = wyszukiwanie();
	int ile;
	Kolejka *k2 = punkty(najmniejsza_roznica, ile);
	std::cout << najmniejsza_roznica << " " << ile << "\n";

	wyswietlanie(k2);
	delete k2;
	delete[] tab;
}

Rafa::~Rafa()
{
}

bool Kolejka::empty()
{
	if (head != NULL) return 0;
	else return 1;
}

void Kolejka::push(Koralowiec *k)
{
	Sasiad *s = new Sasiad;
	s->wskazywany = k;

	if (head != NULL)
	{
		tail->nastepny = s;
		tail = s;
		tail->nastepny = NULL;
	}
	else
	{
		head = s;
		tail = s;
		tail->nastepny = NULL;
	}
}

Koralowiec *Kolejka::front()
{
	return head->wskazywany;
}

void Kolejka::pop()
{
	Sasiad *pomocniczy;
	pomocniczy = head;

	if (head != tail)
	{
		head = head->nastepny;
		delete pomocniczy;
	}
	else
	{
		delete head;
		head = NULL;
		tail = NULL;

	}
}

Kolejka::Kolejka()
{
	head = NULL;
	tail = NULL;
}

Kolejka::~Kolejka()
{}