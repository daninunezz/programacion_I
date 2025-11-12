#include <iostream>
using namespace std;
#include <fstream>

bool isTriangle(int number);

int main() {
    int n = 1;
    ifstream inputFile("integers.txt");
    if (inputFile.is_open()){
        while (inputFile >> n) {
            if (isTriangle(n)) {
                cout << n << " is a triangle";
            }
            else
                cout << n << " is not a triangle";
            cout << endl;
        }
        inputFile.close();
    }
    return 0;
}

bool isTriangle(int number) {
    bool triangle = false;
    int total = 0, summation = 1;
        while (total <= number) {
            if (number == total) {
                triangle = true;
                break;
            }
            else {
                total += summation;
                summation++;
            }
        }
    return triangle;
}