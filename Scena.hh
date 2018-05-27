#ifndef SCENA_HH
#define SCENA_HH

/*!
 * \file
 * \brief Definicja klasy Scena.
 *
 * Plik zawiera definicję klasy Scena.
 */

#include "FabrykaOG.hh"

/*!
 * \brief Klasa modelująca pojęcie Sceny.
 *
 * Modeluje scene, czyli planszę którą widzi użytkownik podczas obsługi programu.
 * Odpwiada również za szeroko pojętą komunikację z użytkownikiem.
 */
class Scena
{
    /*!
     * Ułatwia tworzenie obiektów, gdyż funkcja tworząca, tworzy obiekty na podstawie zmiennych typu \e int.
     */
    enum Typy {Robocik, Przeszkodzisko};

    /*!
     * \brief Zmienna potrzebna do komunikacji z programem \e gnuplot.
     *
     * Dzięki tej zmiennej możemy rysować na bierząco robota i  ścieżke.
     */
    PzG::LaczeDoGNUPlota lacze;

    /*!
     * Lista przechowująca wskaźniki shared_ptr zszablonowane Obiektem graficznym, na wszystkie roboty
     * i przeszkody. Zaraz pod nią, iterator do niej.
     */
    std::list < std::shared_ptr <ObiektGraficzny> > LObiektow;
    std::list < std::shared_ptr <ObiektGraficzny> > :: iterator Oit = LObiektow.begin();

    /*!
     * Lista przechowująca wskaźniki shared_ptr zszablonowane Robotem, na wszystkie roboty.
     * Zaraz pod nią, iterator do niej.
     */
    std::list < std::shared_ptr <Robot> > LRobotow;
    std::list < std::shared_ptr <Robot> > :: iterator Rit = LRobotow.begin();

public:

    /*!
     * \brief Sprawdza poprawność danych wproawdzonych przez użytkownika.
     */
    int Policjant();

    /*!
     * \brief Wyświetla możliwości wyboru dla użytkownika, oraz ilość stworzonych obiektów
     * klasy \e Wektor2D.
     */
    void WyswietlMenu();

    /*!
     * \brief Kontroluje główny przebieg działania programu.
     */
    void Run();

    /*!
     * \brief Główna inicjalizacja robotów w programie
     */
    void DodajRoboty();

    /*!
     * \brief Główna inicjalizacja przeszkód w programie
     */
    void DodajPrzeszkody();

    /*!
     * \brief Informuje o aktualnie używanym robocie.
     */
    void JakiRobot();

    /*!
     * \brief Umożliwia wybór robota którym będzie się operować.
     */
    void WyborRobota();

    /*!
     * \brief Obsługuje menu do komunikacji z użytkownikiem.
     */
    void Menu();

    /*!
     * \brief Wywołuje tworzenie nowego robota.
     */
    void NowyRobot();

    /*!
     * \brief Wywołuje tworzenie nowej przeszkody.
     */
    void NowaPrzeszkoda();
};

#endif
