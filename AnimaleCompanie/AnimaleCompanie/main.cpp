#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Caine {
public:
    string rasa;
    int varsta;
    double greutate;
    static int nrCaini;
    const string tip;
    char* sunet;

    Caine() : rasa("Necunoscuta"), varsta(0), greutate(0.0), tip("Caine") {
        nrCaini++;
        sunet = new char[strlen("Ham!") + 1];
        strcpy_s(sunet, strlen("Ham!") + 1, "Ham!");
    }

    Caine(string r, int v) : rasa(r), varsta(v), greutate(0.0), tip("Caine") {
        nrCaini++;
        sunet = new char[strlen("Ham!") + 1];
        strcpy_s(sunet, strlen("Ham!") + 1, "Ham!");
    }

    Caine(string r, int v, double g)
        : rasa(r), varsta(v), greutate(g), tip("Caine") {
        nrCaini++;
        sunet = new char[strlen("Ham! Ham!") + 1];
        strcpy_s(sunet, strlen("Ham! Ham!") + 1, "Ham! Ham!");
    }

    void latra() {
        cout << sunet << endl;
    }

    void afiseaza() {
        cout << tip << " de rasa " << rasa
            << ", varsta: " << varsta
            << " ani, greutate: " << greutate << " kg." << endl;
    }

    // --- Functie statica: calculeaza varsta medie (exemplu generic)
    static double calculeazaVarstaMedie(int totalVarsta) {
        if (nrCaini == 0) return 0;
        return (double)totalVarsta / nrCaini;
    }

    ~Caine() {
        delete[] sunet;
    }
};
int Caine::nrCaini = 0;


class Pisica {
public:
    string nume;
    string culoare;
    bool esteSterilizata;
    static int nrPisici;
    const string tip;
    char* sunet;

    Pisica() : nume("Anonima"), culoare("necunoscuta"), esteSterilizata(false), tip("Pisica") {
        nrPisici++;
        sunet = new char[strlen("Miau!") + 1];
        strcpy_s(sunet, strlen("Miau!") + 1, "Miau!");
    }

    Pisica(string n, string c) : nume(n), culoare(c), esteSterilizata(false), tip("Pisica") {
        nrPisici++;
        sunet = new char[strlen("Miau!") + 1];
        strcpy_s(sunet, strlen("Miau!") + 1, "Miau!");
    }

    Pisica(string n, string c, bool s)
        : nume(n), culoare(c), esteSterilizata(s), tip("Pisica") {
        nrPisici++;
        sunet = new char[strlen("Miau!") + 1];
        strcpy_s(sunet, strlen("Miau!") + 1, "Miau!");
    }

    void toarce() {
        cout << nume << " toarce linistit. " << sunet << endl;
    }

    void afiseaza() {
        cout << tip << " " << nume
            << ", culoare: " << culoare
            << ", " << (esteSterilizata ? "sterilizata" : "nesterilizata") << "." << endl;
    }

    // --- Functie statica: procentul pisicilor sterilizate (exemplu)
    static double procentSterilizate(int nrSterilizate) {
        if (nrPisici == 0) return 0;
        return (double)nrSterilizate / nrPisici * 100.0;
    }

    ~Pisica() {
        delete[] sunet;
    }
};
int Pisica::nrPisici = 0;


class Papagal {
public:
    string specie;
    string culoare;
    bool vorbeste;
    static int nrPapagali;
    const string tip;
    char* sunet;

    Papagal() : specie("Necunoscuta"), culoare("necunoscuta"), vorbeste(false), tip("Papagal") {
        nrPapagali++;
        sunet = new char[strlen("Cip!") + 1];
        strcpy_s(sunet, strlen("Cip!") + 1, "Cip!");
    }

    Papagal(string s, string c) : specie(s), culoare(c), vorbeste(false), tip("Papagal") {
        nrPapagali++;
        sunet = new char[strlen("Cip-cirip!") + 1];
        strcpy_s(sunet, strlen("Cip-cirip!") + 1, "Cip-cirip!");
    }

    Papagal(string s, string c, bool v)
        : specie(s), culoare(c), vorbeste(v), tip("Papagal") {
        nrPapagali++;
        sunet = new char[strlen("Cip-cirip!") + 1];
        strcpy_s(sunet, strlen("Cip-cirip!") + 1, "Cip-cirip!");
    }

    void canta() {
        cout << sunet << endl;
    }

    void afiseaza() {
        cout << tip << " de specie " << specie
            << ", culoare: " << culoare
            << ", " << (vorbeste ? "vorbeste" : "nu vorbeste") << "." << endl;
    }

    // --- Functie statica: procentul papagalilor care vorbesc
    static double procentVorbitori(int nrVorbitori) {
        if (nrPapagali == 0) return 0;
        return (double)nrVorbitori / nrPapagali * 100.0;
    }

    ~Papagal() {
        delete[] sunet;
    }
};
int Papagal::nrPapagali = 0;



int main() {
    Caine c1;
    Caine c2("Beagle", 4);
    Caine c3("Labrador", 3, 25.5);

    c1.afiseaza(); c1.latra();
    c2.afiseaza(); c2.latra();
    c3.afiseaza(); c3.latra();

    Pisica p1;
    Pisica p2("Miti", "neagra");
    Pisica p3("Luna", "gri", true);

    p1.afiseaza(); p1.toarce();
    p2.afiseaza(); p2.toarce();
    p3.afiseaza(); p3.toarce();

    Papagal pa1;
    Papagal pa2("Cacadu", "alb");
    Papagal pa3("Ara", "albastru", true);

    pa1.afiseaza(); pa1.canta();
    pa2.afiseaza(); pa2.canta();
    pa3.afiseaza(); pa3.canta();

    cout << "\nNumar total de caini: " << Caine::nrCaini << endl;
    cout << "Numar total de pisici: " << Pisica::nrPisici << endl;
    cout << "Numar total de papagali: " << Papagal::nrPapagali << endl;

    cout << "\nVarsta medie a cainilor (exemplu): " << Caine::calculeazaVarstaMedie(7) << " ani\n";
    cout << "Procent pisici sterilizate (exemplu): " << Pisica::procentSterilizate(1) << "%\n";
    cout << "Procent papagali vorbitori (exemplu): " << Papagal::procentVorbitori(1) << "%\n";

    return 0;
}
