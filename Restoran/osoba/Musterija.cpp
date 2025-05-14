#include"Musterija.h"

Musterija::Musterija(const string &ime, const string &prezime, const double &novac)
:Osoba(ime, prezime), novac(novac), placeno(true)
{

}

void Musterija::rezervisiSto(Restoran *restoran)
{
    try
    {
        Sto *sto = restoran->getSto();
        konobar = sto->getKonobar();
        idStola = sto->getID();
        cout << *this << " je rezervisao sto broj: " << idStola << endl;
    }
    catch(const RestoranException& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Musterija::prikaziJelovnik()
{
    konobar->prikaziMeni();
}

void Musterija::naruciJelo(const string &naziv)
{
    try
    {
        konobar->uzmiNarudzbinu(naziv, idStola);
        placeno = false;
    }
    catch(const OsobaException& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void Musterija::platiRacun()
{
    try
    {
        double racun = konobar->izdajRacun(idStola);
        if(novac - racun < 0)
            throw OsobaException("Musterija nema dovoljno novca!");
        konobar->naplatiRacun(this, racun);
        cout << *this << " je uspesno platio racun."<< endl;
        placeno = true;
    }
    catch(const OsobaException& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Musterija::oslobodiSto()
{
    try
    {
        if(!placeno)
            throw OsobaException("Racun nije placen!");
        konobar->oslobodiSto(idStola);
        cout << *this << " je oslobodio sto broj: " << idStola << endl << endl;
    }
    catch(const OsobaException& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Musterija::zatraziDnevniMeni(const int &sat)
{
    konobar->prikaziDnevniMeni(sat);
}

const string Musterija::toString() const
{
    return "Musterija: " + Osoba::toString();
}

ostream &operator<<(ostream &out, Musterija &m)
{
    return out << m.toString();
}


