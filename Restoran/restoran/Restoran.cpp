#include"Restoran.h"

Restoran::Restoran(Jelovnik *jelovnik)
:jelovnik(jelovnik), generator(new Generator(jelovnik)), kasa(0)
{

}

Restoran::~Restoran()
{
    delete generator;
}

void Restoran::dodajSto(Sto *sto)
{
    stolovi.push_back(sto);
}

Sto * Restoran::getSto() const
{
    for(auto it : stolovi)
    {
        if(it->isZauzeto() == false)
        {
            it->setZauzeto(true);
            return it;
        }
    }
    throw RestoranException("Svi stolovi su zauzeti!");
}

void Restoran::prikaziJelovnik() const
{
    time_t vreme = time(nullptr);
    tm * lokalnoVreme = localtime(&vreme);
    int sat = static_cast<int>(lokalnoVreme->tm_hour);
    jelovnik->prikaziJelovnik();
    cout << "\033[1;36mDnevni meni u " << sat << "h:\033[0m" << endl;
    generator->dajDnevnoJeloUSatu(sat);
    cout << "\t\033[1;36mCena: " << fixed << setprecision(2) << generator->getCena(sat) << " RSD\033[0m" << endl;
}

double Restoran::spremiJelo(const string &naziv) const
{
    try
    {
        return jelovnik->getCenuJela(naziv);
    }
    catch(const JeloException& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

void Restoran::prikaziDnevniMeni(const int &sat)
{
    cout << "\033[1;36mDnevni meni u " << sat << "h:\033[0m" << endl;
    generator->dajDnevnoJeloUSatu(sat);
    cout << "\t\033[1;36mCena: " << fixed << setprecision(2) << generator->getCena(sat) << " RSD\033[0m" << endl;
}

void Restoran::prikaziKasu() const
{
    cout << "Kasa: " << fixed << setprecision(2) << kasa << " RSD" << endl;
}