/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Masina {
protected:
    int cod;
    string producator;
    string model;
    int AnFabricare;
    string culoare;
    int pret;
public:
    Masina(int cod, string producator, string model, int AnFabricare, string culoare, int pret):
            cod(cod), producator(producator), model(model), AnFabricare(AnFabricare), culoare(culoare), pret(pret) {}

    Masina() = default;
    void setCod(int cod)
    {
        this->cod = cod;
    }
    void printCod()
    {
        cout << cod << endl;
    }
    int getCod() const
    {
        return cod;
    }

    void setProducator(string producator)
    {
        this->producator = producator;
    }
    void printProducator()
    {
        cout << producator << endl;
    }
    string getProducator() const
    {
        return producator;
    }

    void setModel(string model)
    {
        this->model = model;
    }
    void printModel()
    {
        cout << model << endl;
    }
    string getModel() const
    {
        return model;
    }

    void setAnFabricare(int AnFabricare)
    {
        this->AnFabricare = AnFabricare;
    }
    void printAnFabricare()
    {
        cout << AnFabricare << endl;
    }
    int getAnFabricare() const
    {
        return AnFabricare;
    }


    void setCuloare(string culoare)
    {
        this->culoare = culoare;
    }
    void printCuloare()
    {
        cout << culoare << endl;
    }
    string getCuloare() const
    {
        return culoare;
    }

    void setPret(int pret)
    {
        this->pret = pret;
    }
    void printPret()
    {
        cout << pret << endl;
    }
    int getPret() const
    {
        return pret;
    }
    void printAll() const
    {
        cout << cod << endl << producator << endl << model << endl << AnFabricare << endl << culoare << endl << pret << endl;
    }
    void printTip(){
        cout << "Tip : Masina";
    }
    virtual ~Masina() = default;
};

class SUV : public Masina    {
public:
    SUV(int cod, string producator, string model, int AnFabricare, string culoare, int pret):
            Masina(cod, producator, model, AnFabricare, culoare, pret) {}

    void printTip()  {
        cout << "Tip: SUV" << endl;
    }
};

class SEDAN : public Masina {
public:
    SEDAN(int cod, string producator, string model, int AnFabricare, string culoare, int pret):
            Masina(cod, producator, model, AnFabricare, culoare, pret) {}

    void printTip()  {
        cout << "Tip: SEDAN" << endl;
    }
};

class CABRIO : public Masina {
public:
    CABRIO(int cod, string producator, string model, int AnFabricare, string culoare, int pret):
            Masina(cod, producator, model, AnFabricare, culoare, pret) {}

    void printTip()  {
        cout << "Tip: CABRIO" << endl;
    }
};
class DEALERSHIP {
private:
    vector<SUV> MasiniSUV;
    vector<SEDAN> MasiniSEDAN;
    vector<CABRIO> MasiniCABRIO;
public:
    void adaugaSUV(const SUV &suv) {
        MasiniSUV.push_back(suv);
    }

    void adaugaSEDAN(const SEDAN &sedan) {
        MasiniSEDAN.push_back(sedan);

    }

    void adaugaCABRIO(const CABRIO &cabrio) {
        MasiniCABRIO.push_back(cabrio);
    }

    void printmasini() const {
        cout << "SUV-uri:" << endl;
        for (const auto &suv: MasiniSUV) {
            suv.printAll();
            cout << endl;
        }

        cout << "SEDAN-uri:" << endl;
        for (const auto &sedan: MasiniSEDAN) {
            sedan.printAll();
            cout << endl;
        }
        cout << "CABRIO-uri:" << endl;
        for (const auto &cabrio: MasiniCABRIO) {
            cabrio.printAll();
            cout << endl;
        }
    }

    void scoate_ultimulSUV() {
        if (!MasiniSUV.empty()) {
            MasiniSUV.pop_back();
        }
    }

    void scoate_ultimulSEDAN() {
        if (!MasiniSEDAN.empty()) {
            MasiniSEDAN.pop_back();
        }
    }

    void scoate_ultimulCABRIO() {
        if (!MasiniCABRIO.empty()) {
            MasiniCABRIO.pop_back();
        }
    }

