#ifndef JELO_H
#define JELO_H

#include"Sastojak.h"
#include"vector"
#include"KAT_JELA.h"
#include"sstream"
#include"iomanip"
#include"../exception/JeloException.h"

class Jelo
{
    private:
        const string naziv;
        vector<Sastojak *> sastojci;
        double cena;
        static double PDV;
        KATEGORIJA_JELA kategorija;
        KATEGORIJA_JELA podKategorija;
        double getCenaSastojaka() const;
        const string toString();
        string pomocna();
        string podKategorijaToString() const;

    public:
        Jelo(const string &, KATEGORIJA_JELA, KATEGORIJA_JELA);
        void dodajSastojak(Sastojak *);
        void izbaciSastojak(const string &);
        void postaviCenu(const double &);
        KATEGORIJA_JELA getKategorija() const;
        const string &getNaziv() const;
        friend ostream &operator<<(ostream &, Jelo &);
        const double getCena() const;
};  

#endif