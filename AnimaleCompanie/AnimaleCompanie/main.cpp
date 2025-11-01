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
    Caine rex("Labrador", 3, 25.5);
    Pisica luna("Luna", "gri", true);
    Papagal coco("Ara", "albastru", true);

    rex.afiseaza();
    rex.latra();

    luna.afiseaza();
    luna.toarce();

    coco.afiseaza();
    coco.canta();

    cout << "\nNumar total de caini: " << Caine::nrCaini << endl;
    cout << "Numar total de pisici: " << Pisica::nrPisici << endl;
    cout << "Numar total de papagali: " << Papagal::nrPapagali << endl;

    return 0;
}
