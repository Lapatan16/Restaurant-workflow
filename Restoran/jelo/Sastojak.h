#ifndef SASTOJAK_H
#define SASTOJAK_H

#include"iostream"
using namespace std;
#include"KAT_SASTOJKA.h"

class Sastojak
{
    private:
        const string naziv;
        double cena;
        KATEGORIJA kategorija;

    public:
        Sastojak(const string &, const double &, KATEGORIJA);
        const string getNaziv() const;
        const double getCena() const;
        KATEGORIJA getKategorija() const;
        void setCena(const double &);
};

#endif