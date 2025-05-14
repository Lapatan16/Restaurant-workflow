#ifndef OSOBA_H
#define OSOBA_H

#include"iostream"
using namespace std;

class Osoba
{
    private:
        const string ime;
        const string prezime;

    protected:
        Osoba(const string &ime, const string& prezime);
        virtual const string toString() const;

    public:
        virtual ~Osoba();
};

#endif