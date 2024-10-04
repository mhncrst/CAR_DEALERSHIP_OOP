#ifndef MASINA_H
#define MASINA_H
#include <string>
#include <iostream>
using namespace std;

class Masina {
protected:
    int cod;
    string producator;
    string model;
    int AnFabricare;
    string culoare;
    int pret;
    static int totalMasini;
public:
    static int numarTotalMasini();
    Masina(int cod, string producator, string model, int AnFabricare, string culoare, int pret);
    Masina();
    Masina& operator=(const Masina& other);
    void setCod(int cod);
    void printCod();
    int getCod() const;
    void setProducator(string producator);
    void printProducator();
    string getProducator() const;
    void setModel(string model);
    void printModel();
    string getModel() const;
    void setAnFabricare(int AnFabricare);
    void printAnFabricare();
    int getAnFabricare() const;
    void setCuloare(string culoare);
    void printCuloare();
    string getCuloare() const;
    void setPret(int pret);
    void printPret();
    int getPret() const;
    void printAll() const;
    virtual void printTip();
    //virtual ~Masina();
    virtual void CostIntretinere(int numarAni);
};
#endif