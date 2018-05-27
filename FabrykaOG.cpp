#include "FabrykaOG.hh"

/*!
 * \file
 * \brief Zawiera definicje metod klasy Fabryka.
 *
 * Zawiera definicje metod klasy Fabryka
 * wraz z ich opisem.
 */

/*!
 * Tworzy przeszkodę lub robota i zwraca inteligentny wskaznik na ten nowo utworozny obiekt.
 */
std::shared_ptr < ObiektGraficzny > Fabryka::dodajObiekt(int w, PzG::LaczeDoGNUPlota * dupa)
{

    if(w == 0)
    {
        auto tmp = std::shared_ptr < Robot > (Robot::dodajtypa(dupa));
        return tmp;
    }
    else if(w == 1)
    {
        auto tmp = std::shared_ptr < Przeszkoda > (Przeszkoda::stworz(dupa));
        return tmp;
    }
    else
    {
        std::cout << "Program nie jest przystosowany do stworzenia takiego obiektu, prosze zmienic swoje wymagania!";
        return std::make_shared <ObiektGraficzny> ();
    }

    return std::make_shared <ObiektGraficzny> ();

}
