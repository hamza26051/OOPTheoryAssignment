#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Medicine {
private:
    string name;
    string formula;
    double retailPrice;
    string manufactureDate;
    string expiryDate;

public:
    Medicine(string n, string f, double price, string date, string expiry)
        : name(n), formula(f), retailPrice(price), manufactureDate(date), expiryDate(expiry) {}

    void setName(string n) {
        name = n;
    }

    void setFormula(string f) {
        formula = f;
    }

    void setRetailPrice(double price) {
        retailPrice = price;
    }

    void setManufactureDate(string date) {
        manufactureDate = date;
    }

    void setExpiryDate(string expiry) {
        expiryDate = expiry;
    }

    string getName() {
        return name;
    }

    string getFormula() {
        return formula;
    }

    double getRetailPrice() {
        return retailPrice;
    }

    string getManufactureDate() {
        return manufactureDate;
    }

    string getExpiryDate() {
        return expiryDate;
    }

    virtual void display() {
        cout << "Name of the medicine: " << name << endl;
        cout << "Formula of the medicine: " << formula << endl;
        cout << "Retail Price of the medicine: " << retailPrice << endl;
        cout << "Manufacture Date of the medicine: " << manufactureDate << endl;
        cout << "Expiry Date of the medicine: " << expiryDate << endl;
    }

    bool operator==(const Medicine& other) const {
        return expiryDate.substr(6) == other.expiryDate.substr(6);
    }
};

class Tablet : public Medicine {
private:
    float sucroseLevel;

public:
    Tablet(float level, string n, string f, double price, string date, string expiry)
        : Medicine(n, f, price, date, expiry), sucroseLevel(level) {
        if (sucroseLevel < 0 || sucroseLevel > 1) {
            cout << "Please enter correct sucrose level!" << endl;
        }
    }

    void display() override {
        Medicine::display();
        cout << "Sucrose Level: " << sucroseLevel << endl;
    }
};

class Capsule : public Medicine {
private:
    float absorptionPercentage;

public:
    Capsule(float percent, string n, string f, double price, string date, string expiry)
        : Medicine(n, f, price, date, expiry), absorptionPercentage(percent) {
        if (absorptionPercentage < 0 || absorptionPercentage > 100) {
            cout << "Please enter correct Absorption Percentage!" << endl;
        }
    }

    void display() override {
        Medicine::display();
        cout << "Absorption Percentage: " << absorptionPercentage << endl;
    }
};

class Syrup : public Medicine {
public:
    Syrup(string n, string f, double price, string date, string expiry)
        : Medicine(n, f, price, date, expiry) {}

};

class Pharmacist {
public:
    void Search_Medicine(vector<Medicine*>& medicines) {
        string form;
        cout << "Enter the name of Formula" << endl;
        cin >> form;
        for (Medicine* med : medicines) {
            if (med->getFormula() == form) {
                med->display();
            }
        }
    }
};

class Counter {
private:
    double Revenue;

public:
    Counter() : Revenue(0.0) {}

    void Search_Medicine(vector<Medicine*>& medicines) {
        string n;
        cout << "Enter the name of Medicine" << endl;
        cin >> n;
        for (Medicine* med : medicines) {
            if (med->getName() == n) {
                med->display();
            }
        }
    }

    void UpdateRevenue(vector<Medicine*>& medicines) {
        for (Medicine* med : medicines) {
            Revenue += med->getRetailPrice();
        }
    }

    void DisplayRevenue() {
        cout << "Revenue is: " << Revenue << endl;
    }
};

int main() {
    vector<Medicine*> medicines;
    medicines.push_back(new Tablet(0.1, "Panadol", "High", 5.5, "01-03-2023", "01-03-2025"));
    medicines.push_back(new Capsule(80, "Calpol", "Medium", 8.5, "02-04-2023", "02-04-2025"));
    medicines.push_back(new Syrup("Cough Syrup", "Low", 10, "03-05-2023", "03-05-2025"));

    Pharmacist pharmacist;
    pharmacist.Search_Medicine(medicines);

    Counter counter;
    counter.Search_Medicine(medicines);
    counter.UpdateRevenue(medicines);
    counter.DisplayRevenue();
    if (*medicines[0] == *medicines[1]) {
        cout << "The expiry years of the first two medicines are the same." << endl;
    } else {
        cout << "The expiry years of the first two medicines are different." << endl;
    }

    for (Medicine* med : medicines) {
        delete med;
    }

    return 0;
}

