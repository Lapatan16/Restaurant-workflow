#include"Musterija.h"

Konobar::Konobar(const string &ime, const string &prezime, Restoran *restoran)
:Osoba(ime, prezime), restoran(restoran)
{

}

void Konobar::dodajSto(Sto *sto)
{
    cout << *this << " je zaduzen za sto broj " << sto->getID() << "." << endl;
    stolovi.push_back(sto);
}

void Konobar::uzmiNarudzbinu(const string &naziv, const int &idStola)
{
    for(auto it : stolovi)
    {
        if(it->getID() == idStola)
        {
            cout << *this << " uzima narudzbinu za jelo: " << naziv << " na stolu " << idStola << "." << endl;
            it->uvecajRacun(restoran->spremiJelo(naziv));
            return;
        }
    }
    throw OsobaException("Sto ne postoji!");
}

void Konobar::prikaziMeni() const
{
    restoran->prikaziJelovnik();
}

double Konobar::izdajRacun(const int &idStola) const
{
    for(auto it : stolovi)
    {
        if(idStola == it->getID())
        {
            cout << "Racun iznosi: " << fixed << setprecision(2) << it->getRacun() << " RSD" << endl;
            return it->getRacun();
        }
    }
    throw OsobaException("Sto ne postoji!");
}

void Konobar::oslobodiSto(const int &idStola)
{
    for(auto it : stolovi)
    {
        if(it->getID() == idStola)
        {
            it->setZauzeto(false);
            it->resetujRacun();
            return;
        }
    }
    throw OsobaException("Sto ne postoji!");
}

void Konobar::naplatiRacun(Musterija *m, const double &racun)
{
    cout << *this << " naplacuje racun od " << *m << endl;
    m->novac -= racun;
    restoran->kasa += racun;
}

void Konobar::prikaziDnevniMeni(const int &sat)
{
    restoran->prikaziDnevniMeni(sat);
}

const string Konobar::toString() const
{
    return "Konobar: " + Osoba::toString();
}

ostream &operator<<(ostream &out, Konobar &k)
{
    return out << k.toString();
}