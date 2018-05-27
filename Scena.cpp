/*!
 * \file
 * \brief Zawiera definicje metod klasy Scena.
 *
 * Zawiera definicje metod klasy Scena, wraz z ich opisem.
 */

#include "Scena.hh"

/*!
 * Inicjalizacja zmiennej statycznej.
 */
Fabryka Fabryka::fab;

/*!
 * Wyświetla informację o możliwych wyborach obsługiwanych przez program. Dodatkowo przy
 * użyciu metody \e PokazWektory wyświetla informacje o ilości obiektów typu \e Wektor2D.
 */
void Scena::WyswietlMenu()
{
    Wektor2D::PokazWektory();
    std::cout << "j -> Jazda na wprost" << std::endl;
    std::cout << "s -> Zmiana wielkosci robota" << std::endl;
    std::cout << "o -> Obrot o kat" << std::endl;
    std::cout << "w -> Ponowne wyswietlenie menu" << std::endl;
    std::cout << "g -> Selekcja robota" << std:: endl;
    std::cout << "z -> Zmiana szybkosci robota" << std::endl;
    std::cout << "q -> Dodanie nowej przeszkody" << std::endl;
    std::cout << "p -> Dodanie nowego robota" << std::endl << std::endl;
    std::cout << "k -> Zakonczenie dzialania programu" << std::endl;
}

/*!
 * Tworzy Roboty wraz ze wskaźnikami na nie, następnie wrzuca te wskaźniki do dwóch list
 * oraz wyświetla roboty na scenie.
 */
void Scena::DodajRoboty()
{

    std::shared_ptr <ObiektGraficzny > r = Fabryka::Buduj(Robocik, &lacze);
    std::shared_ptr <Robot> ro = std::static_pointer_cast < Robot >(r);

    LRobotow.push_back(ro);
    LObiektow.push_back(r);

    ++Rit;
    ++Oit;

    (*Rit)->InicjalizujKsztalt();
    (*Rit)->DodajRobota1();

    std::shared_ptr <ObiektGraficzny > r1 = Fabryka::Buduj(Robocik, &lacze);
    std::shared_ptr <Robot> ro1 = std::static_pointer_cast < Robot >(r1);

    LRobotow.push_back(ro1);
    LObiektow.push_back(r1);

    ++Rit;
    ++Oit;

    (*Rit)->InicjalizujKsztalt();
    (*Rit)->DodajRobota2();

    std::shared_ptr <ObiektGraficzny > r2 = Fabryka::Buduj(Robocik, &lacze);
    std::shared_ptr <Robot> ro2 = std::static_pointer_cast < Robot >(r2);

    LRobotow.push_back(ro2);
    LObiektow.push_back(r2);

    ++Rit;
    ++Oit;

    (*Rit)->InicjalizujKsztalt();
    (*Rit)->DodajRobota3();

}

/*!
 * Tworzy Przeszkody wraz ze wskaźnikami na nie, następnie wrzuca te wskaźniki do listy obiektów graficznych
 * oraz wyświetla przeszkody na scenie.
 */
void Scena::DodajPrzeszkody()
{
    std::shared_ptr <ObiektGraficzny > p = Fabryka::Buduj(Przeszkodzisko, &lacze);

    LObiektow.push_back(p);

    ++Oit;

    (*Oit)->DodajPrzeszkode1();

    std::shared_ptr <ObiektGraficzny > p1 = Fabryka::Buduj(Przeszkodzisko, &lacze);

    LObiektow.push_back(p1);

    ++Oit;

    (*Oit)->DodajPrzeszkode2();

    std::shared_ptr <ObiektGraficzny > p2 = Fabryka::Buduj(Przeszkodzisko, &lacze);

    LObiektow.push_back(p2);

    ++Oit;

    (*Oit)->DodajPrzeszkode3();
}


/*!
 * Zwraca dla użytkownika informacje o indeksie akulanie używanego robota, oraz jego punkcie położenia.
 */
void Scena::JakiRobot()
{
    int ktory = std::distance(LRobotow.begin(), Rit);
    std::cout << std::endl << std::endl << "Aktualnie wyselekscjonowanym robotem jest: "<< std::endl << "Robot " << ++ktory << ". \t";
    std::cout << "Wspolrzedne: " << (*Rit)->ZwrocPolozenie() << std::endl << std::endl;
}

/*!
 * Sprawdza czy na strumieniu \e std::cin jest ustawiona flaga \e fail() i tak długo
 * pobiera od użytkownika nową wartość aż będzie ona wartością liczbową.
 */
int Scena::Policjant()
{
    int w;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(),'\n');
        std::cout << "Prosze podac cyfre a nie znak!\n";
        std::cin >> w;
    }
    return w;
}

