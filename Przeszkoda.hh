#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "ObiektGraficzny.hh"


class Przeszkoda : public ObiektGraficzny
{

    PzG::LaczeDoGNUPlota * wsklacze;

public:

    void DodajPrzeszkode1();
    Przeszkoda(PzG::LaczeDoGNUPlota * lacznik);

};



#endif
