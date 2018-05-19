#ifndef SWEKTOR_HH
#define SWEKTOR_HH

/*!
 * \file
 * \brief  Definicja szablonu SWektor
 *
 *  Zawiera definicję szablonu SWektor. Pozwala on na
 *  stworzenie instancji klasy wektor o dowolnym wymiarze
 *  oraz typie pól reprezentujących jego współrzędne, dla
 *  których zdefiniowane są podstawowe działania arytmetyczne.
 */

#include <iostream>

/*!
 * \brief Szablon klasy wektor parametryzowanej wymiarem i typem współrzędnych
 *
 *  Szablon umożliwiający tworzenie instancji typu, który modeluje
 *  pojęcie wektora.
 *   \param  STyp - typ pól repezentujących kolejne współrzędne wektora,
 *   \param  SWymiar - wymiar wektora.
 */
template <typename STyp, int SWymiar>
class SWektor
{

    /*!
     * Przechowuje informacje o ilości aktualnie istniejących obiektów klasy Wektor2D.
     */
    static int WektoryAktualne;

    /*!
     * Przechowuje informacje o ilości ogólnie stworzonych obiektów klasy Wektor2D.
     */
    static int WektoryOgolne;

    /*!
     * \brief Współrzędne wektora
     *
     *  Tablica zawiera kolejne współrzędne wektora.
     */
    STyp  _Wsp[SWymiar];

public:

    /*!
     * Metoda wyświetlająca aktualną zawartość zmiennych statycznych wraz z odpowiednim opisem.
     */
    static void PokazWektory()
    {
        std::cout << "Laczna ilosc stworzonych obiektow klasy Wektor2D: " << WektoryOgolne << std::endl;
        std::cout << "Ilosc istniejacych obiektow klasy Wektor2D: " << WektoryAktualne << std::endl << std::endl;
    }

    static void ZwrocObi()
    {
        std::cout << "Laczna ilosc stworzonych obiektow klasy Wektor2D: " << WektoryOgolne << std::endl;
        std::cout << "Ilosc nieusunietych obiektow klasy Wektor2D: " << WektoryAktualne << std::endl << std::endl;
    }

    /*!
     * \brief Inicjaliuje obiekt wartościami 0, oraz dokumentuje stowrzenie obiektu typu Wektor2D.
     */
    SWektor();

    /*!
     * \brief Dokumentuje usunięcie obiektu typu Wektor2D.
     */
    ~SWektor();

    /*!
     * \brief Dodatkowo dokumentuje dodanie obiektu typu Wektor2D.
     */
    SWektor(const SWektor<STyp, SWymiar> &W);

    /*!
     * \brief Dostęp poprzez indeks do współrzędnych wektora w trybie \e tylko \e do \e odczytu.
     *
     *  Umożliwia dostęp do współrzędnych poprzez indeks w trybie  \e tylko \e do \e odczytu.
     *  Nie jest sprawdzana poprawność wartości indeksu, czy mieści się we właściwym zakresie.
     *
     *  \param[in] Ind - indeks wybranej współrzędnej. Indeksowanie tak jak w przypadku
     *               tablicy, zaczyna się od 0.
     *  \pre Wartość parametru \e Ind musi być mniejsza niż \e SWymiar.
     *  \return Wartość indeksowanej współrzędnej.
     */
    STyp  operator [] (unsigned int Ind) const
    {
        return _Wsp[Ind];
    }

    /*!
     * \brief Dostęp poprzez indeks do współrzędnych wektora w trybie \e modyfikacji.
     *
     *  Umożliwia dostęp do współrzędnych poprzez indeks w trybie modyfikacji.
     *  Nie jest sprawdzana poprawność wartości indeksu, czy mieści się we właściwym zakresie.
     *
     *  \param[in] Ind - indeks wybranej współrzędnej. Indeksowanie tak jak w przypadku
     *               tablicy, zaczyna się od 0.
     *  \pre Wartość parametru \e Ind musi być mniejsza niż \e SWymiar.
     *  \return Referencję do indeksowanej współrzędnej.
     */
    STyp &operator [] (unsigned int Ind)
    {
        return _Wsp[Ind];
    }

