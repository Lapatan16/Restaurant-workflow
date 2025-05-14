#include"Sastojak.h"

Sastojak::Sastojak(const string &naziv, const double &cena, KATEGORIJA kategorija)
:naziv(naziv), cena(cena), kategorija(kategorija)
{

}

const string Sastojak::getNaziv() const
{
    return naziv;
}

const double Sastojak::getCena() const
{
    return cena;
}

KATEGORIJA Sastojak::getKategorija() const
{
    return kategorija;
}

void Sastojak::setCena(const double &cena)
{
    this->cena += cena;
}