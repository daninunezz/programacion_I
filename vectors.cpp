#include <iostream>
using namespace std;

const int DIM = 3;
typedef int tVector[DIM];


int main()
{
    tVector v1, v2, vr;

    for (int i = 0; i < DIM; i++) {
        cout << "v1" << i + 1 << ": ";
        cin >> v1[i];
    }

    for (int i = 0; i < DIM; i++) {
        cout << "v2" << i + 1 << ": ";
        cin >> v2[i];
    }

    for (int i = 0; i < DIM; i++) {
        vr[i] = v1[i] + v2[i];
    }
    
    return 0;
}