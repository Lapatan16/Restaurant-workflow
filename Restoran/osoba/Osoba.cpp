#include"Osoba.h"

Osoba::Osoba(const string &ime, const string &prezime)
:ime(ime), prezime(prezime)
{

}

Osoba::~Osoba()
{

}

const string Osoba::toString() const
{
    string s = ime + " " + prezime;
    return s;
}

// const string Osoba::getIme() const
// {
//     return ime;
// }

// const string Osoba::getPrezime() const
// {
//     return prezime;
// }