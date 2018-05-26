#include "FabrykaOG.hh"

std::shared_ptr < ObiektGraficzny > Fabryka::dodajObiekt(int w, PzG::LaczeDoGNUPlota * dupa)
{

    if(w == 0)
    {
        std::shared_ptr < Robot > tmp = std::shared_ptr < Robot > (Robot::dodajtypa(dupa));
        return tmp;
    }

    if(w == 1)
    {
        std::shared_ptr < Przeszkoda > tmp = std::shared_ptr < Przeszkoda > (Przeszkoda::stworz(dupa));
        return tmp;
    }

    return std::make_shared <ObiektGraficzny> ();

}






