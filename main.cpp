#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
using namespace std;
#include "Masina.h"
#include "SUV.h"
#include "SEDAN.h"
#include "CABRIO.h"
class MasinaFactory {
public:
    virtual unique_ptr<Masina> createCar(int cod, string producator, string model, int AnFabricare, string culoare, int pret) const = 0;
    virtual ~MasinaFactory() = default;
};

class SUVFactory : public MasinaFactory {
public:
    unique_ptr<Masina> createCar(int cod, string producator, string model, int AnFabricare, string culoare, int pret) const override {
        return make_unique<SUV>(cod, producator, model, AnFabricare, culoare, pret);
    }
};

class SEDANFactory : public MasinaFactory {
public:
    unique_ptr<Masina> createCar(int cod, string producator, string model, int AnFabricare, string culoare, int pret) const override {
        return make_unique<SEDAN>(cod, producator, model, AnFabricare, culoare, pret);
    }
};

class CABRIOFactory : public MasinaFactory {
public:
    unique_ptr<Masina> createCar(int cod, string producator, string model, int AnFabricare, string culoare, int pret) const override {
        return make_unique<CABRIO>(cod, producator, model, AnFabricare, culoare, pret);
    }
};
class DEALERSHIP {
private:
    vector<SUV> MasiniSUV;
    vector<SEDAN> MasiniSEDAN;
    vector<CABRIO> MasiniCABRIO;

    // Singura instanță a clasei DEALERSHIP
    static DEALERSHIP* instance;

    // Constructor privat pentru a preveni instanțierea
    DEALERSHIP() {}

public:
    DEALERSHIP(DEALERSHIP &other) = delete;

    void operator=(const DEALERSHIP &) = delete;

    static DEALERSHIP* getInstance() {
        if (instance == nullptr) {
            instance = new DEALERSHIP();
        }
        return instance;
    }

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
    const vector<SUV>& getMasiniSUV() const {
        return MasiniSUV;
    }

    const vector<SEDAN>& getMasiniSEDAN() const {
        return MasiniSEDAN;
    }

    const vector<CABRIO>& getMasiniCABRIO() const {
        return MasiniCABRIO;
    }

