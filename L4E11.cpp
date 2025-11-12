#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;
int counter = 0;
typedef double tList[MAX];
tList numbers;

int menu();
void endN(int& count);
void begN(int& count);
void del(int& count);
void locate(int count);
void print(tList list, int count);
void save(int count);
bool isFull(int count);

int main() {
    ifstream file("list.txt");
    if (file.is_open()) {
        int index = 0;
        file >> numbers[0];
        while (numbers[index] != -1) {
            counter++;
            index++;
            file >> numbers[index];
        }
    }
    else cout << "Mistake loading file..." << endl;
    
    bool loop = true;
    while (loop == true) {
        switch (menu()) {
            case 1:
                endN(counter);
                break;
            case 2:
                begN(counter);
                break;
            case 3:
                del(counter);
                break;
            case 4:
                locate(counter);
                break;
            case 5:
                print(numbers, counter);
                break;
            case 6:
                save(counter);
                break;
            case 7:
                loop = false;
                break;
        }
    }

    return 0;
}

int menu() {
    int op = -1;
    while (op < 1 || op > 7) {
        cout << "1. Insert a new number at the end" << endl;
        cout << "2. Insert a new number at the beginning" << endl;
        cout << "3. Delete a number given its position" << endl;
        cout << "4. Locate a number" << endl;
        cout << "5. Print the list" << endl;
        cout << "6. Save the list" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your option: ";
        cin >> op;
    }
    return op;
}

void endN(int& count) {
    if (isFull(count)) {
        cout << "The list is full, you can't add more numbers." << endl;
        return;
    }

    double n;
    cout << "Enter the number you want to add: ";
    cin >> n;
    
    if (n == int(n)) {
        n = int(n);
    }
    numbers[count] = n;
    numbers[count + 1] = -1;
    count += 1;
}

void begN(int& count) {
    if (isFull(count)) {
        cout << "The list is full, you can't add more numbers." << endl;
        return;
    }

    double n;
    cout << "Enter the number you want to add: ";
    cin >> n;  
    for (int i = count; i > 0; i--) {
        numbers[i] = numbers[i - 1];
    }
    if (n == int(n)) {
        n = int(n);
    }
    numbers[0] = n;
    count += 1;
}

void del(int& count) {
    int n = 0;
    while (n < 1 || n > count) {
        cout << "Which element would you like to delete?: ";
        cin >> n;
        if (n < 1 || n > count) cout << "Invalid number" << endl;
    }
    for (int i = n - 1; i < count; i++) {
        numbers[i] = numbers[i + 1];
    }
    count -= 1;
}

void locate(int count) {
    double n;
    cout << "Enter the number you want to find: ";
    cin >> n;
    bool loop = true, found = false;
    int counter = 0;
    while (loop) {
        if (numbers[counter] == n) {
            loop = false;
            found = true;
        }
        if (counter > count) {
            loop = false;
        }
        counter++;
    }
    if (found)
        cout << "Number found in line " << counter << endl;
    else
        cout << "Number not found" << endl;
}

void print(tList list, int count) {
    for (int i = 0; i < count; i++) {
        cout << list[i] << endl;
    }
}

void save(int count) {
    ofstream file("list.txt");
    if (file.is_open()) {
        for (int i = 0; i < count; i++){
            file << numbers[i] << endl;
        }
        file << -1;
        file.close();
    }
    else cout << "Error loading file..." << endl;
}

bool isFull(int count) {
    return count >= MAX;
}