#include <iostream>
#include <string>
#include <cstring>
using namespace std;


class Pisica;

class Caine {
private:
    string rasa;
    int varsta;
    double greutate;
    static int nrCaini;
    const string tip;
    char* sunet;

public:
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

    Caine(const Caine& other)
        : rasa(other.rasa), varsta(other.varsta), greutate(other.greutate), tip("Caine") {
        nrCaini++;
        sunet = new char[strlen(other.sunet) + 1];
        strcpy_s(sunet, strlen(other.sunet) + 1, other.sunet);
    }

    Caine& operator=(const Caine& other) {
        if (this != &other) {
            rasa = other.rasa;
            varsta = other.varsta;
            greutate = other.greutate;

            delete[] sunet;
            sunet = new char[strlen(other.sunet) + 1];
            strcpy_s(sunet, strlen(other.sunet) + 1, other.sunet);
        }
        return *this;
    }

    bool operator==(const Caine& other) const {
        return rasa == other.rasa &&
            varsta == other.varsta &&
            fabs(greutate - other.greutate) < 0.0001 &&
            strcmp(sunet, other.sunet) == 0;
    }

    bool operator<(const Caine& other) const {
        return varsta < other.varsta;
    }

    friend ostream& operator<<(ostream& out, const Caine& c) {
        out << "Caine (" << c.rasa << "), varsta: "
            << c.varsta << " ani, greutate: " << c.greutate
            << " kg, sunet: " << c.sunet;
        return out;
    }

    // Getteri, setteri, alte metode
    string getRasa() const { return rasa; }
    int getVarsta() const { return varsta; }
    double getGreutate() const { return greutate; }
    string getTip() const { return tip; }
    const char* getSunet() const { return sunet; }

    void setRasa(string r) { rasa = r; }
    void setVarsta(int v) { varsta = v; }
    void setGreutate(double g) { greutate = g; }

    void setSunet(const char* s) {
        delete[] sunet;
        sunet = new char[strlen(s) + 1];
        strcpy_s(sunet, strlen(s) + 1, s);
    }

    void latra() const { cout << sunet << endl; }

    void afiseaza() const {
        cout << tip << " de rasa " << rasa
            << ", varsta: " << varsta
            << " ani, greutate: " << greutate << " kg." << endl;
    }

    static double calculeazaVarstaMedie(int totalVarsta) {
        if (nrCaini == 0) return 0;
        return (double)totalVarsta / nrCaini;
    }

    static int getNrCaini() { return nrCaini; }

    ~Caine() {
        delete[] sunet;
    }

    friend void comparaCainePisica(const Caine& c, const Pisica& p);
};
int Caine::nrCaini = 0;



class Pisica {
private:
    string nume;
    string culoare;
    bool esteSterilizata;
    static int nrPisici;
    const string tip;
    char* sunet;

public:
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

    Pisica(const Pisica& other)
        : nume(other.nume), culoare(other.culoare),
        esteSterilizata(other.esteSterilizata), tip("Pisica") {
        nrPisici++;
        sunet = new char[strlen(other.sunet) + 1];
        strcpy_s(sunet, strlen(other.sunet) + 1, other.sunet);
    }

    string getNume() const { return nume; }
    string getCuloare() const { return culoare; }
    bool getEsteSterilizata() const { return esteSterilizata; }
    string getTip() const { return tip; }
    const char* getSunet() const { return sunet; }

    void setNume(string n) { nume = n; }
    void setCuloare(string c) { culoare = c; }
    void setEsteSterilizata(bool s) { esteSterilizata = s; }
    void setSunet(const char* s) {
        delete[] sunet;
        sunet = new char[strlen(s) + 1];
        strcpy_s(sunet, strlen(s) + 1, s);
    }

    void toarce() const {
        cout << nume << " toarce linistit. " << sunet << endl;
    }

    void afiseaza() const {
        cout << tip << " " << nume
            << ", culoare: " << culoare
            << ", " << (esteSterilizata ? "sterilizata" : "nesterilizata") << "." << endl;
    }

    static double procentSterilizate(int nrSterilizate) {
        if (nrPisici == 0) return 0;
        return (double)nrSterilizate / nrPisici * 100.0;
    }

