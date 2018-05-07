/*!
 * \file
 * \brief Zawiera definicje metod klasy Robot.
 *
 * Zawiera definicje metod klasy Robot
 * wraz z ich opisem.
 */

#include "Robot.hh"

/*!
 * Pobiera od użytkownika nową wartość szybkości i nadpisuje aktualną.
 */
void Robot::ZmienSzybkosc()
{
    double g;
    std::cout << "Prosze podac nowa szybkosc poruszania sie i obrotu dla robota: \n";
    std::cin >> g;
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
 * Wielkość opóźnienia jest oczywiście modyfikowalna przez zmienną \e szybkosc.
 *
 * \param b - kąt o który ma się obrócić robot podany w stopniach, potrzebny aby pętla
 * \e for wykonała odpowiednią ilość jedno-stopniowych obrotów.
 */
void Robot::obroc(double b)
{

    for (int i = 0; i < b; ++i)
    {
        Obrot(1);
        ZapiszDoPliku("figury/robot.dat");
        lacze.Rysuj();
        usleep(40000 / szybkosc);


    }

}

/*!
 * Tworzy wierzchołki robota o podanych współrzędnych
 * a następnie rysująca tego robota na scenie.
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

    ZapiszDoPliku("figury/robot.dat");
}

void Robot::DodajRobota()
{
    std::cout << "Podaj wspolrzedne srodka robota aby go stworzyc: " << std::endl;
    std::cin >> _PolozenieObiektu[0] >> _PolozenieObiektu[1];
    ZapiszDoPliku("figury/robot.dat");
    sciezkowy.DodajPierwszyPunkt(_PolozenieObiektu[0], _PolozenieObiektu[1]);
    lacze.Rysuj();
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
 * wraz z animcją, przy uzyciu funkcji \e usleep.
 *
 * \param dlugosc - ilosc jednostek na skali sceny, o które ma się przesunąć robot względem swojego
 * aktualnego położenia.
 */
void Robot::JedzProsto(double dlugosc)
{
    Wektor2D wektorPrzemieszczenia;

    wektorPrzemieszczenia[0] = cos(Alpha);
    wektorPrzemieszczenia[1] = sin(Alpha);

    for (unsigned int i = 0; i < dlugosc; ++i)
    {
        PoruszOWektor(wektorPrzemieszczenia);
        ZapiszDoPliku("figury/robot.dat");
        sciezkowy.RysujSciezke(_PolozenieObiektu);
        lacze.Rysuj();
        usleep(40000 / szybkosc);

    }
}

void Robot::Skaluj(double w)
{

    for(unsigned int i = 0; i < _TabWierz.size(); ++i)
    {
        _TabWierz[i][0] /= skala;
        _TabWierz[i][1] /= skala;
        _TabWierz[i][0] *= w;
        _TabWierz[i][1] *= w;
    }
    skala = w;
    ZapiszDoPliku("figury/robot.dat");
    lacze.Rysuj();
}
