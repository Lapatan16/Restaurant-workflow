#ifndef KONOBAR_H
#define KONOBAR_H

class Musterija;
class Restoran;
class Sto;

#include"Osoba.h"
#include"../exception/OsobaException.h"
#include"vector"

class Konobar : public Osoba
{
    private:
        Restoran *restoran;
        vector<Sto *> stolovi;

    protected:
        const string toString() const override;

    public:
        Konobar(const string &, const string &, Restoran *);
        void dodajSto(Sto *);
        void uzmiNarudzbinu(const string &, const int &);
        void prikaziMeni() const;
        double izdajRacun(const int &) const;
        void naplatiRacun(Musterija *, const double &);
        void oslobodiSto(const int &);
        void prikaziDnevniMeni(const int &);
        friend ostream & operator<<(ostream &, Konobar &);

};

#endif