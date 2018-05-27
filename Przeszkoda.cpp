/*!
 * \file
 * \brief Zawiera definicje metod klasy Przeszkoda.
 *
 * Plik zawiera definicje metod klasy Przeszkoda wraz z ich opisem.
 */

#include "Przeszkoda.hh"

/*!
 * Inicjalizacja zmiennej statycznej.
 */
int Przeszkoda::Indeks;

/*!
 * Tworzy nową przeszkodę na podstawie parametrów podanych przez użytkownika. Następnie zapisuje ją do pliku.
 */
void Przeszkoda::DodajPrzeszkode()
{
    double x, y, sz, wys, tmpx, tmpy;
    std::cout << "Podaj docelowe wspolrzedne przeszkody (lewy dolny rog)\noraz jej szerokosc i dlugosc: x y sz wys >";
    std::cin >> x >> y >> sz >> wys;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(),'\n');
        std::cout << "Prosze podac odpowiednie wartosci!\n";
        std::cin >> x >> y >> sz >> wys;
    }
    _TabWierz.DodajWierzcholek(x, y);
    tmpx = x + sz;
    _TabWierz.DodajWierzcholek(tmpx, y);
    tmpy = y + wys;
    _TabWierz.DodajWierzcholek(tmpx, tmpy);
    _TabWierz.DodajWierzcholek(x, tmpy);
    _TabWierz.DodajWierzcholek(x, y);

    ZapiszDoPliku(Nazwa.c_str());

    tmpx = x+(0.5*sz);
    tmpy = y+(0.5*wys);

    _PolozenieObiektu[0] = tmpx;
    _PolozenieObiektu[1] = tmpy;
}

/*!
 * Sprawdza wszystkie możliwości kolizji - na rogach, na bokach i w środku przeszkody.
 * Zwraca prawdę jeżeli doszło do kolizji, oraz fałsz jeżeli nie doszło.
 *
 * \param wek - polożenie aktualnie używanego robota.
 * \param r - promień aktualnie używanego robota.
 */
bool Przeszkoda::Kolizja(Wektor2D wek, double r)
{
    double x, y;
    double szerokosc = _TabWierz[1][0] - _TabWierz[0][0];
    double wysokosc = _TabWierz[2][1] - _TabWierz[1][1];

    x = abs(wek[0] - _PolozenieObiektu[0]);
    y = abs(wek[1] - _PolozenieObiektu[1]);
    double cDist = pow((x - szerokosc/2), 2) + pow((y - wysokosc/2), 2);

    if (x > (szerokosc/2 + r)) { return false; }
    if (y > (wysokosc/2 + r)) { return false; }

    if (x <= (szerokosc/2)) { return true; }
    if (y <= (wysokosc/2)) { return true; }

    return (cDist <= pow((r), 2));
}

/*!
 * Nadaje danej przeszkodzie numer indeksu, nazwe do zapisu do pliku, oraz inicjalizuje dany plik.
 * Definicja konstruktora znajduje się w sekcji \e private aby zapobiec przypadkowemu tworzeniu sie obiektow tej klasy.
 */
Przeszkoda::Przeszkoda(PzG::LaczeDoGNUPlota * lacznik)
{
 Indeks++;

 wsklacze = lacznik;

 Nazwa += "Przeszkoda" + std::to_string(Indeks) + ".dat";

 wsklacze->DodajNazwePliku(Nazwa.c_str(), PzG::RR_Ciagly, 4);
}

/*!
 * Wrzuca wierzchołki do tablicy i zapisuje ją do pliku pod nazwą danej przeszkody.
 */
void Przeszkoda::DodajPrzeszkode1()
{
    _TabWierz.DodajWierzcholek(-200, -200);
    _TabWierz.DodajWierzcholek(-100, -200);
    _TabWierz.DodajWierzcholek(-100, -100);
    _TabWierz.DodajWierzcholek(-200, -100);
    _TabWierz.DodajWierzcholek(-200, -200);

    ZapiszDoPliku(Nazwa.c_str());

    _PolozenieObiektu[0] = -150;
    _PolozenieObiektu[1] = -150;
}

/*!
 * Wrzuca wierzchołki do tablicy i zapisuje ją do pliku pod nazwą danej przeszkody.
 */
void Przeszkoda::DodajPrzeszkode2()
{
    _TabWierz.DodajWierzcholek(100, -300);
    _TabWierz.DodajWierzcholek(300, -300);
    _TabWierz.DodajWierzcholek(300, -100);
    _TabWierz.DodajWierzcholek(100, -100);
    _TabWierz.DodajWierzcholek(100, -300);

    ZapiszDoPliku(Nazwa.c_str());

    _PolozenieObiektu[0] = 200;
    _PolozenieObiektu[1] = -200;
}

/*!
 * Wrzuca wierzchołki do tablicy i zapisuje ją do pliku pod nazwą danej przeszkody.
 */
void Przeszkoda::DodajPrzeszkode3()
{
    _TabWierz.DodajWierzcholek(-300, 100);
    _TabWierz.DodajWierzcholek(-100, 100);
    _TabWierz.DodajWierzcholek(-100, 200);
    _TabWierz.DodajWierzcholek(-300, 200);
    _TabWierz.DodajWierzcholek(-300, 100);

    ZapiszDoPliku(Nazwa.c_str());

    _PolozenieObiektu[0] = -200;
    _PolozenieObiektu[1] =  150;
}
