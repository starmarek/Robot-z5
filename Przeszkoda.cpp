#include "Przeszkoda.hh"

int Przeszkoda::Indeks = 0;

Przeszkoda::Przeszkoda(PzG::LaczeDoGNUPlota * lacznik)
{

 Przeszkoda::Indeks++;

 this->wsklacze = lacznik;

 Nazwa += "Przeszkoda" + std::to_string(Przeszkoda::Indeks) + ".dat";

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
    //wsklacze->Rysuj();
}


void Przeszkoda::DodajPrzeszkode2()
{
    _TabWierz.DodajWierzcholek(300, -300);
    _TabWierz.DodajWierzcholek(300, -100);
    _TabWierz.DodajWierzcholek(100, -100);
    _TabWierz.DodajWierzcholek(100, -300);
    _TabWierz.DodajWierzcholek(300, -300);

    ZapiszDoPliku(Nazwa.c_str());
    //wsklacze->Rysuj();
}


void Przeszkoda::DodajPrzeszkode3()
{
    _TabWierz.DodajWierzcholek(-300, 100);
    _TabWierz.DodajWierzcholek(-100, 100);
    _TabWierz.DodajWierzcholek(-100, 200);
    _TabWierz.DodajWierzcholek(-300, 200);
    _TabWierz.DodajWierzcholek(-300, 100);

    ZapiszDoPliku(Nazwa.c_str());
   // wsklacze->Rysuj();
}
