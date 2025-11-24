#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

string fileName = "";
const int MAX = 20;
int counter = 0, currMax = 0;
bool found = false;
typedef string tNames[MAX];
typedef int tQuantities[MAX];
tNames nameList;
tQuantities gramsList;
tQuantities caloriesList;

void load(string fileName, int& counter, bool& found);
double totCal(tQuantities gramsList, tQuantities caloriesList, int counter);
void display(string recipeName, tQuantities gramsList, tQuantities caloriesList, tNames nameList, int counter);
int findMax(tQuantities gramsList, tQuantities caloriesList, int counter);
void save(tNames nameList, tQuantities gramsList, tQuantities caloriesList, int counter, string fileName);

int main() {
    string recipeName = "", newName = "";
    int newCal = 0, newGram = 0, newTot = 0;
    cout << "Enter the name of the file: ";
    cin >> fileName;
    load(fileName, counter, found);
    if (found) {
        cout << "Enter the name of the recipe: ";
        cin.get();
        getline(cin, recipeName);
        display(recipeName, gramsList, caloriesList, nameList, counter);
        cout << "The ingredient with the most calories is found in number " << findMax(gramsList, caloriesList, counter) << endl;
        cout << "Change that product for a healthier one" << endl;

        currMax = findMax(gramsList, caloriesList, counter);
        do {
            cout << "New ingredient name: ";
            cin.get();
            getline(cin, newName);
            cout << "Calories / 100gr of this ingredient: ";
            cin >> newCal;
            cout << "Grams of this ingredient: ";
            cin >> newGram;
            if (newGram * (newCal / 100.0) > gramsList[currMax - 1] * (caloriesList[currMax - 1] / 100.0)) {
                cout << "The ingredient must be healthier, try again..." << endl;
            }
        } while (newGram * (newCal / 100.0) > gramsList[currMax - 1] * (caloriesList[currMax - 1] / 100.0));

        nameList[currMax - 1] = newName;
        caloriesList[currMax - 1] = newCal;
        gramsList[currMax - 1] = newGram;

        display(recipeName, gramsList, caloriesList, nameList, counter);
        save(nameList, gramsList, caloriesList, counter, fileName);
        return 0;
    }
}

void load(string fileName, int& counter, bool& found) {
    int grams = 0;
    int calories = 0;
    string name = "";

    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Couldn't open the file" << endl;
    }
    else {
        found = true;
        file >> grams;
        while (grams != 0) {
            file >> calories;
            file.get();
            getline(file, name);

            gramsList[counter] = grams;
            caloriesList[counter] = calories;
            nameList[counter] = name;
            counter++;
            file >> grams;
        }
        file.close();
    }
}

double totCal(tQuantities gramsList, tQuantities caloriesList, int counter) {
    double totCal = 0;
    for (int i = 0; i < counter; i++) {
        totCal += gramsList[i] * (caloriesList[i] / 100.0);
    }
    return totCal;
}

void display(string recipeName, tQuantities gramsList, tQuantities caloriesList, tNames nameList, int counter) {
    cout << left << recipeName << " information" << endl;
    cout << setw(3) << "#" << setw(15) << "Ingredient" << setw(7) << "Grams" << setw(20) << "Calories / 100g" << setw(12) << "Total calories" <<  endl;
    for (int i = 0; i < counter; i++) {
        cout << setw(3) << i + 1 << setw(16) << nameList[i] << setw(12) << gramsList[i] << setw(20) << caloriesList[i] << setw(11) << gramsList[i] * (caloriesList[i] / 100.0) << endl;
    }
    cout << "Total calories: " << fixed << setprecision(2) << setw(42) << right << totCal(gramsList, caloriesList, counter) << endl << endl;
}

int findMax(tQuantities gramsList, tQuantities caloriesList, int counter) {
    int max = 0;
    int index = 0;
    for (int i = 0; i < counter; i++) {
        if (gramsList[i] * (caloriesList[i] / 100.0) > max) {
            max = gramsList[i] * (caloriesList[i] / 100.0);
            index = i + 1;
        }
    }
    return index;
}

void save(tNames nameList, tQuantities gramsList, tQuantities caloriesList, int counter, string fileName) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cout << "Unable to open the file..." << endl;
    }
    else {
        for (int i = 0; i < counter; i++) {
            file << gramsList[i] << " " << caloriesList[i] << " " << nameList[i] << endl;
        }
    file << 0;
    }
}
