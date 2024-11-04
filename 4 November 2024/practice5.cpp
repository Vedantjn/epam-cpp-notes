#include <iostream>
using namespace std;

class Hospital {
private:
    static int totalPatients;
    int inPatients;
    int outPatients;
    int criticalCarePatients;

public:
    Hospital() {
        inPatients = 0;
        outPatients = 0;
        criticalCarePatients = 0;
    }

    void addInPatient() {
        inPatients++;
        totalPatients++;
    }

    void addOutPatient() {
        outPatients++;
        totalPatients++;
    }

    void addCriticalCarePatient() {
        criticalCarePatients++;
        totalPatients++;
    }

    void displayPatients() {
        cout << "In-patients: " << inPatients << endl;
        cout << "Out-patients: " << outPatients << endl;
        cout << "Critical Care patients: " << criticalCarePatients << endl;
    }

    static int getTotalPatients() {
        return totalPatients;
    }
};

int Hospital::totalPatients = 0;

int main() {
    Hospital h1;
    h1.addInPatient();
    h1.addInPatient();
    h1.addOutPatient();
    h1.addCriticalCarePatient();
    
    h1.displayPatients();
    cout << "Total patients in hospital: " << Hospital::getTotalPatients() << endl;
    
    return 0;
}


// In-patients: 2
// Out-patients: 1
// Critical Care patients: 1
// Total patients in hospital: 4