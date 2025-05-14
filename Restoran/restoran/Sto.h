#ifndef STO_H
#define STO_H

class Konobar;

class Sto
{
    private:
        Konobar *konobar;
        bool zauzet;
        int id;
        double racun;
        
        static int br;

    public:
        Sto(Konobar *);
        Konobar * getKonobar() const;
        bool isZauzeto() const;
        void setZauzeto(const bool);
        void uvecajRacun(const double &);
        double getRacun() const;
        int getID() const;
        void resetujRacun();
};


#endif