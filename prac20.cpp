
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Patient {
    string name;
    int priority;
    Patient(string n, int p) : name(n), priority(p) {}

    // Modify operator to handle priorities where a smaller number means higher priority
    bool operator>(const Patient& other) const {
        return this->priority > other.priority;
    }
};

class ComparePatient {
public:
    bool operator()(const Patient& p1, const Patient& p2) {
        return p1 > p2; // Use our custom comparison
    }
};

void manageq() {
    priority_queue<Patient, vector<Patient>, ComparePatient> pq;
    int ch, n, pri;
    string name;
    do {
        cout << "\n======MENU========\n";
        cout << "1. Add patient\n";
        cout << "2. Serve patient\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch(ch) {
            case 1:
                cout << "Enter the number of patients to add: ";
                cin >> n;
                for(int i = 0; i < n; i++) {
                    cout << "Enter the name of patient " << i+1 << ": ";
                    cin >> name;
                    cout << "Enter the priority of patient " << i+1 << " (1=serious / 2=not serious / 3=general checkup): ";
                    cin >> pri;
                    pq.push(Patient(name, pri));
                }
                break;
            case 2:
                if (!pq.empty()) {
                    Patient p = pq.top();
                    pq.pop();
                    cout << "Serving patient: " << p.name << " priority: " << p.priority << endl;
                } else {
                    cout << "No patients to serve!" << endl;
                }
                break;
            case 3:
                cout << "Exiting program!\n";
                break;
        }
    } while (ch != 3);
}

int main() {
    manageq();
    return 0;
}