    void alegere_caroserie() {
        cout << "In primul rand, ce tip de masina credeti ca vi s-ar potrivi?:" << endl;
        cout << "1.SUV" << endl << "2.SEDAN" << endl << "3.CABRIO" << endl;
        int caroserie;
        cin >> caroserie;
        if (caroserie == 1) {
            alegere_SUV();
        }
        if(caroserie == 2)
        {
            alegere_SEDAN();
        }
        if(caroserie == 3)
        {
            alegere_CABRIO();
        }
    }

    void alegere_SUV() const {
        cout << "Care este bugetul dumneavoastra?:" << endl;
        cout << "1. 80-100k" << endl << "2. 50-79k" << endl << "3. 30-49k" << endl << "4. 0-29k" << endl;
        int bugetSUV;
        cin >> bugetSUV;
        vector<SUV> SUV_disponibile;

        if (bugetSUV == 1) {
            for (const auto &suv: MasiniSUV) {
                if (suv.getPret() >= 80000 && suv.getPret() <= 100000) {
                    SUV_disponibile.push_back(suv);
                }
            }
        } else if (bugetSUV == 2) {
            for (const auto &suv: MasiniSUV) {
                if (suv.getPret() >= 50000 && suv.getPret() <= 79000) {
                    SUV_disponibile.push_back(suv);
                }
            }
        } else if (bugetSUV == 3) {
            for (const auto &suv: MasiniSUV) {
                if (suv.getPret() >= 30000 && suv.getPret() <= 49000) {
                    SUV_disponibile.push_back(suv);
                }
            }
        } else if (bugetSUV == 4) {
            for (const auto &suv: MasiniSUV) {
                if (suv.getPret() >= 0 && suv.getPret() <= 29000) {
                    SUV_disponibile.push_back(suv);
                }
            }
        }

        if (!SUV_disponibile.empty()) {
            cout << "SUV-urile disponibile in acest buget sunt:" << endl;
            for (const auto &suv: SUV_disponibile) {
                suv.printAll();
                cout << endl;
            }
            cout << "Doriti sa achizitionati ceva?" << endl;
            cout << "1.Da" << endl << "2.Nu" << endl;
            int raspuns4;
            cin >> raspuns4;
            if(raspuns4 == 1)
            {
                achizitionare_masina();
            }
            if(raspuns4 == 2)
            {
                negociere_masina();
            }
        }
        else {
            cout << "Nu exista SUV-uri disponibile in acest buget." << endl;
        }
    }


    void alegere_SEDAN() const {
        cout << "Care este bugetul dumneavoastra?:" << endl;
        cout << "1. 80-100k" << endl << "2. 50-79k" << endl << "3. 30-49k" << endl << "4. 0-29k" << endl;
        int bugetSEDAN;
        cin >> bugetSEDAN;
        vector<SEDAN> SEDAN_disponibile;

        if (bugetSEDAN == 1) {
            for (const auto &sedan: MasiniSEDAN) {
                if (sedan.getPret() >= 80000 && sedan.getPret() <= 100000) {
                    SEDAN_disponibile.push_back(sedan);
                }
            }
        } else if (bugetSEDAN == 2) {
            for (const auto &sedan: MasiniSEDAN) {
                if (sedan.getPret() >= 50000 && sedan.getPret() <= 79000) {
                    SEDAN_disponibile.push_back(sedan);
                }
            }
        } else if (bugetSEDAN == 3) {
            for (const auto &sedan: MasiniSEDAN) {
                if (sedan.getPret() >= 30000 && sedan.getPret() <= 49000) {
                    SEDAN_disponibile.push_back(sedan);
                }
            }
        } else if (bugetSEDAN == 4) {
            for (const auto &sedan: MasiniSEDAN) {
                if (sedan.getPret() >= 0 && sedan.getPret() <= 29000) {
                    SEDAN_disponibile.push_back(sedan);
                }
            }
        }
        if (!SEDAN_disponibile.empty()) {
            cout << "Sedan-urile disponibile in acest buget sunt:" << endl;
            for (const auto &sedan: SEDAN_disponibile) {
                sedan.printAll();
                cout << endl;

            }
            cout << "Doriti sa achizitionati ceva?" << endl;
            cout << "1.Da" << endl << "2.Nu" << endl;
            int raspuns4;
            cin >> raspuns4;
            if(raspuns4 == 1)
            {
                achizitionare_masina();
            }
            if(raspuns4 == 2)
            {
                negociere_masina();
            }
        } else {
            cout << "Nu exista SEDAN-uri disponibile in acest buget." << endl;
        }
    }



