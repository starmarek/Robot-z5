#ifndef SCENA_HH
#define SCENA_HH

/*!
 * \file
 * \brief Definicja klasy Scena i funkcji inicjalizującej zapis wektrów.
 *
 * Plik zawiera definicję klasy Scena, i funkcji która inicjalizuje plik \e wierzchołkiAktualne.dat.
 */

#include "Robot.hh"
#include "Przeszkoda.hh"
#include <memory>
#include <list>

/*!
 * \brief Klasa modelująca pojęcie Sceny.
 *
 * Modeluje scene, czyli planszę którą widzi użytkownik podczas obsługi programu.
 * Odpwiada również za szeroko pojętą komunikację z użytkownikiem.
 */
class Scena
{

    /*!
     * \brief Zmienna potrzebna do komunikacji z programem \e gnuplot.
     *
     * Dzięki tej zmiennej możemy rysować na bierząco robota i  ścieżke.
     */
    PzG::LaczeDoGNUPlota lacze;

    //std::list < std::shared_ptr <ObiektGraficzny> > LObiektow;

    std::list < std::shared_ptr <Robot> > LRobotow;
    std::list < std::shared_ptr <Robot> > :: iterator Rit = LRobotow.begin();

    std::list < std::shared_ptr <Przeszkoda> > LPrzeszkod;
    std::list < std::shared_ptr <Przeszkoda> > :: iterator Pit = LPrzeszkod.begin();

public:

    /*!
     * \brief Wyświetla możliwości wyboru dla użytkownika, oraz ilość stworzonych obiektów
     * klasy \e Wektor2D.
     */
    void WyswietlMenu();

    /*!
     * \brief Uruchamia, kończy i kontroluje przebieg działania programu.
     */
    void Run();
    void DodajRoboty();
    void DodajPrzeszkody();
    void JakiRobot();
    void WyborRobota();
    void Menu();
};

#endif
