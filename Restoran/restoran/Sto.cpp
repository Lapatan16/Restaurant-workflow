#include"../osoba/Musterija.h"

int Sto::br(1);

Sto::Sto(Konobar *k)
:konobar(k), id(br++), zauzet(false), racun(0)
{
    k->dodajSto(this);
}

Konobar *Sto::getKonobar() const
{
    return konobar;
}

bool Sto::isZauzeto() const
{
    return zauzet;
}

void Sto::setZauzeto(const bool stanje)
{
    zauzet = stanje;
}

void Sto::uvecajRacun(const double &suma)
{
    racun += suma;
}

double Sto::getRacun() const
{
    return racun;
}

int Sto::getID() const
{
    return id;
}

void Sto::resetujRacun()
{
    racun = 0;
}
