#ifndef MUSTERIJA_H
#define MUSTERIJA_H

#include"Osoba.h"
#include"Konobar.h"
#include"../restoran/Restoran.h"

class Musterija : public Osoba
{
    private:
        double novac;
        int idStola;
        Konobar *konobar;
        bool placeno;
        
        friend void Konobar::naplatiRacun(Musterija *m, const double &racun);
    
    protected:
        const string toString() const override;
        
    public:
        Musterija(const string &, const string &, const double &);
        void rezervisiSto(Restoran *);
        void prikaziJelovnik();
        void naruciJelo(const string &);
        void platiRacun();
        void oslobodiSto();
        void zatraziDnevniMeni(const int &);
        friend ostream & operator<<(ostream &, Musterija &);
};

#endif