#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 30;
typedef double tNumbers[MAX];
typedef string tStrings[MAX];
int counter = 0;
tNumbers grades;
tStrings names;

int menu();
void addStud(int& counter);
void locate(int counter);
void del(int& counter);
 void print(int counter);

int main() {

    string name;
    double grade;
    
    ifstream file("list.txt");
    if (file.is_open()) {
        getline(file, name);
        while (name != "XXX") {
            file >> grade;
            names[counter] = name;
            grades[counter] = grade;
            counter++;
            file.get();
            getline(file, name);
        }
    }
    bool loop = true;
    while (loop) {
        switch (menu()) {
            case 0:
                loop = false;
                break;
            case 1:
                print(counter);
                break;
            case 2:
                addStud(counter);
                break;
            case 3:
                locate(counter);
                break;
            case 4:
                del(counter);
                break;
        }
    }

    return 0;
}

int menu() {
    int op = -1;
    while (op < 0 || op > 5) {
        cout << "1. Display the list" << endl;
        cout << "2. Insert new student" << endl;
        cout << "3. Locate student" << endl;
        cout << "4. Delete student" << endl;
        cout << "0. Exit program" << endl;
        cout << "your option: ";
        cin >> op;
        if (op < 0 || op > 5) {
            cout << "Not possible" << endl;
        }
    }
    return op;
}

void addStud(int& counter) {
    int op = -1;
    string name;
    double grade;
    //eh
    cout << "Enter the name of the student: ";
    cin.get();
    getline(cin, name);
    cout << "Enter the grade of the student: ";
    cin >> grade;
    cout << "In which position would you like to add the student? (1 - " << counter + 1 <<  "): ";
    cin >> op;
    for (int i = counter; i >= op; i--) {
        names[i] = names[i - 1];
        grades[i] = grades[i - 1];
    }
    names[op - 1] = name;
    grades[op -1] = grade;
    counter += 1;
}

void locate(int counter) {
    string name;
    cout << "Enter the name of the student you want to find: ";
    cin.get();
    getline(cin, name);
    int pos = -1;
    for (int i = 0; i < counter; i++) {
        if (names[i] == name) {
            pos = i + 1;
        }
    }
    cout << "Student found in position " << pos << endl;
}

void del(int& counter) {
    int op;
    cout << "Enter the position of the student you want to delete: ";
    cin >> op;
    for (int i = op - 1; i < counter; i++) {
        names[i] = names[i + 1];
        grades[i] = grades[i + 1];
    }
    counter -= 1;
}

void print(int counter) {
    for (int i = 0; i < counter; i++) {
        cout << setw(3) << left << i + 1 << setw(20) << names[i] << setprecision(2) << right << grades[i] << endl;
    }
}



