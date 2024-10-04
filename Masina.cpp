#include "Masina.h"

    Masina :: Masina(int cod, string producator, string model, int AnFabricare, string culoare, int pret):
            cod(cod), producator(producator), model(model), AnFabricare(AnFabricare), culoare(culoare), pret(pret) {}


Masina& Masina::operator=(const Masina& other) {
    if (this != &other) {
        cod = other.cod;
        producator = other.producator;
        model = other.model;
        AnFabricare = other.AnFabricare;
        culoare = other.culoare;
        pret = other.pret;
    }
    return *this;
}

    void Masina :: setCod(int cod)
    {
        this->cod = cod;
    }
    void Masina :: printCod()
    {
        cout << cod << endl;
    }
    int Masina :: getCod() const
    {
        return cod;
    }

    void Masina :: setProducator(string producator)
    {
        this->producator = producator;
    }
    void Masina :: printProducator()
    {
        cout << producator << endl;
    }
    string Masina :: getProducator() const
    {
        return producator;
    }

    void Masina :: setModel(string model)
    {
        this->model = model;
    }
    void Masina :: printModel()
    {
        cout << model << endl;
    }
    string Masina :: getModel() const
    {
        return model;
    }

    void Masina :: setAnFabricare(int AnFabricare)
    {
        this->AnFabricare = AnFabricare;
    }
    void Masina :: printAnFabricare()
    {
        cout << AnFabricare << endl;
    }
    int Masina :: getAnFabricare() const
    {
        return AnFabricare;
    }


    void Masina :: setCuloare(string culoare)
    {
        this->culoare = culoare;
    }
    void Masina :: printCuloare()
    {
        cout << culoare << endl;
    }
    string Masina :: getCuloare() const
    {
        return culoare;
    }

    void Masina :: setPret(int pret)
    {
        this->pret = pret;
    }
    void Masina :: printPret()
    {
        cout << pret << endl;
    }
    int Masina :: getPret() const
    {
        return pret;
    }
    void Masina :: printAll() const
    {
        cout << cod << endl << producator << endl << model << endl << AnFabricare << endl << culoare << endl << pret << endl;
    }
    void Masina :: printTip(){
        cout << "Tip : Masina";
    }
    void Masina :: CostIntretinere(int numarAni)
    {
        cout << "Costul de intretinere al masinii este:" << endl;
        cout << (((2024 - getAnFabricare()) * getPret()) * 0.01) * numarAni << "lei";
    }