/*!
 * Korzystając z lity robotów ustawia iterator na danego robota którego chce obsługiwać użytkownik.
 */
void Scena::WyborRobota()
{
    unsigned int w;
    std::cout << std::endl << "Aktualnie aktywne roboty: " << std::endl;
    Rit = LRobotow.begin();

    for(unsigned int i = 1; i <= LRobotow.size(); ++i)
    {
        std::cout << "Robot " << i << "\t Wspolrzedne: " << (*Rit)->ZwrocPolozenie() << std::endl;
        if ((Rit != LRobotow.end()) && (next(Rit) == LRobotow.end())) break;
        Rit++;
    }

    std::cout << "Prosze wybrac robota: " << std::endl;
    std::cin >> w;
    if (std::cin.fail()) w = Policjant();
    Rit = LRobotow.begin();

    for(unsigned int i = 1; i < w; ++i)
    {
        ++Rit;
    }
}

/*!
 * Posiada menu do komunikacji z użytkownikiem w postaci \e switch'a, który
 * jest uodporniony na podanie opcji, która nie jest obsługiwana. Względem wybranej opcji odpala daną metodę dla robota.
 */
void Scena::Menu()
{
    char znak;
    std::cout << std::endl << "---------------Centrum Sterowania Robotem--------------------" << std::endl << std::endl;
    WyswietlMenu();
    do
    {
        JakiRobot();
        std::cout << "Twój wybór> ";
        std::cin >> znak;
        std::cout << "\n";

        switch(znak)
        {
        case 'j':
            int tmp;
            std::cout << "Podaj odleglosc (ilosc jednostek) na jaka ma sie przemiescic robot: \n";
            std::cin >> tmp;
            if (std::cin.fail()) tmp = Policjant();
            (*Rit)->JedzProsto(tmp, LObiektow);
            break;

        case 'w':
            WyswietlMenu();
            break;

        case 'z':
            int w;
            std::cout << "Prosze podac nowa szybkosc poruszania sie i obrotu dla robota: \n";
            std::cin >> w;
            if (std::cin.fail()) w = Policjant();
            (*Rit)->ZmienSzybkosc(w);
            break;

        case 'o':
            int tm;
            std::cout << "Podaj kat o jaki ma sie obrocic robot: \n";
            std::cin >> tm;
            if (std::cin.fail()) tm = Policjant();
            (*Rit)->obroc(tm);
            break;

        case 's':
            double a;
            std::cout << "Podaj wartosc do skalowania robota:  " << std::endl;
            std::cin >> a;
            if (std::cin.fail()) a = Policjant();
            (*Rit)->Skaluj(a);
            break;

        case 'g':
            WyborRobota();
            break;

        case 'p':
            NowyRobot();
            break;

        case 'q':
            NowaPrzeszkoda();
            break;


        default:
            if(znak == 'k')
            {
                std::cout << "Koniec dzialania programu, dziekuje za uzytkowanie! \n";
                return;
            }
            else
            {
                std::cout << "Proszę wybrać odpowiednia opcje. \n";
            }
            break;
        }
    }while(znak != 'k');

}

/*!
 * Scala najważniejsze metody programu w jedną, aby zachować przejrzystość funkcji \e main.
 */
void Scena::Run()
{
    DodajRoboty();
    DodajPrzeszkody();
    lacze.Rysuj();
    Menu();
}

/*!
 * Nowo stworzonego robota podpisuje pod dwa shared_ptry oraz wrzuca je do dwóch różnych list.
 * Następnie inicjalizuje tego robota na scenie i go tam rysuje.
 */
void Scena::NowyRobot()
{
    std::shared_ptr <ObiektGraficzny > w = Fabryka::Buduj(Robocik, &lacze);
    std::shared_ptr <Robot> wo = std::static_pointer_cast < Robot >(w);

    LRobotow.push_back(wo);
    LObiektow.push_back(w);

    Rit = LRobotow.end();
    Rit--;
    (*Rit)->InicjalizujKsztalt();
    (*Rit)->DodajRobota();
    lacze.Rysuj();
}

/*!
 * Nowo stworzoną przeszkodę podpisuje pod shared_ptr i wrzuca go do listy obiektów graficznych.
 * Następnie inicjaluzuje tą przeszkodę i rysuja ją na scenie.
 */
void Scena::NowaPrzeszkoda()
{
    std::shared_ptr <ObiektGraficzny > p = Fabryka::Buduj(Przeszkodzisko, &lacze);

    LObiektow.push_back(p);

    Oit = LObiektow.end();
    Oit--;

    (*Oit)->DodajPrzeszkode();
    lacze.Rysuj();
}
