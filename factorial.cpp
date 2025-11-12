#include <iostream>
using namespace std;

double factorial(int num){

    while (num > 1){
        float(num);
        num *= (num - 1);
        num--;
    }
    return num;
}

int main()
{
    cout << factorial(5);
    return 0;
}