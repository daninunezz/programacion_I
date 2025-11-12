#include <iostream>
using namespace std;
#include <string>

string inverted(int num);

int main(){
    int n;
    bool loop = true;
    
    while (loop == true) {
        cout << "Enter a number to invert it: ";
        cin >> n;
        cout << inverted(n) << endl;
        cout << "Continue? (1 - YES, 0 - NO): " << endl;
        cin >> loop;
    }
    return 0;
}

string inverted(int num) {
    string inverted;
    char ch;
    int n;
    while (num != 0) {
        n = num % 10;
        num /= 10;
        switch (n) {
            case 1:
                ch = '1';
                break;
            case 2:
                ch = '2';
                break;
            case 3:
                ch = '3';
                break;
            case 4:
                ch = '4';
                break;
            case 5:
                ch = '5';
                break;
            case 6:
                ch = '6';
                break;
            case 7:
                ch = '7';
                break;
            case 8:
                ch = '8';
                break;
            case 9:
                ch = '9';
                break;
        }
        inverted += ch;

    }
    return inverted;
}