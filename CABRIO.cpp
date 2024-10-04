#include "CABRIO.h"


CABRIO :: CABRIO(int cod, string producator, string model, int AnFabricare, string culoare, int pret): Masina(cod, producator, model, AnFabricare, culoare, pret) {}


void CABRIO :: printTip()  {
    cout << "Tip: CABRIO" << endl;
}

void CABRIO :: CostIntretinere(int numarAni)
{
    cout << "Costul de intretinere al masinii este:" << endl;
    cout << ((((2024 - getAnFabricare()) * getPret()) * 0.01) * 1.25) * numarAni << "lei";

}