#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum tSex { Male, Female };
enum tHair { Brown, Blonde, Red, Brunette, Dark };
enum tStudies { Engineering, Science, Health, Social, Humanities };

string hairToStr(tHair hair);
string studiesToStr(tStudies studies);

int main() {
   ifstream input("People.txt");
   ofstream output("People2.txt");
   tSex sex;
   tHair hair;
   tStudies area;
   string name, surname;
   int age, tmp;
   char ch;
   double height, weight;

   if (input.is_open()) {
      getline(input, name);
      while (name != "#") {
         getline(input, surname);
         input >> age >> ch;
         if (ch == 'M')
            sex = Male;
         else
            sex = Female;
         // sex = (ch == 'M' ? Male : Female)
         input >> height >> weight;
         input >> tmp;
         hair = tHair(tmp);
         input >> ch;
         if (ch == 'Y') {
            input >> tmp;
            area = tStudies(tmp);
         }
         //write info to output
         input.get();
         getline(input, name);
      }
   }
   else
      cout << "File not found!" << endl;




   return 0;
}

string hairToStr(tHair hair) {
   string str;

   if (hair == Brown)
      str = "Brown";
   else if (hair == Blonde)
      str = "Blonde";
   else if (hair == Red)
      str = "Red";
   else if (hair == Brunette)
      str = "Brunette";
   else
      str = "Dark";

   return str;
}

string studiesToStr(tStudies studies) {
   string str;

   if (studies == Engineering)
      str = "Engineering";
   else if (studies == Science)
      str = "Science";
   else if(studies == Health)
      str = "Health Sciences";
   else if (studies == Social)
      str = "Social Sciences";
   else
      str = "Humanities";

   return str;
}
