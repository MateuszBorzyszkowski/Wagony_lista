#pragma
#include <iostream>

struct Lista
{
	Lista *next;
	int data;
};

class Stos
{
private:
	Lista *stack;
	int licznik;
public:
	Stos();
	~Stos();
	bool empty(void);
	Lista *top(void);
	int size(void);
	void push(int v);
	void pop(void);
	void reverse();
	void wypisz(int liczba);
};

Stos::Stos()
{
	stack = NULL;
	licznik = 0;
}
Stos::~Stos()
{
	while (stack) pop();
}

bool Stos::empty(void)
{
	return !stack;
}
Lista *Stos::top(void)
{
	return stack;
}
int Stos::size(void)
{
	return licznik;
}
void Stos::push(int v)
{
	Lista *e = new Lista;
	e->data = v;
	e->next = stack;
	stack = e;
	licznik++;
}
void Stos::pop(void)
{
		Lista *e = stack;
		stack = stack->next;
		delete e;
		licznik--;
}
void Stos::reverse()
{
	Lista *e, *p;
	if (stack)
	{
		p = stack;
		while (p->next)
		{
			e = p->next;
			p->next = e->next;
			e->next = stack;
			stack = e;
		}
	}
}
void Stos::wypisz(int liczba)
{
	Lista *e = stack;
	//while (e)
	//{
	//	std::cout << e->data << " ";
	//	e = e->next;
	//}
	//std::cout << "\n";
	int x = 0;
	while (x < liczba)
	{
		if (x == liczba - 1)
		{
			std::cout << "TAK";
			break;
		}
		if (e->data < e->next->data)
		{
			std::cout << "NIE";
			break;
		}
		else
		{
			e = e->next;
		}
		x++;
	}
}


int main()
{
	Stos tor_boczny;
	Stos bocznica;
	Stos tor_peron;
	int liczba_wagonow;
	int n;
	int pom;

	std::cin >> liczba_wagonow;
	while (std::cin.good())
	{
		std::cin >> n;
		tor_boczny.push(n);
	}
	//tor_boczny.wypisz();
	tor_boczny.reverse();
	//tor_boczny.wypisz();
	
	bool flaga = true;
	while (flaga)
	{
		if (bocznica.empty())														//jesli bocznica jest pusta to ide do toru bocznego
		{
			if (tor_boczny.empty())													// jesli tor boczny jest pusty to wszystko znajduje się juz na torze peron
			{
				std::cout << "WSZYSTKO NA PERONIE";
			}
			else																	// jesli tor boczny nie jest pusty to sprawdzamy czy sa co najmniej 2 wagony
			{
				if (tor_boczny.size() > 1)											// jesli sa co najmniej 2 wagony na torze bocznym to porownuje je, ktory jest mniejszy
				{
					if (tor_boczny.top()->data < tor_boczny.top()->next->data)		// jesli wagon z gory jest mniejszy to idzie na tor peron
					{
						pom = tor_boczny.top()->data;
						tor_boczny.pop();
						tor_peron.push(pom);
					}
					else															// jesli wagon z gory jest większy to idzie na bocznice		
					{
						pom = tor_boczny.top()->data;
						tor_boczny.pop();
						bocznica.push(pom);
					}
				}
				else																// jesli jest tylko 1 wagon na torze bocznym to przenies go na tor peron
				{
					pom = tor_boczny.top()->data;
					tor_boczny.pop();
					tor_peron.push(pom);
				}
			}
		}
		else																		// jesli bocznica nie jest pusta
		{
			if (tor_boczny.empty())													// jesli tor boczny jest pusty to z bocznicy przenosimy na tor do peronu (nie mozemy przeniesc na tor boczny, jest to niedozwolone)
			{
				pom = bocznica.top()->data;
				bocznica.pop();
				tor_peron.push(pom);
			}
			else																	// jesli tor boczny nie jest pusty to porownuje gore z toru bocznego i bocznicy
			{
				if (tor_boczny.top()->data < bocznica.top()->data)					// jesli na torze bocznym jest mniejsza gora niz na gorze bocznicy to sprawdzam czy sa chociaz 2 wagony na torze bocznym
				{
					if (tor_boczny.size() > 1)										// jesli na torze bocznym sa chociaz 2 wagony to je porownuje ktory jest wiekszy
					{
						if (tor_boczny.top()->data < tor_boczny.top()->next->data)	// jesli wagon z gory jest wiekszy to idzie na tor peron
						{
							pom = tor_boczny.top()->data;
							tor_boczny.pop();
							tor_peron.push(pom);
						}
						else														// jesli wagon z gory jest mniejszy to idzie na bocznice		
						{
							pom = tor_boczny.top()->data;
							tor_boczny.pop();
							bocznica.push(pom);
						}
					}
					else															// jesli jest tylko 1 wagon na torze bocznym to przenies go na tor peron
					{
						pom = tor_boczny.top()->data;
						tor_boczny.pop();
						tor_peron.push(pom);
					}
				}
				else																// jesli gora na bocznicy jest wieksza niz na torze bocznym to z bocznicy idzie na tor peron
				{
					pom = bocznica.top()->data;
					bocznica.pop();
					tor_peron.push(pom);
				}
			}
		}

		if (tor_boczny.empty())
			if (bocznica.empty())
				flaga = false;
	}


		//std::cout << "Tor Boczny: ";
		//tor_boczny.wypisz();
		//std::cout << "Bocznica: ";
		//bocznica.wypisz();
		//std::cout << "Tor Peron: ";
		/*tor_peron.reverse();*/
		tor_peron.wypisz(liczba_wagonow);


		
				
	return 0;
}