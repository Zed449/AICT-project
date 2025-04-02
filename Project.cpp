#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Structure to store patient details
struct Patient {
    string name;
    int age;
    float bloodPressure;
    float temperature;
    string diagnosis;
};

// Function to add a new patient record
void addPatient() {
    Patient p;
    cout << "Enter Patient Name: ";
    cin.ignore();
    getline(cin, p.name);
    cout << "Enter Age: ";
    cin >> p.age;
    cout << "Enter Blood Pressure (mmHg): ";
    cin >> p.bloodPressure;
    cout << "Enter Temperature (°C): ";
    cin >> p.temperature;
    cout << "Enter Diagnosis: ";
    cin.ignore();
    getline(cin, p.diagnosis);

    ofstream file("patients.txt", ios::app);
    if (file.is_open()) {
        file << p.name << "," << p.age << "," << p.bloodPressure << "," << p.temperature << "," << p.diagnosis << "\n";
        file.close();
        cout << "Patient record added successfully!\n";
    } else {
        cout << "Error opening file!\n";
    }
}

// Function to view all patient records
void viewPatients() {
    ifstream file("patients.txt");
    if (!file.is_open()) {
        cout << "No records found!\n";
        return;
    }
    string line;
    cout << "\n--- Patient Records ---\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

// Function to search for a patient by name
void searchPatient() {
    ifstream file("patients.txt");
    if (!file.is_open()) {
        cout << "No records found!\n";
        return;
    }
    string searchName, line;
    cout << "Enter Patient Name to Search: ";
    cin.ignore();
    getline(cin, searchName);
    bool found = false;
    while (getline(file, line)) {
        if (line.find(searchName) != string::npos) {
            cout << "Record Found: " << line << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No record found for " << searchName << "\n";
    }
    file.close();
}

// Main function with menu system
int main() {
    int choice;
    do {
        cout << "\n--- Patient Health Record System ---\n";
        cout << "1. Add Patient Record\n";
        cout << "2. View All Records\n";
        cout << "3. Search for a Patient\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                viewPatients();
                break;
            case 3:
                searchPatient();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);
    return 0;
}
