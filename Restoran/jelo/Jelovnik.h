#ifndef JELOVNIK_H
#define JELOVNIK_H

#include"Jelo.h"

class Jelovnik
{
    private:
        vector<Jelo *> jelovnik;

        const string katToString(KATEGORIJA_JELA) const;

    public:
        Jelovnik();
        ~Jelovnik();
        void dodajJelo(Jelo *);
        vector<Jelo *> getJelaPoKat(KATEGORIJA_JELA) const;
        Jelo * getJelo(const string &) const;
        void izbaciJelo(const string &);
        void prikaziJelovnik() const;   
        double getCenuJela(const string &) const; 
};

#endif