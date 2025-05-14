#ifndef RESTORAN_H  
#define RESTORAN_H

#include"../jelo/Jelovnik.h"
#include"Generator.h"
#include"../osoba/Konobar.h"
#include"Sto.h"
#include"ctime"

class Restoran
{
    private:
        Jelovnik *jelovnik;
        vector<Sto *> stolovi;
        Generator *generator;
        double kasa;

        friend void Konobar::naplatiRacun(Musterija *, const double &);

    public:
    
        Restoran(Jelovnik *);
        ~Restoran();
        void dodajSto(Sto *);
        Sto * getSto() const;
        void prikaziJelovnik() const;
        double spremiJelo(const string &) const;
        void prikaziDnevniMeni(const int &);
        void prikaziKasu() const;
};  

#endif