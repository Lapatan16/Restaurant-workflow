#include"Jelovnik.h"

Jelovnik::Jelovnik()
{

}

Jelovnik::~Jelovnik()
{
    
}

const string Jelovnik::katToString(KATEGORIJA_JELA kat) const
{
    if(kat == PREDJELO)
        return "Predjelo";
    else if(kat == GLAVNO)
        return "Glavno jelo";
    return "Dezert";
}

void Jelovnik::dodajJelo(Jelo *j)
{
    for(auto it : jelovnik)
    {
        if(j->getNaziv() == it->getNaziv())
            throw JeloException("Jelo vec postoji u jelovniku!");
    }
    jelovnik.push_back(j);
}

Jelo * Jelovnik::getJelo(const string &naziv) const
{
    for(auto it : jelovnik) 
    {
        if(it->getNaziv() == naziv)
            return it;
    }
    throw JeloException("Jelo ne postoji u jelovniku!");
}

vector<Jelo *> Jelovnik::getJelaPoKat(KATEGORIJA_JELA kat) const
{
    vector<Jelo *> jela;
    for(auto it : jelovnik)
    {
        if(it->getKategorija() == kat)
        {
            jela.push_back(it);
        }
    }
    return jela;
}

void Jelovnik::izbaciJelo(const string &naziv)
{
    for(vector<Jelo *>::iterator it = jelovnik.begin(); it < jelovnik.end(); it++)
    {
        if((*it)->getNaziv() == naziv)
        {
            jelovnik.erase(it);
            return;
        }
    }
    throw JeloException("Jelo ne postoji u jelovniku!");
}

void Jelovnik::prikaziJelovnik() const
{
    cout << "\033[1;36mJelovnik:\033[0m" << endl;
    for(int i = 0; i < 3; i++)
    {
        vector<Jelo *> jela = getJelaPoKat(((KATEGORIJA_JELA)(PREDJELO + i)));
        cout << "\033[1;32m" << katToString(((KATEGORIJA_JELA)(PREDJELO + i))) << ":\033[0m" << endl;
        for(auto it : jela)
        {
            cout << *it << endl;
        }
    }
}

double Jelovnik::getCenuJela(const string &naziv) const
{
    for(auto it : jelovnik)
    {
        if(it->getNaziv() == naziv)
        {
            return it->getCena();
        }
    }
    throw JeloException("Jelo ne postoji u jelovniku!");
}