    /*!
     * \brief Odejmowanie dwóch wektorów.
     */
    SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &Odjemnik) const;

    /*!
     * \brief Dodanie dwóch wektorów.
     */
    SWektor<STyp,SWymiar> operator + (const SWektor<STyp,SWymiar> &Skl2) const;

    /*!
     * \brief Mnoży wektor przez liczbę.
     */
    SWektor<STyp,SWymiar> operator * (double Mnoznik) const;
};

/*!
 * Inicjalizacja zmiennej statycznej.
 */
template <typename STyp, int SWymiar>
int SWektor<STyp, SWymiar>::WektoryAktualne;

/*!
 * Inicjalizacja zmiennej statycznej.
 */
template <typename STyp, int SWymiar>
int SWektor<STyp, SWymiar>::WektoryOgolne;

/*!
 * Inicjaluje wszystkie współrzędne wektora wartością 0, a nastepnie zwiększa zmienne statyczne.
 */
template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar>::SWektor()
{
    for (STyp &Wsp: _Wsp) Wsp = 0;
    ++WektoryAktualne;
    ++WektoryOgolne;
}

/*!
 * Od domyślnego konstruktora kopiującego ten różni się tylko tym, że dodatkowo
 * dokumentuje stworzenie obiektu \e Wektor2D. Konstruktor ten jest wywoływany
 * w metodach \e push.back().
 */
template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar>::SWektor(const SWektor<STyp, SWymiar> &W)
{
    for(unsigned int i = 0; i<SWymiar;++i) _Wsp[i] = W[i];

    ++WektoryAktualne;
    ++WektoryOgolne;
}

/*!
 * Destruktor ten pomniejsza licznik wektorów aktualnie istniejących przy niszczeniu
 * obiektów klasy Wektor2D.
 */
template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar>::~SWektor()
{
    --WektoryAktualne;
}

/*!
 *  Realizuje odejmowanie dwóch wektorów i zwraca wynik działania.
 *  \param[in] Odjemnik - drugi argument operacji odejmownaia.
 *  \return Wynik operacji odejmowania.
 */
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &Odjemnik) const
{
    SWektor<STyp,SWymiar>  Wynik;

    for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] - Odjemnik[Ind];
    return Wynik;
}

/*!
 *  Realizuje dodawanie dwóch wektorów i zwraca wynik działania.
 *  \param[in] Skl2 - drugi argument operacji dodwania.
 *  \return Wynik operacji dodawania.
 */
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator + (const SWektor<STyp,SWymiar> &Skl2) const
{
    SWektor<STyp,SWymiar>  Wynik;

    for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] + Skl2[Ind];
    return Wynik;
}

/*!
 *  Realizuje mnożenie wszystkie współrzędnych wektora przez liczbę.
 *  \param[in] Mnoznik - wartość liczby, przez którą zostaną wymnożone wszystkie
 *                       współrzędne wektora.
 *  \return Wynik operacji mnożenia przez liczbę.
 */
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (double Mnoznik) const
{
    SWektor<STyp,SWymiar>  Wynik;

    for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]*Mnoznik;
    return Wynik;
}

/*!
 * \brief Wypisuje kolejne współrzędne wektora
 *
 * Do strumienia wyjściowego w formie tekstowej wpisuje wszystkie wartości
 * współrzędnych wektora rozdzielając je spacją.
 * Przykład wyniku operacji
\verbatim
    12.5 1.23 4 6
\endverbatim
 *  \param[in,out]  StrmWyj - strumień wyjściowy, do którego zostają wpisane
 *                            w formie tekstowej wartości kolejnych współrzędnych.
 *  \param[in] W - wektor, którego współrzędne mają zostać wpisane do strumienia.
 *  \return Referencja do strumienia wyjściowego będącego parametrem wywołania
 *          niniejszego przeciążenia operatora <<.
 */
template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &StrmWyj, const SWektor<STyp,SWymiar>& W)
{
    for (unsigned int Ind = 0; Ind < SWymiar; ++Ind)
    {
        StrmWyj << " " << W[Ind];
    }
    return StrmWyj;
}

#endif
