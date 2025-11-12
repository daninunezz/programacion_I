// Practice Class 5

#include <iostream>
#include <string>
#include <fstream>
#include <cctype> // To convert to uppercase
using namespace std;

enum tGenre { action, adventure, scifi, comedy, drama, mystery, horror };
enum tLanguage { spanish, english, french, german, italian, portuguese };

tGenre readGenre(); // Returns the genre selected by the user
string genreStr(tGenre genre); // Returns the name (string) of a genre
tLanguage readLanguage(); // Returns the language selected by the user
string languageStr(tLanguage lang); // Returns the name (string) of a language

int main() {
    string title, director, nif, date, langStr, genStr, subtStr;
    tGenre genre;
    tLanguage language, subtitles;
    bool subtornot = false;
    int minutes, dayOfRental, aux, rentalN = 1;
    char option;
    ifstream inputFile;
    ofstream outputFile;

    outputFile.open("rentals.txt");

    if (outputFile.is_open()) {
        cout << "Film title (# to end): ";
        getline(cin, title);
        outputFile << title << endl;
        while (title != "#") {
            cout << "Film director: ";
            getline(cin, director);
            outputFile << director << endl;

            genre = readGenre();
            outputFile << int(genre) << endl;
            
            language = readLanguage();
            outputFile << int(language) << endl;

            cout << "Film with subtitles? (y/n): ";
            cin >> option;
            option = toupper(option);
            outputFile << option << endl;
            if (option == 'Y')
                subtornot = true;
            else
               subtornot = false;
            if (subtornot == true) {
                subtitles = readLanguage();
                outputFile << int(subtitles) << endl;
            }
            cout << "Minutes: ";
            cin >> minutes;
            outputFile << minutes << endl;
            cout << "Client NIF: ";
            cin >> nif;
            outputFile << nif << endl;
            cout << "Rental date: ";
            cin.get();
            getline(cin, date);
            outputFile << date << endl;
            cout << "Rental days: ";
            cin >> dayOfRental;
            outputFile << dayOfRental << endl;
            cout << "Film title (# to end): ";
            cin.get();
            getline(cin, title);
            outputFile << title << endl;
        }
        outputFile.close();
        
        inputFile.open("rentals.txt");
        getline(inputFile, title);
        cout << endl;
        while (title != "#") { 
            getline(inputFile, director);
            inputFile >> aux;
            genre = tGenre(aux);
            inputFile >> aux;
            language = tLanguage(aux);
            inputFile >> option;
            if (option == 'Y') {
               inputFile >> aux;
               subtitles = tLanguage(aux);
            }
            inputFile >> minutes;
            inputFile.get();
            getline(inputFile, nif);
            getline(inputFile, date);
            inputFile >> dayOfRental;
            langStr = languageStr(language);
            subtStr = languageStr(subtitles);
            genStr = genreStr(genre);
            cout << "Rental " << rentalN << endl;
            rentalN++;
            cout << title << " (" << director << "), " << genStr << ", " << langStr;
            if (option == 'Y') {
               cout << " (subt. " << subtStr << ")";
            }
            cout << ", " << minutes << " min." << endl;
            cout << "Client: " << nif << " - " << date << ", " << dayOfRental << " days" << endl;
            cout << "---------------" << endl;
            inputFile.get();
            getline(inputFile, title);
         }
         inputFile.close();
    }
   return 0;
}

tGenre readGenre() {
   tGenre genre;
   bool ok = false;
   int num;

   while (!ok) {
      cout << "Film genre:" << endl;
      cout << "1 - Action" << endl;
      cout << "2 - Adventure" << endl;
      cout << "3 - Science Fiction" << endl;
      cout << "4 - Comedy" << endl;
      cout << "5 - Drama" << endl;
      cout << "6 - Mystery" << endl;
      cout << "7 - Horror" << endl;
      cout << "Genre number: ";
      cin >> num;
      if (num >= 1 && num <= 7)
         ok = true;
   }
   genre = tGenre(num - 1);

   return genre;
}

string genreStr(tGenre genre) {
   string str;

   if (genre == action)
      str = "Action";
   else if (genre == adventure)
      str = "Adventure";
   else if (genre == scifi)
      str = "Science Fiction";
   else if (genre == comedy)
      str = "Comedy";
   else if (genre == drama)
      str = "Drama";
   else if (genre == mystery)
      str = "Mystery";
   else if (genre == horror)
      str = "Horror";

   return str;
}

tLanguage readLanguage() {
   bool ok = false;
   int num;
   tLanguage language;

   while (!ok) {
      cout << "Language:" << endl;
      cout << "1 - Spanish" << endl;
      cout << "2 - English" << endl;
      cout << "3 - French" << endl;
      cout << "4 - German" << endl;
      cout << "5 - Italian" << endl;
      cout << "6 - Portuguese" << endl;
      cout << "Language number: ";
      cin >> num;
      if (num >= 1 && num <= 6)
         ok = true;
   }
   language = tLanguage(num - 1);

   return language;
}

string languageStr(tLanguage lang) {
   string str;

   if (lang == spanish)
      str = "Spanish";
   else if (lang == english)
      str = "English";
   else if (lang == french)
      str = "French";
   else if (lang == german)
      str = "German";
   else if (lang == italian)
      str = "Italian";
   else if (lang == portuguese)
      str = "Portuguese";

   return str;
}