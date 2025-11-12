/* Declare an enumerated type tGrade with the following values: noPresentado,
suspenso, aprobado, notable, sobresaliente and matriculaDeHonor. Then
declare two variables level1 and level2, and read two numerical grades from
0 to 10 (with one decimal). Assign the corresponding values (0: noPresentado)
to two variables grade1 and grade2, of type tGrade. Finally, display each
numerical grade followed by the corresponding textual qualification. (It will only
show qualifications if both grades are between 0 and 10.) The program will use
two functions to return the corresponding tGrade for a numerical grade and the
corresponding string for a tGrade. */

#include <iostream>
using namespace std;
#include <string>

enum tGrade {noPresentado, suspenso, aprobado, notable, sobresaliente, matriculaDeHonor};
string gradeToStr(tGrade g);

int main()
{
    tGrade grade1, grade2;
    float level1 = -1, level2 = -1;
    string grade1Str, grade2Str;

    while (level1 < 0 || level1 > 10 || level2 < 0 || level2 > 10) {
        cout << "Level 1: ";
        cin >> level1;
        cout << "Level 2: ";
        cin >> level2;
    }
    if (level1 == 0) {
        grade1 = noPresentado;
    }
    else if (level1 > 0 && level1 < 5) {
        grade1 = suspenso;
    }
    else if (level1 >= 5 && level1 < 7) {
        grade1 = aprobado;
    }
    else if (level1 >= 7 && level1 < 9) {
        grade1 = notable;
    }
    else if (level1 >= 9 && level1 < 10) {
        grade1 = sobresaliente;
    }
    else {
        grade1 = matriculaDeHonor;
    }
    
    if (level2 == 0) {
        grade2 = noPresentado;
    }
    else if (level2 > 0 && level2 < 5) {
        grade2 = suspenso;
    }
    else if (level2 >= 5 && level2 < 7) {
        grade2 = aprobado;
    }
    else if (level2 >= 7 && level2 < 9) {
        grade2 = notable;
    }
    else if (level2 >= 9 && level2 < 10) {
        grade2 = sobresaliente;
    }
    else {
        grade2 = matriculaDeHonor;
    }

    grade1Str = gradeToStr(grade1);
    grade2Str = gradeToStr(grade2);

    cout << level1 << ": " << grade1Str << endl;
    cout << level2 << ": " << grade2Str << endl;
    
    return 0;
}


string gradeToStr(tGrade g) {
    string str;
    if (g == noPresentado) {
        str = "No Presentado";
    }
    else if(g == suspenso) {
        str = "Suspenso";
    }
    else if(g == aprobado){
        str = "Aprobado";
    }
    else if (g == notable) {
        str = "Notable";
    }
    else if (g == sobresaliente) {
        str = "Sobresaliente";
    }
    else {
        str = "Matrícula de Honor";
    }
    return str;
}