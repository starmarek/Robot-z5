/*!
 * \file
 * \brief Zawiera definicje metod klasy Robot.
 *
 * Zawiera definicje metod klasy Robot
 * wraz z ich opisem.
 */

#include "Robot.hh"

/*!
 * Inicjalizacja zmiennej statycznej.
 */
int Robot::Indeks;

/*!
 * Nadpisuje aktualną wartość szybkości.
 */
void Robot::ZmienSzybkosc(int g)
{
    szybkosc = g;
}

/*!
 * Obraca każdy wierzchołek robota w oparciu o wzór:
 *
 * |x' = x * cos(alpha) - y * sin(alpha)
 * |y' = x * sin(alpha) + y * cos(alpha)
 *
 * gdzie \e x i \e y to aktualne współrzędne wierzchołka,
 * \e x' i \e y' to współrzędne po przekształceniu a \e alpha
 * to kąt podany w radianach, o który chcemy obrócić dany wierzchołek.
 *
 * \param a - kąt o który chcemy obrócić robota, podany w stopniach.
 */
void Robot::Obrot(double a)
{
    double x, y;
    a *= M_PI/180;
    Alpha += a;

    for(unsigned int i = 0; i < _TabWierz.size(); ++i)
    {
        x = _TabWierz[i][0];
        y = _TabWierz[i][1];

        _TabWierz[i][0] = x*cos(a) - y*sin(a);
        _TabWierz[i][1] = x*sin(a) + y*cos(a);
    }
}

/*!
 * Wykonuje animację obrotu widoczną na scenie.
 * Wykrzystuje funkcję \e usleep z nagłówka \e <unistd.h>,
 * aby pętla \e for była opóźniona, co daje efekt wykonującej się animacji.
 * Metoda reaguje na zmiany szybkości, modyfikując ilość wykonanych skoków w pętli
 * co daje wizulany efekt zmieniającej się prędkość robota.
 *
 * \param b - kąt o który ma się obrócić robot podany w stopniach, potrzebny aby pętla
 * \e for wykonała odpowiednią ilość skoków.
 */
void Robot::obroc(double b)
{
    double tmp = b/szybkosc;

    for (int i = 0; i < tmp; ++i)
    {
        if(tmp - i < 1)
        {
            Obrot((tmp - i) * szybkosc);
            ZapiszDoPliku(Nazwa.c_str());
            wsklacze->Rysuj();
            usleep(40000);
            return;
        }

        Obrot(szybkosc);
        ZapiszDoPliku(Nazwa.c_str());
        wsklacze->Rysuj();
        usleep(40000);
    }
    return;
}

/*!
 * Tworzy wierzchołki robota w podanych współrzędnych.
 */
void Robot::InicjalizujKsztalt()
{
    _TabWierz.DodajWierzcholek(0, 0);
    _TabWierz.DodajWierzcholek(30, 0);
    _TabWierz.DodajWierzcholek(0, -30);
    _TabWierz.DodajWierzcholek(-30, -30);
    _TabWierz.DodajWierzcholek(-30, 30);
    _TabWierz.DodajWierzcholek(0, 30);
    _TabWierz.DodajWierzcholek(30, 0);

    ZapiszDoPliku(Nazwa.c_str());
}

/*!
 * Tworzy nowego robota na podstawie parametrów podanych przez użytkownika.
 * Następnie zapisuje go do pliku oraz inicjalizuje jego ścieżkę.
 */
void Robot::DodajRobota()
{
    std::cout << "Podaj wspolrzedne do stworzenia nowego robota:\n ";
    std::cin >> _PolozenieObiektu[0] >> _PolozenieObiektu[1];
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(),'\n');
        std::cout << "Prosze podac odpowiednie wspolrzedne!\n";
        std::cin >> _PolozenieObiektu[0] >> _PolozenieObiektu[1];
    }
    ZapiszDoPliku(Nazwa.c_str());
    sciezkowy.DodajPierwszyPunkt(_PolozenieObiektu[0], _PolozenieObiektu[1], NazwaSciezki);
}

