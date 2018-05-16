#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "ObiektGraficzny.hh"


class Przeszkoda : public ObiektGraficzny
{

    PzG::LaczeDoGNUPlota * wsklacze;
    static int Indeks;

public:

    void DodajPrzeszkode1();
    void DodajPrzeszkode2();
    void DodajPrzeszkode3();
    Przeszkoda(PzG::LaczeDoGNUPlota * lacznik);

};



#endif
