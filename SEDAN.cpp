#include "SEDAN.h"


SEDAN :: SEDAN(int cod, string producator, string model, int AnFabricare, string culoare, int pret): Masina(cod, producator, model, AnFabricare, culoare, pret) {}


void SEDAN :: printTip()  {
    cout << "Tip: SEDAN" << endl;
}
void SEDAN :: CostIntretinere(int numarAni)
{
    cout << "Costul de intretinere al masinii este:/n" << endl;
    cout << (((2024 - getAnFabricare()) * getPret()) * 0.01) * numarAni << "lei";

}