/*!
 * Metoda zmieniająca położenie robota względem zadanego punktu.
 * Dodatkowo inicjalizuje pierwszy punkt ścieżki oraz rysuje robota w programie
 * \e gnuplot.
 */
void Robot::DodajRobota1()
{
    _PolozenieObiektu[0] = 150;
    _PolozenieObiektu[1] = 150;
    ZapiszDoPliku(Nazwa.c_str());
    sciezkowy.DodajPierwszyPunkt(_PolozenieObiektu[0], _PolozenieObiektu[1], NazwaSciezki);
}

/*!
 * Metoda zmieniająca położenie robota względem zadanego punktu.
 * Dodatkowo inicjalizuje pierwszy punkt ścieżki oraz rysuje robota w programie
 * \e gnuplot.
 */
void Robot::DodajRobota2()
{
    _PolozenieObiektu[0] = -250;
    _PolozenieObiektu[1] = -250;
    ZapiszDoPliku(Nazwa.c_str());
    sciezkowy.DodajPierwszyPunkt(_PolozenieObiektu[0], _PolozenieObiektu[1], NazwaSciezki);
}

/*!
 * Metoda zmieniająca położenie robota względem zadanego punktu.
 * Dodatkowo inicjalizuje pierwszy punkt ścieżki oraz rysuje robota w programie
 * \e gnuplot.
 */
void Robot::DodajRobota3()
{
    _PolozenieObiektu[0] = 0;
    _PolozenieObiektu[1] = 0;
    ZapiszDoPliku(Nazwa.c_str());
    sciezkowy.DodajPierwszyPunkt(_PolozenieObiektu[0], _PolozenieObiektu[1], NazwaSciezki);
}

/*!
 * Metoda przy pomocy iteratora sprawdza czy z żadnym z obiektów z listy obiektów graficznych,
 * nie zeszła kolizja wywołując odpowiednią metodę co do obiektu (metody wirtualne).
 *
 * Jeżli zaszła, zwraca \e true, jeżeli nie, \e false.
 */
bool Robot::DetekcjaKol(const std::list < std::shared_ptr <ObiektGraficzny> > &lista)
{
    for(std::list < std::shared_ptr <ObiektGraficzny> > :: const_iterator it = lista.begin(); it != lista.end(); ++it)
    {
        if((*it)->Kolizja(this->_PolozenieObiektu, this->Promien))
        {
            std::cout << "\n!!! Ruch nie moze zostac kontynuowany \n!!! ze wzgledu na wystapienie kolizji\n";
            return true;
        }
    }
    return false;
}

/*!
 * W oparciu o odlegść na jaką ma się przemieścić robot, obliczą wektor przesunięcią
 * ze wzoru:
 *
 * |x' = cos(Alpha) * odleglosc
 * |y' = sin(Alpha) * odleglosc
 *
 * Gdzie \e x' i \e y' to współrzędne wektora przsunięcia a \e Alpha
 * to kąt o jaki jest aktualnie obrócony robot. Jako, że chcemy uzyskać wersor
 * dzielimy prawą stronę równana przez \e odlegosc, zatem zostaje sam \e cos i \e sin.
 * Następnie w pętli \e for, metoda dokonuje przesunięcia robota dzięki funkcji \e PoruszOWektor,
 * wraz z animcją, przy uzyciu funkcji \e usleep. Przy każdym skoku o \e wektorPrzemieszczenia,
 * sprawdza czy zaszła kolizja robota z którymś z obiektów przy pomocy metody \e DetekcjaKol.
 *
 * \param dlugosc - ilosc jednostek na skali sceny, o które ma się przesunąć robot względem swojego
 * aktualnego położenia.
 * \param lista - aktualna lista wszystkich obiektów graficznych.
 */