    void alegere_caroserie() {
        cout << "In primul rand, ce tip de masina credeti ca vi s-ar potrivi?:" << endl;
        cout << "1. SUV" << endl << "2. SEDAN" << endl << "3. CABRIO" << endl;
        int caroserie;
        cin >> caroserie;
        if (caroserie == 1) {
            alegere_SUV();
        }
        if(caroserie == 2) {
            alegere_SEDAN();
        }
        if(caroserie == 3) {
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
            cout << "1. Da" << endl << "2. Nu" << endl;
            int raspuns4;
            cin >> raspuns4;
            if(raspuns4 == 1) {
                achizitionare_masina();
            } else if(raspuns4 == 2) {
                negociere_masina();
            }
        } else {
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
            cout << "1. Da" << endl << "2. Nu" << endl;
            int raspuns4;
            cin >> raspuns4;
            if(raspuns4 == 1) {
                achizitionare_masina();
            } else if(raspuns4 == 2) {
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
            cout << "1. Da" << endl << "2. Nu" << endl;
            int raspuns4;
            cin >> raspuns4;
            if(raspuns4 == 1) {
                achizitionare_masina();
            } else if(raspuns4 == 2) {
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

        if (!gasit) {
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

        if (!gasit) {
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

        if (!gasit) {
            cout << "Nu exista o masina cu codul introdus." << endl;
            cout << "Doriti sa mai introduceti codul inca o data?" << endl;
            cout << "1. Da" << endl << "2. Nu" << endl;
            int raspuns3;
            cin >> raspuns3;
            if(raspuns3 == 1){
                achizitionare_masina();
            } else {
                cout << "Multumim pentru vizita!" << endl;
            }
        }
    }
    void adaugaMasina(unique_ptr<Masina> masina) {
        if (dynamic_cast<SUV*>(masina.get())) {
            MasiniSUV.push_back(*dynamic_cast<SUV*>(masina.get()));
        } else if (dynamic_cast<SEDAN*>(masina.get())) {
            MasiniSEDAN.push_back(*dynamic_cast<SEDAN*>(masina.get()));
        } else if (dynamic_cast<CABRIO*>(masina.get())) {
            MasiniCABRIO.push_back(*dynamic_cast<CABRIO*>(masina.get()));
        }
        cout<<"Doriti sa o si cumparati acum? \n1.DA\n2.NU\n";
        int r10;
        cin>>r10;
        if(r10 == 1) {
            achizitionare_masina();
        }
        else
        {
            cout << "Va multumim pentru vizita";
        }
    }


    void negociere_masina() const {
        cout << "Care este motivul pentru care nu doriti sa faceti o achizitie?" << endl;
        cout << "1. Pretul este prea ridicat." << endl << "2. Imi trebuie putin timp de gandire." << endl
             << "3. Nu aveti ceea ce caut." << endl;
        int raspuns5;
        cin >> raspuns5;
        if (raspuns5 == 1) {
            cout << "In regula, in acest caz putem:" << endl << "1. Negocia pentru o reducere de 3%" << endl
                 << "2. Sa va oferim un plan de leasing" << endl << "3. Nicio varianta de mai sus nu este potrivita" << endl;
            int raspuns6;
            cin >> raspuns6;
            if (raspuns6 == 1 || raspuns6 == 2) {
                cout << "Perfect, haideti sa finalizam tranzactia!" << endl;
            } else {
                cout << "Ne pare rau, multumim pentru vizita!" << endl;
            }
        } else if (raspuns5 == 2) {
            cout << "In regula, multumim pentru vizita!" << endl;
        } else if (raspuns5 == 3) {
            cout << "Ne pare rau, multumim pentru vizita!" << endl;
        }
    }
    unique_ptr<Masina> citesteDetaliiMasina(const MasinaFactory& factory) {
        int cod;
        string producator, model, culoare;
        int AnFabricare, pret;

        cout << "Introduceti codul masinii: ";
        cin >> cod;
        cout << "Introduceti producatorul: ";
        cin >> producator;
        cout << "Introduceti modelul: ";
        cin >> model;
        cout << "Introduceti anul fabricatiei: ";
        cin >> AnFabricare;
        cout << "Introduceti culoarea: ";
        cin >> culoare;
        cout << "Introduceti pretul: ";
        cin >> pret;

        return factory.createCar(cod, producator, model, AnFabricare, culoare, pret);
    }

    void creeazaMasina() {
        cout << "Selectati tipul de masina pe care doriti sa o creati:" << endl;
        cout << "1. SUV" << endl << "2. SEDAN" << endl << "3. CABRIO" << endl;
        int tip;
        cin >> tip;

        unique_ptr<MasinaFactory> factory;
        switch (tip) {
            case 1:
                factory = make_unique<SUVFactory>();
                break;
            case 2:
                factory = make_unique<SEDANFactory>();
                break;
            case 3:
                factory = make_unique<CABRIOFactory>();
                break;
            default:
                cout << "Optiune invalida" << endl;
                return;
        }

        unique_ptr<Masina> masina = citesteDetaliiMasina(*factory);
        adaugaMasina(move(masina));
        cout << "Masina a fost adaugata cu succes!" << endl;
    }

    ~DEALERSHIP() = default;
};
template <class T>
class StockGestionare {
private:
    vector<T> stock;

public:

    void adauga_la_Stoc(const T& item) {
        stock.push_back(item);
    }

    void displayStoc() const {
        for (const auto& item : stock) {
            item.printAll();
            cout << endl;
        }
    }
};



DEALERSHIP* DEALERSHIP::instance = nullptr;




int main() {
    // Obținerea instanței DEALERSHIP și folosirea acesteia
    DEALERSHIP* dealership = DEALERSHIP::getInstance();

    unique_ptr<SUV> suv1 = make_unique<SUV>(001, "Mercedes", "GLE" , 2022, "NEGRU", 95000);
    unique_ptr<SUV> suv2 = make_unique<SUV>(002, "BMW", "X5", 2021, "ALBASTRU", 65000);
    unique_ptr<SUV> suv3 = make_unique<SUV>(003, "Nissan", "Qashqai", 2022, "ARGINTIU", 37500);
    unique_ptr<SUV> suv4 = make_unique<SUV>(004, "Hyundai", "Tucson", 2021, "GRI", 25000);
    unique_ptr<SEDAN> sedan1 = make_unique<SEDAN>(101, "Mercedes", "Clasa E", 2023, "NEGRU", 80000);
    unique_ptr<SEDAN> sedan2 = make_unique<SEDAN>(102, "BMW", "Seria 4", 2021, "GRI", 60000);
    unique_ptr<SEDAN> sedan3 = make_unique<SEDAN>(103, "Mercedes", "Clasa C", 2022, "ALB", 49000);
    unique_ptr<SEDAN> sedan4 = make_unique<SEDAN>(104, "Lexus", "IS", 2018, "ARGINTIU", 25000);
    unique_ptr<CABRIO> cabrio1 = make_unique<CABRIO>(201, "Audi", "A5 Cabriolet", 2022, "VERDE", 95000);
    unique_ptr<CABRIO> cabrio2 = make_unique<CABRIO>(202, "BMW", "Seria 4 Cabriolet", 2022, "NEGRU", 80000);
    unique_ptr<CABRIO> cabrio3 = make_unique<CABRIO>(203, "Mercedes", "Clasa C Cabriolet", 2020, "ALB", 45000);
    unique_ptr<CABRIO> cabrio4 = make_unique<CABRIO>(204, "Lexus", "LC Convertible", 2017, "ARGINTIU", 29000);

    dealership->adaugaSUV(*suv1);
    dealership->adaugaSUV(*suv2);
    dealership->adaugaSUV(*suv3);
    dealership->adaugaSUV(*suv4);
    dealership->adaugaSEDAN(*sedan1);
    dealership->adaugaSEDAN(*sedan2);
    dealership->adaugaSEDAN(*sedan3);
    dealership->adaugaSEDAN(*sedan4);
    dealership->adaugaCABRIO(*cabrio1);
    dealership->adaugaCABRIO(*cabrio2);
    dealership->adaugaCABRIO(*cabrio3);
    dealership->adaugaCABRIO(*cabrio4);

    StockGestionare<Masina> stockManager;


    const vector<SUV>& SUVs = DEALERSHIP::getInstance()->getMasiniSUV();
    for (const SUV& suv : SUVs) {
        stockManager.adauga_la_Stoc(suv);
    }

    const vector<SEDAN>& SEDANs = DEALERSHIP::getInstance()->getMasiniSEDAN();
    for (const SEDAN& sedan : SEDANs) {
        stockManager.adauga_la_Stoc(sedan);
    }

    const vector<CABRIO>& CABRIOs = DEALERSHIP::getInstance()->getMasiniCABRIO();
    for (const CABRIO& cabrio : CABRIOs) {
        stockManager.adauga_la_Stoc(cabrio);
    }

    unique_ptr<MasinaFactory> suvFactory = make_unique<SUVFactory>();
    unique_ptr<MasinaFactory> sedanFactory = make_unique<SEDANFactory>();
    unique_ptr<MasinaFactory> cabrioFactory = make_unique<CABRIOFactory>();

    cout << "Buna ziua, cu ce va pot ajuta?:" << endl;
    cout << "1. As vrea sa-mi dati o lista cu toate masinile disponibile." << endl;
    cout << "2. As avea nevoie de consultanta dumneavoastra." << endl;
    cout << "3. As vrea sa imi aduceti o masina." << endl;
    int raspuns;
    cin >> raspuns;
    if (raspuns == 1) {
        cout << "Aceasta este lista completa a masinilor disponibile:" << endl;
        stockManager.displayStoc();
        cout << "Va mai putem ajuta cu ceva?" << endl;
        cout << "1. Da, as dori sa achizitionez o masina" << endl;
        cout << "2. Nu, multumesc" << endl;
        int raspuns2;
        cin >> raspuns2;
        if (raspuns2 == 1) {
            dealership->achizitionare_masina();
        } else {
            cout << "In regula, multumim pentru vizita!" << endl;
        }
    } else if (raspuns == 2) {
        dealership->alegere_caroserie();
    }
    else if (raspuns == 3) {
        dealership->creeazaMasina();
    }
    else {
        cout << "Optiune invalida. Multumim pentru vizita!" << endl;
    }

    return 0;
}

