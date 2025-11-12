#include <iostream>
using namespace std;

int main()
{
    char character;
    bool digit = false, letter = false, lowercase = false, uppercase = false;

    cout << "Enter a character: ";
    cin >> character;

    if (character >= '0')
        if (character <= '9')
            digit = true;
    
    if (character >= 'A')
        if (character <= 'Z'){
            letter = true;
            uppercase = true;
        }
    if (character >= 'a')
        if (character <= 'z'){
            letter = true;
            lowercase = true;
        }
        
    return 0;
}