void Robot::JedzProsto(double dlugosc, std::list < std::shared_ptr <ObiektGraficzny> > lista)
{
    Wektor2D wektorPrzemieszczenia;
    double tmp = dlugosc / szybkosc;

    wektorPrzemieszczenia[0] = cos(Alpha);
    wektorPrzemieszczenia[1] = sin(Alpha);

    for (unsigned int i = 0; i < tmp; ++i)
    {
        if(tmp - i < 1)
        {
           PoruszOWektor(wektorPrzemieszczenia * ((tmp - i) * szybkosc));
           if(DetekcjaKol(lista)) return;
           ZapiszDoPliku(Nazwa.c_str());
           sciezkowy.RysujSciezke(_PolozenieObiektu, NazwaSciezki);
           wsklacze->Rysuj();
           usleep(40000);
           return;
        }
        PoruszOWektor(wektorPrzemieszczenia * szybkosc);
        if(DetekcjaKol(lista)) return;
        ZapiszDoPliku(Nazwa.c_str());
        sciezkowy.RysujSciezke(_PolozenieObiektu, NazwaSciezki);
        wsklacze->Rysuj();
        usleep(40000);
    }
    return;
}

/*!
 * Zmienia wielkość robota względem skali podanej przez użytkownika. Metoda zawsze
 * najpierw uwzględnia aktualną skalę aby skalować robota przyjmując wartość podstawową
 * równą jeden. Zmienia również długość promienia robota.
 */
void Robot::Skaluj(double w)
{
    for(unsigned int i = 0; i < _TabWierz.size(); ++i)
    {
        _TabWierz[i][0] /= skala;
        _TabWierz[i][1] /= skala;
        _TabWierz[i][0] *= w;
        _TabWierz[i][1] *= w;
    }

    Promien /= skala;
    skala = w;
    Promien *= w;
    ZapiszDoPliku(Nazwa.c_str());
    wsklacze->Rysuj();
}

/*!
 * Konstruktor nadaje robotowi jego długość promienia, numer indeksu, oraz osobistą nazwę potrzebną przy zapisie do pliku.
 * Inicjalizuje również ten plik.
 * Konstruktor przeniesiony do sekcji \e private aby zapobiec przypadkowemu tworzeniu sie obiektow tej klasy.
 */
Robot::Robot(PzG::LaczeDoGNUPlota * lacznik)
{
    wsklacze = lacznik;

    Promien = 30;

    ++Indeks;

    Nazwa += "Robot" + std::to_string(Indeks) + ".dat";

    NazwaSciezki += "Sciezka" + std::to_string(Indeks) + ".dat";

    wsklacze->DodajNazwePliku(Nazwa.c_str(), PzG::RR_Ciagly, 3);
    wsklacze->DodajNazwePliku(NazwaSciezki.c_str(), PzG::RR_Ciagly,2);
}

/*!
 * Metoda potrzebna przy wyświetlaniu aktualnie używanego robota w metodzie sceny.
 */
Wektor2D Robot::ZwrocPolozenie()
{
    return _PolozenieObiektu;
}

/*!
 * Detekcja kolizji przebiega na zasadzie porównania odległości między środkami robotów,
 * do sumy promieni okręgów na nich opisanych. Zwraca \e true kiedy kolizja zaszła, oraz \e false
 * kiedy nie zaszła.
 *
 * \param wek - polożenie aktualnie używanego robota.
 * \param r - promień aktualnie używanego robota
 */
bool Robot::Kolizja(Wektor2D wek, double r)
{
    double a = abs(_PolozenieObiektu[0] - wek[0]);
    double b = abs(_PolozenieObiektu[1] - wek[1]);
    double dist = sqrt(pow(a, 2) + pow(b, 2));

    if(dist == 0) { return false; }
    if(Promien + r >= dist) { return true; }

    return false;
}
