#include"../osoba/Musterija.h"
#include"../restoran/Generator.h"

int main()
{
    Sastojak *s1 = new Sastojak("Krompir", 20, NEUTRALNO);
    Sastojak *s2 = new Sastojak("Sunka", 30, NEUTRALNO);
    Sastojak *s3 = new Sastojak("Kackavalj", 35, SLATKO);
    Sastojak *s4 = new Sastojak("Prezla", 15, SLANO);
    Sastojak *s5 = new Sastojak("Svinjsko Meso", 500, SLANO);
    Sastojak *s6 = new Sastojak("Luk", 20, SLANO);
    Sastojak *s7 = new Sastojak("Zacin", 10, SLANO);
    Sastojak *s8 = new Sastojak("Mleko", 35, NEUTRALNO);
    Sastojak *s9 = new Sastojak("Voce", 40, SLATKO);
    Sastojak *s10 = new Sastojak("Secer", 20, SLATKO);
    Sastojak *s11 = new Sastojak("So", 10, SLANO);
    Sastojak *s12 = new Sastojak("Brasno", 20, NEUTRALNO);
    Sastojak *s13 = new Sastojak("Jaje", 20, NEUTRALNO);
    Sastojak *s14 = new Sastojak("Kisela Voda", 25, NEUTRALNO);
    Sastojak *s15 = new Sastojak("Pilece Meso", 400, SLANO);
    Sastojak *s16 = new Sastojak("Cajna", 25, SLANO);

    Jelo *j1 = new Jelo("Svedski sto", PREDJELO, HLADNO);
    Jelo *j2 = new Jelo("Supa", PREDJELO, TOPLO);
    Jelo *j3 = new Jelo("Cevapi", GLAVNO, TOPLO);
    Jelo *j4 = new Jelo("Punjena pljeskavica", GLAVNO, TOPLO);
    Jelo *j5 = new Jelo("Gurmanska pljeskavica", GLAVNO, TOPLO);
    Jelo *j6 = new Jelo("Becka snicla", GLAVNO, TOPLO);
    Jelo *j7 = new Jelo("Karadjordjeva snicla", GLAVNO, TOPLO);
    Jelo *j8 = new Jelo("Sladoled", DEZERT, HLADNO);
    Jelo *j9 = new Jelo("Palacinke", DEZERT, TOPLO);
    Jelo *j10 = new Jelo("Banana split", DEZERT, TOPLO);

    try
    {
        j1->dodajSastojak(s2);
        j1->dodajSastojak(s3);
        j1->dodajSastojak(s16);

        j2->dodajSastojak(s7);
        j2->dodajSastojak(s11);

        j3->dodajSastojak(s5);
        j3->dodajSastojak(s7);
        j3->dodajSastojak(s11);

        j4->dodajSastojak(s5);
        j4->dodajSastojak(s7);
        j4->dodajSastojak(s3);

        j5->dodajSastojak(s5);
        j5->dodajSastojak(s7);
        j5->dodajSastojak(s6);

        j6->dodajSastojak(s4);
        j6->dodajSastojak(s7);
        j6->dodajSastojak(s11);
        j6->dodajSastojak(s15);

        j7->dodajSastojak(s4);
        j7->dodajSastojak(s7);
        j7->dodajSastojak(s11);
        j7->dodajSastojak(s15);
        j7->dodajSastojak(s3);

        j8->dodajSastojak(s8);
        j8->dodajSastojak(s10);
        j8->dodajSastojak(s13);

        j9->dodajSastojak(s8);
        j9->dodajSastojak(s10);
        j9->dodajSastojak(s13);
        j9->dodajSastojak(s14);
        j9->dodajSastojak(s9);
    }
    catch(const JeloException& e)
    {
        std::cerr << e.what() << '\n';
    }

    j1->postaviCenu(20);
    j2->postaviCenu(20);
    j3->postaviCenu(40);
    j4->postaviCenu(40);
    j5->postaviCenu(40);
    j6->postaviCenu(40);
    j7->postaviCenu(30);
    j8->postaviCenu(30);
    j9->postaviCenu(30);

    try // Primer hvatanja greske kada se doda isti sastojak vise puta!
    {
        j10->dodajSastojak(s8);
        j10->dodajSastojak(s8);
    }
    catch(const JeloException& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    Jelovnik *jelovnik = new Jelovnik();

    try
    {
        jelovnik->dodajJelo(j1);
        jelovnik->dodajJelo(j2);
        jelovnik->dodajJelo(j3);
        jelovnik->dodajJelo(j4);
        jelovnik->dodajJelo(j5);
        jelovnik->dodajJelo(j6);
        jelovnik->dodajJelo(j7);
        jelovnik->dodajJelo(j8);
        jelovnik->dodajJelo(j9);
    }
    catch(const JeloException& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    Jelovnik *jelovnik2 = new Jelovnik();

    try // primer hvatanja greske pri dodavanju istog jela vise puta
    {
        jelovnik->dodajJelo(j1);
        jelovnik->dodajJelo(j1);
    }
    catch(const JeloException& e)
    {
        std::cerr << e.what() << '\n';
    }

    Restoran *restoran = new Restoran(jelovnik);

    Konobar *k1 = new Konobar("Pera", "Peric", restoran);
    Konobar *k2 = new Konobar("Janko", "Jankovic", restoran);
    Konobar *k3 = new Konobar("Marko", "Markovic", restoran);

    Sto *sto1 = new Sto(k1);
    Sto *sto2 = new Sto(k1);
    Sto *sto3 = new Sto(k1);
    Sto *sto4 = new Sto(k2);
    Sto *sto5 = new Sto(k3);
    Sto *sto6 = new Sto(k3);

    restoran->dodajSto(sto1);    
    restoran->dodajSto(sto2);    
    restoran->dodajSto(sto3);    
    restoran->dodajSto(sto4);    
    restoran->dodajSto(sto5);    
    restoran->dodajSto(sto6);

    Musterija *m1 = new Musterija("Ivan", "Ivanovic", 2500);
    Musterija *m2 = new Musterija("Mihajlo", "Mihajlovic", 50);
    Musterija *m3 = new Musterija("Pera", "Peric", 1500);
    Musterija *m4 = new Musterija("Nikola", "Nikolic", 3000);
    Musterija *m5 = new Musterija("Luka", "Lukic", 3000);
    Musterija *m6 = new Musterija("Nikola", "Jokic", 3000);
    Musterija *m7 = new Musterija("Novak", "Djokovic", 3000);

    try
    {
        m1->rezervisiSto(restoran);
        m1->prikaziJelovnik();
        m1->naruciJelo("Supa");
        m1->naruciJelo("Cevapi");
        m1->naruciJelo("Sladoled");
        m1->platiRacun();
        m1->oslobodiSto();
    }
    catch(const OsobaException& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try // primer hvatanja greske kada musterija nema dovoljno para da plati racun
    {
        m2->rezervisiSto(restoran);
        m2->prikaziJelovnik();
        m2->naruciJelo("Svedski sto");
        m2->platiRacun();
        m2->oslobodiSto();
    }
    catch(const OsobaException& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        m3->rezervisiSto(restoran);
        m3->prikaziJelovnik();
        m3->naruciJelo("Svedski sto");
        m3->naruciJelo("Gurmanska pljeskavica");
        m3->naruciJelo("Karadjordjeva snicla");
        m3->naruciJelo("Palacinke");
        m3->platiRacun();
        m3->oslobodiSto();
    }
    catch(const OsobaException& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        m4->rezervisiSto(restoran);
        m4->zatraziDnevniMeni(12);
        m4->naruciJelo("Svedski sto");
        m4->naruciJelo("Gurmanska pljeskavica");
        m4->naruciJelo("Karadjordjeva snicla");
        m4->naruciJelo("Palacinke");
        m4->platiRacun();
        m4->oslobodiSto();
    }
    catch(const OsobaException& e)
    {
        std::cerr << e.what() << '\n';
    }

    try // hvatanje greske kada nema vise stolova
    {
        m1->rezervisiSto(restoran);
        m3->rezervisiSto(restoran);
        m4->rezervisiSto(restoran);
        m5->rezervisiSto(restoran);
        m6->rezervisiSto(restoran);
        m7->rezervisiSto(restoran);
    }
    catch(const OsobaException& e)
    {
        std::cerr << e.what() << '\n';
    }

    restoran->prikaziKasu();

    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    delete s6;
    delete s7;
    delete s8;
    delete s9;
    delete s10;
    delete s11;
    delete s12;
    delete s13;
    delete s14;
    delete s15;
    delete s16;
    delete j1;
    delete j2;
    delete j3;
    delete j4;
    delete j5;
    delete j6;
    delete j7;
    delete j9;
    delete j10;
    delete jelovnik;
    delete restoran;
    delete k1;
    delete k2;
    delete k3;
    delete sto1;
    delete sto2;
    delete sto3;
    delete sto4;
    delete sto5;
    delete sto6;
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
    delete m6;
    delete m7;

    return 0;
}