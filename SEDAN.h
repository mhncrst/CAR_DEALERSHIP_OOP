#ifndef SEDAN_H
#define SEDAN_H
#include <string>
#include <iostream>
#include "Masina.h"

using namespace std;

class SEDAN : public Masina    {
public:
    SEDAN(int cod, string producator, string model, int AnFabricare, string culoare, int pret);


    virtual void printTip();

    virtual void CostIntretinere(int numarAni);
};
#endif