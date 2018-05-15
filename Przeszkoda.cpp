#include "Przeszkoda.hh"

Przeszkoda::Przeszkoda(PzG::LaczeDoGNUPlota * lacznik)
{

 ++Indeks;

 this->wsklacze = lacznik;

 Nazwa += "Przeszkoda" + std::to_string(Indeks) + ".dat";

 wsklacze->DodajNazwePliku(Nazwa.c_str(), PzG::RR_Ciagly, 4);
 wsklacze->ZmienTrybRys(PzG::TR_2D);

}

void Przeszkoda::DodajPrzeszkode1()
{
    _TabWierz.DodajWierzcholek(-200, -200);
    _TabWierz.DodajWierzcholek(-100, -200);
    _TabWierz.DodajWierzcholek(-100, -100);
    _TabWierz.DodajWierzcholek(-200, -100);
    _TabWierz.DodajWierzcholek(-200, -200);

    ZapiszDoPliku(Nazwa.c_str());
    wsklacze->Rysuj();
}
