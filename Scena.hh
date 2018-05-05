#ifndef SCENA_HH
#define SCENA_HH

/*!
 * \file
 * \brief Definicja klasy Scena i funkcji inicjalizującej zapis wektrów.
 *
 * Plik zawiera definicję klasy Scena, i funkcji która inicjalizuje plik \e wierzchołkiAktualne.dat.
 */

#include "Robot.hh"

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

    /*!
     * \brief Robot pojawiający się na scenie.
     *
     * Zmienna przechowująca informacje o robocie znajdującym się na scenie i służca
     * do wykonywania na nim operacji.
     */
    Robot R;

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

    /*!
     * \brief Funckja bezpośrednio wyświetlająca ilość stworzonych obiektów klasy \e Wektor2D.
     */
    void WyswietlWektory();
};

#endif
