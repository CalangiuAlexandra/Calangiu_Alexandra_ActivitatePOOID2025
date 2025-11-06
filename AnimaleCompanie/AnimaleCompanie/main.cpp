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

    // --- Constructor 1: fara parametri
    Caine() : rasa("Necunoscuta"), varsta(0), greutate(0.0), tip("Caine") {
        nrCaini++;
        sunet = new char[strlen("Ham!") + 1];
        strcpy_s(sunet, strlen("Ham!") + 1, "Ham!");
    }

    // --- Constructor 2: 2 parametri
    Caine(string r, int v) : rasa(r), varsta(v), greutate(0.0), tip("Caine") {
        nrCaini++;
        sunet = new char[strlen("Ham!") + 1];
        strcpy_s(sunet, strlen("Ham!") + 1, "Ham!");
    }

    // --- Constructor 3: 3 parametri
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

    // --- Constructor 1: fara parametri
    Pisica() : nume("Anonima"), culoare("necunoscuta"), esteSterilizata(false), tip("Pisica") {
        nrPisici++;
        sunet = new char[strlen("Miau!") + 1];
        strcpy_s(sunet, strlen("Miau!") + 1, "Miau!");
    }

    // --- Constructor 2: 2 parametri
    Pisica(string n, string c) : nume(n), culoare(c), esteSterilizata(false), tip("Pisica") {
        nrPisici++;
        sunet = new char[strlen("Miau!") + 1];
        strcpy_s(sunet, strlen("Miau!") + 1, "Miau!");
    }

    // --- Constructor 3: 3 parametri
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

    // --- Constructor 1: fara parametri
    Papagal() : specie("Necunoscuta"), culoare("necunoscuta"), vorbeste(false), tip("Papagal") {
        nrPapagali++;
        sunet = new char[strlen("Cip!") + 1];
        strcpy_s(sunet, strlen("Cip!") + 1, "Cip!");
    }

    // --- Constructor 2: 2 parametri
    Papagal(string s, string c) : specie(s), culoare(c), vorbeste(false), tip("Papagal") {
        nrPapagali++;
        sunet = new char[strlen("Cip-cirip!") + 1];
        strcpy_s(sunet, strlen("Cip-cirip!") + 1, "Cip-cirip!");
    }

    // --- Constructor 3: 3 parametri
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

    ~Papagal() {
        delete[] sunet;
    }
};
int Papagal::nrPapagali = 0;



int main() {
    Caine c1;                          // Constructor fără parametri
    Caine c2("Beagle", 4);             // Constructor cu 2 parametri
    Caine c3("Labrador", 3, 25.5);     // Constructor cu 3 parametri

    c1.afiseaza(); c1.latra();
    c2.afiseaza(); c2.latra();
    c3.afiseaza(); c3.latra();

    Pisica p1;                         // Fără parametri
    Pisica p2("Miti", "neagra");       // 2 parametri
    Pisica p3("Luna", "gri", true);    // 3 parametri

    p1.afiseaza(); p1.toarce();
    p2.afiseaza(); p2.toarce();
    p3.afiseaza(); p3.toarce();

    Papagal pa1;                       // Fără parametri
    Papagal pa2("Cacadu", "alb");      // 2 parametri
    Papagal pa3("Ara", "albastru", true); // 3 parametri

    pa1.afiseaza(); pa1.canta();
    pa2.afiseaza(); pa2.canta();
    pa3.afiseaza(); pa3.canta();

    cout << "\nNumar total de caini: " << Caine::nrCaini << endl;
    cout << "Numar total de pisici: " << Pisica::nrPisici << endl;
    cout << "Numar total de papagali: " << Papagal::nrPapagali << endl;

    return 0;
}
