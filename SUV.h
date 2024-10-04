#ifndef SUV_H
#define SUV_H
#include <string>
#include <iostream>
#include "Masina.h"

using namespace std;

class SUV : public Masina    {
public:
    SUV(int cod, string producator, string model, int AnFabricare, string culoare, int pret);



    virtual void printTip();

    virtual void CostIntretinere(int numarAni);
};
#endif