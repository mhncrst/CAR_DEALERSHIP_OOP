#ifndef CABRIOH
#define CABRIO_H
#include <string>
#include <iostream>
#include "Masina.h"

using namespace std;

class CABRIO : public Masina    {
public:
    CABRIO(int cod, string producator, string model, int AnFabricare, string culoare, int pret);


    virtual void printTip();

    virtual void CostIntretinere(int numarAni);
};
#endif