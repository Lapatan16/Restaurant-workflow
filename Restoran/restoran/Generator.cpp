#include"Generator.h"

Generator::Generator(Jelovnik *j)
:jelovnik(j)
{
    meni.resize(24);
    cene.resize(24);
    for(int i = 0; i < 24; i++)
        meni[i].resize(3);
    srand(time(nullptr));
    try
    {
        generate();
    }
    catch(const RestoranException& e)
    {
        std::cerr << e.what() << '\n';
    } 
}

void Generator::generate()
{
    for(int j = 0; j < 24; j++)
    {
        cene[j] = 0;
        for(int i = 0; i < 3; i++)
        {
            vector<Jelo *> jela;
            int k = -1;
            
            jela = jelovnik->getJelaPoKat(((KATEGORIJA_JELA)(PREDJELO + i)));
            if(jela.size() == 0)
                throw RestoranException("Nema dovoljno kategorija jela!");
            k = rand() % jela.size();
            meni[j][i] = jela[k];
            cene[j] += jela[k]->getCena();
        }
    }
}

void Generator::dajDnevnoJeloUSatu(const int &sat)
{
    cout << "\t\033[1;35mPredjelo: " << (meni[sat])[0]->getNaziv() << endl << "\tGlavno jelo: " << (meni[sat])[1]->getNaziv() << endl << "\tDezert: " << (meni[sat])[2]->getNaziv() << "\033[0m" << endl;
}
const double Generator::getCena(const int &sat) const
{
    return cene[sat];
}