    static int getNrPisici() { return nrPisici; }

    ~Pisica() {
        delete[] sunet;
    }

    friend void comparaCainePisica(const Caine& c, const Pisica& p);

    Pisica& operator=(const Pisica& other) {
        if (this != &other) {
            nume = other.nume;
            culoare = other.culoare;
            esteSterilizata = other.esteSterilizata;

            delete[] sunet;
            sunet = new char[strlen(other.sunet) + 1];
            strcpy_s(sunet, strlen(other.sunet) + 1, other.sunet);
        }
        return *this;
    }

    bool operator==(const Pisica& other) const {
        return nume == other.nume &&
            culoare == other.culoare &&
            esteSterilizata == other.esteSterilizata &&
            strcmp(sunet, other.sunet) == 0;
    }

    bool operator<(const Pisica& other) const {
        return nume < other.nume;
    }

    friend ostream& operator<<(ostream& out, const Pisica& p) {
        out << "Pisica (" << p.nume << "), culoare: "
            << p.culoare << ", "
            << (p.esteSterilizata ? "sterilizata" : "nesterilizata")
            << ", sunet: " << p.sunet;
        return out;
    }

};
int Pisica::nrPisici = 0;


class Papagal {
private:
    string specie;
    string culoare;
    bool vorbeste;
    static int nrPapagali;
    const string tip;
    char* sunet;

public:
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

    Papagal(const Papagal& other)
        : specie(other.specie), culoare(other.culoare),
        vorbeste(other.vorbeste), tip("Papagal") {
        nrPapagali++;
        sunet = new char[strlen(other.sunet) + 1];
        strcpy_s(sunet, strlen(other.sunet) + 1, other.sunet);
    }

    string getSpecie() const { return specie; }
    string getCuloare() const { return culoare; }
    bool getVorbeste() const { return vorbeste; }
    string getTip() const { return tip; }
    const char* getSunet() const { return sunet; }

    void setSpecie(string s) { specie = s; }
    void setCuloare(string c) { culoare = c; }
    void setVorbeste(bool v) { vorbeste = v; }
    void setSunet(const char* s) {
        delete[] sunet;
        sunet = new char[strlen(s) + 1];
        strcpy_s(sunet, strlen(s) + 1, s);
    }

    void canta() const { cout << sunet << endl; }

    void afiseaza() const {
        cout << tip << " de specie " << specie
            << ", culoare: " << culoare
            << ", " << (vorbeste ? "vorbeste" : "nu vorbeste") << "." << endl;
    }

    static double procentVorbitori(int nrVorbitori) {
        if (nrPapagali == 0) return 0;
        return (double)nrVorbitori / nrPapagali * 100.0;
    }

    static int getNrPapagali() { return nrPapagali; }

    ~Papagal() {
        delete[] sunet;
    }

    friend void seteazaSunetPapagal(Papagal& pa);

    Papagal& operator=(const Papagal& other) {
        if (this != &other) {
            specie = other.specie;
            culoare = other.culoare;
            vorbeste = other.vorbeste;

            delete[] sunet;
            sunet = new char[strlen(other.sunet) + 1];
            strcpy_s(sunet, strlen(other.sunet) + 1, other.sunet);
        }
        return *this;
    }

    bool operator==(const Papagal& other) const {
        return specie == other.specie &&
            culoare == other.culoare &&
            vorbeste == other.vorbeste &&
            strcmp(sunet, other.sunet) == 0;
    }

    bool operator<(const Papagal& other) const {
        return specie < other.specie;
    }

    friend ostream& operator<<(ostream& out, const Papagal& p) {
        out << "Papagal (" << p.specie << "), culoare: "
            << p.culoare << ", "
            << (p.vorbeste ? "vorbeste" : "nu vorbeste")
            << ", sunet: " << p.sunet;
        return out;
    }

};
int Papagal::nrPapagali = 0;

void comparaCainePisica(const Caine& c, const Pisica& p) {
    cout << "Caine rasa: " << c.rasa << ", varsta: " << c.varsta << endl;
    cout << "Pisica nume: " << p.nume << ", sterilizata: " << p.esteSterilizata << endl;
}


