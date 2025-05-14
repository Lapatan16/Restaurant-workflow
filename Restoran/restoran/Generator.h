#ifndef GENERATOR_H
#define GENERATOR_H

#include"../jelo/Jelovnik.h"
#include"../exception/RestoranException.h"

class Generator
{
    private:
        Jelovnik *jelovnik;
        vector<vector<Jelo *>> meni;
        vector<double> cene;

        void generate();
        
    public:
        Generator(Jelovnik *j);
        void dajDnevnoJeloUSatu(const int &sat);
        const double getCena(const int &) const;
};

#endif