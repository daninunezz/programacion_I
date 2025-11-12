
#include <iostream>
using namespace std;

int table(int num);

int main() {
    table(2);
    
    return 0;
}


int table(int num){
    int counter = 1;
    while (num <= counter) {
        cout << counter << " * " << num << " = " << counter * num << endl;
    };
}