    void alegere_CABRIO() const {
        cout << "Care este bugetul dumneavoastra?:" << endl;
        cout << "1. 80-100k" << endl << "2. 50-79k" << endl << "3. 30-49k" << endl << "4. 0-29k" << endl;
        int bugetCABRIO;
        cin >> bugetCABRIO;
        vector<CABRIO> CABRIO_disponibile;

        if (bugetCABRIO == 1) {
            for (const auto &cabrio: MasiniCABRIO) {
                if (cabrio.getPret() >= 80000 && cabrio.getPret() <= 100000) {
                    CABRIO_disponibile.push_back(cabrio);
                }
            }
        } else if (bugetCABRIO == 2) {
            for (const auto &cabrio: MasiniCABRIO) {
                if (cabrio.getPret() >= 50000 && cabrio.getPret() <= 79000) {
                    CABRIO_disponibile.push_back(cabrio);
                }
            }
        } else if (bugetCABRIO == 3) {
            for (const auto &cabrio: MasiniCABRIO) {
                if (cabrio.getPret() >= 30000 && cabrio.getPret() <= 49000) {
                    CABRIO_disponibile.push_back(cabrio);
                }
            }
        } else if (bugetCABRIO == 4) {
            for (const auto &cabrio: MasiniCABRIO) {
                if (cabrio.getPret() >= 0 && cabrio.getPret() <= 29500) {
                    CABRIO_disponibile.push_back(cabrio);
                }
            }
        }

        if (!CABRIO_disponibile.empty()) {
            cout << "CABRIO-urile disponibile in acest buget sunt:" << endl;
            for (const auto &cabrio: CABRIO_disponibile) {
                cabrio.printAll();
                cout << endl;
            }
            cout << "Doriti sa achizitionati ceva?" << endl;
            cout << "1.Da" << endl << "2.Nu" << endl;
            int raspuns4;
            cin >> raspuns4;
            if(raspuns4 == 1)
            {
                achizitionare_masina();
            }
            if(raspuns4 == 2)
            {
                negociere_masina();
            }
        } else {
            cout << "Nu exista CABRIO-uri disponibile in acest buget." << endl;
        }
    }



    void achizitionare_masina() const  {
        bool gasit = false;
        int cod_masina;
        cout << "Vom avea nevoie de codul masinii dorite" << endl;
        cin >> cod_masina;
        for (int i = 0; i < MasiniSUV.size(); ++i) {
            if (MasiniSUV[i].getCod() == cod_masina) {
                cout << "Ati achizitionat urmatoarea masina:" << endl;
                MasiniSUV[i].printAll();
                cout << endl;
                gasit = true;
                break;
            }
        }

        if (gasit == false) {
            for (int i = 0; i < MasiniSEDAN.size(); ++i) {
                if (MasiniSEDAN[i].getCod() == cod_masina) {
                    cout << "Ati achizitionat urmatoarea masina:" << endl;
                    MasiniSEDAN[i].printAll();
                    cout << endl;
                    gasit = true;
                    break;
                }
            }
        }

        if (gasit == false) {
            for (int i = 0; i < MasiniCABRIO.size(); ++i) {
                if (MasiniCABRIO[i].getCod() == cod_masina) {
                    cout << "Ati achizitionat urmatoarea masina:" << endl;
                    MasiniCABRIO[i].printAll();
                    cout << endl;
                    gasit = true;
                    break;
                }
            }
        }

        if (gasit == false) {
            cout << "Nu exista o masina cu codul introdus." << endl;
            cout << "Doriti sa mai introduceti codul inca o data>" << endl;
            cout << "1.Da" << endl << "2.Nu";
            int raspuns3;
            cin >> raspuns3;
            if(raspuns3 == 1){
                achizitionare_masina();
            }
            if(raspuns3 == 2){
                cout << "Multumim pentru vizita!" << endl;
            }
        }
    }

