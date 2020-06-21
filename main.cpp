#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <conio.h>

using namespace std;

class Konto{
    public:
    string login, haslo;

    void dodaj(){
        cout << " Podaj login do logowania: " << endl;
        cin >> login;
        cout << " Podaj haslo: " << endl;
        cin >> haslo;

        fstream plik;
        plik.open("plik.txt", ios::out);

        plik<<login<<endl;
        plik<<haslo<<endl;


        plik.close();

        cout <<"Konto zostalo zalozone, prosze sie zalogowac ponownie"<< endl;

    }

};
class Logowanie{
    public:
    int wybor;
    int zamow;
    double stankonta;
    double reszta;
    double kwota;
    double nr_konta;
    string hist;
    string dane;
    string zmiana;
    string odbiorca;
    string zlogin;
    string zhaslo;
    string login;
    string haslo;


void kontrola()
{
    fstream plik;
    plik.open("plik.txt",ios::in);

    if (plik.good()==false)
    {
        cout<<"Nie mozna sie zalogowac! ";
        exit(0);
    }

    getline(plik, zlogin);
    cout <<"Podaj login: "<< endl;
    cin >> login;
    getline(plik, zhaslo);
    cout <<"Podaj haslo: "<< endl;
    cin >> haslo;

    plik.close();

    if((zlogin == login)&&(zhaslo==haslo))
    {
        cout <<"Logowanie przebieglo prawidlowo! "<< endl;
        menu();
    }
    else
    {
        cout <<"Bledne logowanie! "<< endl;
        system("cls");

        kontrola();

    }

}

void stan_k()
{
        system("cls");
        ifstream plikk;
        plikk.open("stan.txt",ios::in);

    if (plikk.good()==false)
    {
    cout<<"Nie mozna sie sprawdzic stanu konta! ";
    exit(0);
    }

        plikk >> stankonta;
        cout << "Stan konta wynosi: "<< stankonta << " zl" << endl;
        plikk.close();

    cout << "Czy chcesz przejsc do menu? tak lub nie " << endl;
    cin >> zmiana;
    if(zmiana=="tak")
    {
	    menu();
	}
    else exit(0);

}

void przelew()
{
    system("cls");

    fstream plikkh;
    plikkh.open("historia.txt",ios::out | ios::app);

    cout << "Podaj nr konta"<< endl;
    cin >> nr_konta;
    cout << "Podaj odbiorce"<< endl;
    cin >> odbiorca;
    cout << "Podaj kwote"<< endl;
    cin >> kwota;

    plikkh << nr_konta;
    plikkh << odbiorca;
    plikkh << kwota;

    plikkh.close();

    ifstream plikk;
    plikk.open("stan.txt",ios::out | ios::app);
    plikk >> stankonta;

    stankonta = stankonta - kwota;
    plikk.close();

    fstream plik;
    plik.open("stan.txt",ios::out);

    plik << stankonta;
    cout << " Na koncie pozostalo: "<<stankonta<<" zl"<< endl;
    cout << " Przelew zostal wykonany! "<< endl;

    plik.close();

    cout << "Czy chcesz przejsc do menu? tak lub nie " << endl;
    cin >> zmiana;
    if(zmiana=="tak")
    {
	    menu();
	}
    else exit(0);
}

void karta()
{
    cout <<"Czy chcesz zamowic karte"<< endl;
    cout <<"1. Tak, chce zamowic"<< endl;
    cout <<"2. Nie, przejdz do menu "<< endl;
    cin >> zamow;
    if (zamow == 1)
	{

	    do
	    {
		    cout << "Prosze podac miasto" << endl;
            cin >> dane;
            cout << "Prosze podac ulice" << endl;
            cin >> dane;
            cout << "Prosze podac numer zamieszkania" << endl;
            cin >> dane;


	    }
        while(zmiana=="tak");

    cout << "Czy chcesz zmienic dane? tak lub nie " << endl;
    cin >> zmiana;

	}
	else if(zamow == 2)
	{
		menu();
	}
}

void historia()
{
    fstream plik;
    plik.open("historia.txt");
    while (!plik.eof())
    {

        plik>>hist;

        cout<<hist<<endl;
    }
    plik.close();

}

void menu()
{
    system("cls");

    cout << "Wybierz co chcesz zrobic "<< endl;
    cout << "1. Sprawdz stan konta"<< endl;
    cout << "2. Zrob przelew"<< endl;
    cout << "3. Zamow karte"<< endl;
    cout << "4. Sprawdz historie"<< endl;
    cout << "5. Wyjscie"<< endl;
    cin >> wybor;

    switch(wybor)
    {

        case 1:

        stan_k();

        break;

        case 2:

        przelew();

        break;

        case 3:

        karta();

        break;

        case 4:

        historia();

        break;
        case 5:

        exit(0);

        break;
        default:
        break;
        }
}

};


int main()
{

    int wybor;
    string decyzja;
    cout << " Jesli jestes nowym klientem to zaloz konto. " << endl;
    cout << "1. Zalozenie konta  "<< endl;
    cout << "2. Logowanie" << endl;
    cout << "3. Wyjscie" << endl;
    cin >> wybor;


    if (wybor == 1)
	{
	    do
	    {
		    Konto k1;
            k1.dodaj();
            cout << "Czy chcesz zmienic dane? tak lub nie " << endl;
            cin >> decyzja;
	    }
        while(decyzja=="tak");
        return main();
	}
	else if (wybor == 2)
	{
		Logowanie l1;
        l1.kontrola();
	}
	else
	{
	    return 0;
	}

    system("PAUSE");
}
