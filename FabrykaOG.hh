#ifndef FABRYKAOG_HH
#define FABRYKAOG_HH




#include "Robot.hh"
#include "Przeszkoda.hh"


class Fabryka
{

static Fabryka fab;
Fabryka() { }
Fabryka(const Fabryka &) { }

public:

static std::shared_ptr < ObiektGraficzny > Buduj(int w, PzG::LaczeDoGNUPlota * dupa)
{
    return fab.dodajObiekt(w, dupa);
}

std::shared_ptr < ObiektGraficzny > dodajObiekt(int w, PzG::LaczeDoGNUPlota * dupa);

};


#endif
