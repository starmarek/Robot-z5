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
