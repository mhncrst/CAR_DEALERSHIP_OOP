#include "SUV.h"


   SUV :: SUV(int cod, string producator, string model, int AnFabricare, string culoare, int pret): Masina(cod, producator, model, AnFabricare, culoare, pret) {}


    void SUV :: printTip()  {
        cout << "Tip: SUV" << endl;
    }
void SUV :: CostIntretinere(int numarAni)
{
    cout << "Costul de intretinere al masinii este:" << endl;
    cout << ((((2024 - getAnFabricare()) * getPret()) * 0.01) * 1.125) * numarAni << "lei";

}
