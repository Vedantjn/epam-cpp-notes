#include <iostream>
#include <string>
using namespace std;

enum PatientType {
    INPATIENT = 1,
    OUTPATIENT = 2,
    CRITICALCARE = 3
};

class Patient {
protected:
    string name;
    int age;
    int patientId;
    static int nextId;

public:
    Patient() {
        patientId = nextId++;
    }
    
    virtual void inputDetails() {
        cout << "Enter patient name: ";
        cin >> name;
        cout << "Enter patient age: ";
        cin >> age;
    }
};

class InPatient : public Patient {
private:
    int roomNumber;
    int daysOfStay;

public:
    void inputDetails() override {
        Patient::inputDetails();
        cout << "Enter room number: ";
        cin >> roomNumber;
        cout << "Enter expected days of stay: ";
        cin >> daysOfStay;
    }
};

class OutPatient : public Patient {
private:
    string appointmentTime;

public:
    void inputDetails() override {
        Patient::inputDetails();
        cout << "Enter appointment time: ";
        cin >> appointmentTime;
    }
};

class CriticalCarePatient : public Patient {
private:
    string icuUnit;
    int ventilatorNumber;

public:
    void inputDetails() override {
        Patient::inputDetails();
        cout << "Enter ICU unit: ";
        cin >> icuUnit;
        cout << "Enter ventilator number: ";
        cin >> ventilatorNumber;
    }
};

class Hospital {
private:
    static int totalPatients;
    int inPatients;
    int outPatients;
    int criticalCarePatients;

public:
    Hospital() : inPatients(0), outPatients(0), criticalCarePatients(0) {}

    void processPatient(int choice) {
    switch(choice) {
        case INPATIENT: {
            InPatient* patient = new InPatient();
            patient->inputDetails();
            inPatients++;
            totalPatients++;
            break;
        }
        case OUTPATIENT: {
            OutPatient* patient = new OutPatient();
            patient->inputDetails();
            outPatients++;
            totalPatients++;
            break;
        }
        case CRITICALCARE: {
            CriticalCarePatient* patient = new CriticalCarePatient();
            patient->inputDetails();
            criticalCarePatients++;
            totalPatients++;
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
        }
    }


    void displayPatients() const {
        cout << "\nHospital Statistics:" << endl;
        cout << "In-patients: " << inPatients << endl;
        cout << "Out-patients: " << outPatients << endl;
        cout << "Critical Care patients: " << criticalCarePatients << endl;
        cout << "Total patients: " << totalPatients << endl;
    }
};

int Hospital::totalPatients = 0;
int Patient::nextId = 1000;

int main() {
    Hospital hospital;
    int choice;

    while (true) {
        cout << "\n1. Add In-Patient" << endl;
        cout << "2. Add Out-Patient" << endl;
        cout << "3. Add Critical Care Patient" << endl;
        cout << "4. Display Statistics" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting program..." << endl;
            break;
        } else if (choice >= 1 && choice <= 3) {
            hospital.processPatient(choice);
        } else if (choice == 4) {
            hospital.displayPatients();
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