void seteazaSunetPapagal(Papagal& pa) {
    if (pa.culoare == "rosu" || pa.culoare == "galben") {
        delete[] pa.sunet;
        pa.sunet = new char[strlen("CIP-CIRIP!!!") + 1];
        strcpy_s(pa.sunet, strlen("CIP-CIRIP!!!") + 1, "CIP-CIRIP!!!");
    }
    else {
        delete[] pa.sunet;
        pa.sunet = new char[strlen("cirip...") + 1];
        strcpy_s(pa.sunet, strlen("cirip...") + 1, "cirip...");
    }
}



int main() {
    Caine c1;
    Caine c2("Beagle", 4);
    Caine c3("Labrador", 3, 25.5);
    Caine c4 = c3;

    c1 = c2;
    cout << "\nDupa operator= : c1 devine c2\n";
    cout << c1 << "\n";

    cout << "\nComparatie c2 == c3: ";
    if (c2 == c3)
        cout << "Egali\n";
    else
        cout << "Diferiti\n";


    cout << "\nComparatie varsta (c2 < c3): ";
    if (c2 < c3)
        cout << "c2 este mai tanar\n";
    else
        cout << "c2 NU este mai tanar\n";

    cout << "\nAfisare cu operator:\n";
    cout << c1 << "\n" << c2 << "\n" << c3 << "\n";

    c1.setRasa("Bulldog");
    c1.setGreutate(14.7);
    c1.afiseaza();

    c1.afiseaza(); c1.latra();
    c2.afiseaza(); c2.latra();
    c3.afiseaza(); c3.latra();
    c4.afiseaza(); c4.latra();

    Pisica p1;
    Pisica p2("Miti", "neagra");
    Pisica p3("Luna", "gri", true);
    Pisica p4 = p2;

    p1.setNume("Luna");
    p1.setCuloare("gri");
    p1.afiseaza();

    p1.afiseaza(); p1.toarce();
    p2.afiseaza(); p2.toarce();
    p3.afiseaza(); p3.toarce();
    p4.afiseaza(); p4.toarce();

    Papagal pa1;
    Papagal pa2("Cacadu", "alb");
    Papagal pa3("Ara", "albastru", true);
    Papagal pa4 = pa3;

    pa1.setSpecie("Cacadu");
    pa1.setCuloare("alb");
    pa1.afiseaza();

    pa1.afiseaza(); pa1.canta();
    pa2.afiseaza(); pa2.canta();
    pa3.afiseaza(); pa3.canta();
    pa4.afiseaza(); pa4.canta();

    cout << "Total caini: " << Caine::getNrCaini() << endl;
    cout << "Total pisici: " << Pisica::getNrPisici() << endl;
    cout << "Total papagali: " << Papagal::getNrPapagali() << endl;

    cout << "\nNumar total de caini: " << Caine::calculeazaVarstaMedie(7) << endl;
    cout << "Numar total de pisici: " << Pisica::procentSterilizate(1) << "%\n";
    cout << "Numar total de papagali: " << Papagal::procentVorbitori(1) << "%\n";

    comparaCainePisica(c3, p3);

    seteazaSunetPapagal(pa1);
    cout << "Sunet papagal nou: ";
    pa1.canta();

    Pisica p5("Mira", "alba", true);
    Pisica p6("Leo", "portocalie", false);

    cout << p5 << endl;

    if (p5 == p6) {
        cout << "Egale";
    }
    else {
        cout << "Diferite";
    }

    cout << endl;

    if (p5 < p6) {
        cout << "Mira vine inainte de Leo";
    }
    else {
        cout << "Mira vine dupa Leo";
    }

    cout << endl << endl;;

    Papagal paA("Ara", "albastru", true);
    Papagal paB("Cacadu", "alb", false);

    cout << paA << endl;

    if (paA == paB) {
        cout << "Egali\n" << endl;
    }
    else {
        cout << "Diferiti\n" << endl;
    }

    if (paA < paB) {
        cout << "Ara vine inainte de Cacadu\n" << endl;
    }
    else {
        cout << "Ara vine dupa Cacadu\n" << endl;
    }

    // Vectori Obiecte
    int n;

    cout << "\nIntroduceti numarul de caini: ";
    cin >> n;
    cin.ignore();

    Caine* vCaini = new Caine[n];

    for (int i = 0; i < n; i++) {
        string rasa;
        int varsta;
        double greutate;

        cout << "\nCaine " << i + 1 << ":\n";
        cout << "Rasa: ";
        getline(cin, rasa);

        cout << "Varsta: ";
        cin >> varsta;

        cout << "Greutate: ";
        cin >> greutate;
        cin.ignore();

        vCaini[i].setRasa(rasa);
        vCaini[i].setVarsta(varsta);
        vCaini[i].setGreutate(greutate);
    }

    cout << "\n--- AFISARE VECTOR CAINI ---\n";
    for (int i = 0; i < n; i++) {
        cout << vCaini[i] << endl;
    }


    cout << "\nIntroduceti numarul de pisici: ";
    cin >> n;
    cin.ignore();

    Pisica* vPisici = new Pisica[n];

    for (int i = 0; i < n; i++) {
        string nume, culoare;
        bool ster;

        cout << "\nPisica " << i + 1 << ":\n";
        cout << "Nume: ";
        getline(cin, nume);

        cout << "Culoare: ";
        getline(cin, culoare);

        cout << "Este sterilizata? (1=da, 0=nu): ";
        cin >> ster;
        cin.ignore();

        vPisici[i].setNume(nume);
        vPisici[i].setCuloare(culoare);
        vPisici[i].setEsteSterilizata(ster);
    }

    cout << "\n--- AFISARE VECTOR PISICI ---\n";
    for (int i = 0; i < n; i++) {
        cout << vPisici[i] << endl;
    }

    cout << "\nIntroduceti numarul de papagali: ";
    cin >> n;

    Papagal* vPapagali = new Papagal[n];

    for (int i = 0; i < n; i++) {
        string specie, culoare;
        bool vorbeste;

        cout << "\nPapagal " << i + 1 << ":\n";
        cout << "Specie: ";
        getline(cin, specie);

        cout << "Culoare: ";
        getline(cin, culoare);

        cout << "Vorbeste? (1=da, 0=nu): ";
        cin >> vorbeste;
        cin.ignore();

        vPapagali[i].setSpecie(specie);
        vPapagali[i].setCuloare(culoare);
        vPapagali[i].setVorbeste(vorbeste);
    }

    cout << "\n--- AFISARE VECTOR PAPAGALI ---\n";
    for (int i = 0; i < n; i++) {
        cout << vPapagali[i] << endl;
    }

    delete[] vCaini;
    delete[] vPisici;
    delete[] vPapagali;

    // Matrice pisici
    int linii, coloane;

    cout << "\nIntroduceti numarul de linii ale matricei de pisici: ";
    cin >> linii;
    cout << "Introduceti numarul de coloane ale matricei de pisici: ";
    cin >> coloane;

    Pisica** matricePisici = new Pisica * [linii];
    for (int i = 0; i < linii; i++) {
        matricePisici[i] = new Pisica[coloane];
    }

    cout << "\n=== CITIRE MATRICE PISICI ===\n";

    for (int i = 0; i < linii; i++) {
        for (int j = 0; j < coloane; j++) {

            string nume, culoare;
            bool ster;

            cout << "\nPisica [" << i << "][" << j << "]\n";

            cout << "Nume: ";
            getline(cin, nume);

            cout << "Culoare: ";
            getline(cin, culoare);

            cout << "Este sterilizata? (1=da, 0=nu): ";
            cin >> ster;
            cin.ignore();

            matricePisici[i][j].setNume(nume);
            matricePisici[i][j].setCuloare(culoare);
            matricePisici[i][j].setEsteSterilizata(ster);
        }
    }

    cout << "\n=== AFISARE MATRICE PISICI ===\n";

    for (int i = 0; i < linii; i++) {
        for (int j = 0; j < coloane; j++) {
            cout << matricePisici[i][j] << "   ";
        }
        cout << endl;
    }

    for (int i = 0; i < linii; i++) {
        delete[] matricePisici[i];
    }
    delete[] matricePisici;

    return 0;
}
