#include"Jelo.h"

double Jelo::PDV(0.2);

Jelo::Jelo(const string &naziv, KATEGORIJA_JELA kategorija, KATEGORIJA_JELA podKategorija)
:naziv(naziv), kategorija(kategorija), cena(0), podKategorija(podKategorija)
{
    if(podKategorija < 3 || kategorija > 2)
        throw("Nepravilna pod kategorija jela!");
}

double Jelo::getCenaSastojaka() const
{
    double cena = 0;
    for(auto it : sastojci)
    {
        cena += it->getCena();
    }
    return cena;
}

void Jelo::dodajSastojak(Sastojak *s)
{
    for(auto it : sastojci)
    {
        if(s->getNaziv() == it->getNaziv())
        {
            throw JeloException("Nije moguce dodati sastojak koji vec postoji u nizu!");
        }
    }
    sastojci.push_back(s);
}

void Jelo::izbaciSastojak(const string &naziv)
{
    for(vector<Sastojak *>::iterator it = sastojci.begin(); it != sastojci.end(); it++)
    {
        if(naziv == (*it)->getNaziv())
        {
            sastojci.erase(it);
            return;
        }
    }
    throw JeloException("Sastojak ne postoji u nizu!");
}

void Jelo::postaviCenu(const double &c)
{
    cena += getCenaSastojaka() + c;
    cena += cena * PDV;
}

KATEGORIJA_JELA Jelo::getKategorija() const
{
    return kategorija;
}

const string &Jelo::getNaziv() const
{
    return naziv;
}

string Jelo::podKategorijaToString() const
{
    if(podKategorija == TOPLO)
        return "TOPLO";
    return "HLADNO";
}

string Jelo::pomocna()
{
    ostringstream s;
    s << naziv << ", \033[1;32m" << podKategorijaToString() << "\033[1;35m, " << fixed << setprecision(2) << cena;
    return s.str();
}

const string Jelo::toString()
{
    string s = "\t\033[1;35m" + pomocna() + " RSD\n\033[0m";
    s += "\t\033[1;33m(";
    int i = 0;
    for(auto it : sastojci)
    {
        if(i == 0)
            s += it->getNaziv();
        else
            s += ", " + it->getNaziv();
        i++;
    }
    s += ")\033[0m";
    return s;
}

ostream &operator<<(ostream &out, Jelo &j)
{
    return out << j.toString();
}

const double Jelo::getCena() const
{
    return cena;
}