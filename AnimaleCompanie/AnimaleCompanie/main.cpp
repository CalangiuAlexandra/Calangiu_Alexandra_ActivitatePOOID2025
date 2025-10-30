#include <iostream>
#include <string>

using namespace std;

class Caine {
private:
    string rasa;
    int varsta;
    double greutate;

public:
    Caine(string r, int v, double g) : rasa(r), varsta(v), greutate(g) {}

    void latra() {
        cout << "Ham! Ham!" << endl;
    }

    void afiseaza() {
        cout << "Caine de rasa " << rasa
            << ", varsta: " << varsta
            << " ani, greutate: " << greutate << " kg." << endl;
    }
};

class Pisica {
private:
    string nume;
    string culoare;
    bool esteSterilizata;

public:
    Pisica(string n, string c, bool s) : nume(n), culoare(c), esteSterilizata(s) {}

    void toarce() {
        cout << nume << " toarce linistit." << endl;
    }

    void afiseaza() {
        cout << "Pisica " << nume
            << ", culoare: " << culoare
            << ", " << (esteSterilizata ? "sterilizata" : "nesterilizata") << "." << endl;
    }
};


class Papagal {
private:
    string specie;
    string culoare;
    bool vorbeste;

public:
    Papagal(string s, string c, bool v) : specie(s), culoare(c), vorbeste(v) {}

    void canta() {
        cout << "Cip-cirip! Cip-cirip!" << endl;
    }

    void afiseaza() {
        cout << "Papagal de specie " << specie
            << ", culoare: " << culoare
            << ", " << (vorbeste ? "vorbeste" : "nu vorbeste") << "." << endl;
    }
};

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

    return 0;
}