    void negociere_masina() const{
        cout << "Care este motivul pentru care nu doriti sa faceti o achizitie?" << endl;
        cout << "1.Pretul este prea ridicat." << endl << "2.Imi trebuie putin timp de gandire." << endl
             << "2.Nu aveti ceea ce caut." << endl;
        int raspuns5;
        cin >> raspuns5;
        if (raspuns5 == 1) {
            cout << "In regula, in acest caz putem:" << endl << "1.Negocia pentru o reducere de 3%" << endl
                 << "2.Sa va oferim un plan de leasing" << endl << "3.Nicio varianta de mai sus nu este portrivita" << endl;
            int raspuns6;
            cin >> raspuns6;
            if (raspuns6 == 1 || raspuns6 == 2) {
                cout << "Perfect, haideti sa finalizam tranzactia!" << endl;
            } else {
                cout << "Ne pare rau, multumim pentru vizita!" << endl;
            }
            if (raspuns5 == 2) {
                cout << "In regula, multumim pentru vizita!" << endl;
            }
            if (raspuns5 == 3) {
                cout << "Ne pare rau, multumim pentru vizita!" << endl;
            }
        }
    }

    ~DEALERSHIP() = default;


};



int main() {
    DEALERSHIP dealership;

    SUV suv1(001, "Mercedes", "GLE" , 2022, "NEGRU", 95000);
    SUV suv2(002, "BMW", "x5" , 2021, "ALBASTRU", 65000);
    SUV suv3(003, "Nissan", "Qashqai", 2022, "ARGINTIU", 37500);
    SUV suv4(004, "Hyundai", "Tucson", 2021, "GRI", 25000);
    SEDAN sedan1(101, "Mercedes", "Clasa E", 2023, "NEGRU", 80000);
    SEDAN sedan2(102, "BMW", "Seria 4", 2021, "GRI", 60000);
    SEDAN sedan3(103, "Mercedes", "Clasa C", 2022, "ALB", 49000);
    SEDAN sedan4(104, "Lexus", "IS", 2018, "ARGINTIU", 25000);
    CABRIO cabrio1(201, "Audi", "A5 Cabriolet", 2022, "VERDE", 95000);
    CABRIO cabrio2(202, "BMW", "Seria 4 Cabriolet", 2022, "NEGRU", 80000);
    CABRIO cabrio3(203, "Mercedes", "Clasa C Cabriolet", 2020, "ALB", 45000);
    CABRIO cabrio4(204, "Lexus", "LC Convertible", 2017, "ARGINTIU", 29000);

    dealership.adaugaSUV(suv1);
    dealership.adaugaSUV(suv2);
    dealership.adaugaSUV(suv3);
    dealership.adaugaSUV(suv4);
    dealership.adaugaSEDAN(sedan1);
    dealership.adaugaSEDAN(sedan2);
    dealership.adaugaSEDAN(sedan3);
    dealership.adaugaSEDAN(sedan4);
    dealership.adaugaCABRIO(cabrio1);
    dealership.adaugaCABRIO(cabrio2);
    dealership.adaugaCABRIO(cabrio3);
    dealership.adaugaCABRIO(cabrio4);
    cout<< "Buna ziua, cu ce va pot ajuta?:" << endl;
    cout << "1. As vrea sa-mi dati o lista cu toate masinile disponibile." << endl;
    cout << "2. As avea nevoie de consultanta dumneavoastra." << endl;
    int raspuns;
    cin >> raspuns;
    if (raspuns == 1)
    {
        cout<< "Aceasta este lista completa a masinilor disponibile:";
        dealership.printmasini();
        cout << "Va mai putem ajuta cu ceva?" << endl;
        int raspuns2;
        cout <<"1.Da, as dori sa achizitionez o masina" << endl << "2.Nu, multumesc" << endl;
        cin >> raspuns2;
        if(raspuns2 == 1)
        {
            dealership.achizitionare_masina();
        }
        else{
            cout << "In regula" << endl;
        }
    }
    if(raspuns == 2)
    {
        dealership.alegere_caroserie();
    }


    return 0;
}
*/