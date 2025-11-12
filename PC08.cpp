#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const string FileName = "stock.txt";
const int MAX = 50;

typedef string tProdName[MAX];
typedef double tProdPrice[MAX];
typedef int tProdUnits[MAX];

bool load(tProdName prodName, tProdPrice prodPrice, tProdUnits prodUnits, int &counter);
void save(const tProdName prodName, const tProdPrice prodPrice, const tProdUnits prodUnits, int counter);
void initCart(tProdUnits cart, int counter);
void display(const tProdName prodName, const tProdPrice prodPrice, const tProdUnits prodUnits, int counter);
void display(const tProdUnits cart, int counter, const tProdName prodName, const tProdPrice prodPrice);
void sellCart(tProdUnits prodUnits, tProdUnits cart, int counter);
int menu();

int main() {
   tProdName prodName;
   tProdPrice prodPrice;
   tProdUnits prodUnits;
   tProdUnits cart;
   int counter, op = -1, units, numProd;

   if (!load(prodName, prodPrice, prodUnits, counter) || counter == 0) {
      cout << "Impossible to load stock! Aborting..." << endl;
   }
   else {
      initCart(cart, counter);

      while (op != 4 && op != 5) {
         op = menu();

         switch (op) {
            case 1: 
                display(prodName, prodPrice, prodUnits, counter);
                cout << "Product number: ";
                cin >> numProd;
                if (numProd < 1 || numProd > counter) {
                    cout << "No such product! Exiting..." << endl;
                    break;
                }
                cout << "Units to buy: ";
                cin >> units;
                while (units < 1 || units > prodUnits[numProd - 1]) {
                    cout << "Units available: " << prodUnits[numProd - 1] << "! Try again..." << endl;
                    cout << "Units to buy: ";
                    cin >> units;
                }
                cart[numProd - 1] += units;
                break;
            
            case 2:
                display(cart, counter, prodName, prodPrice);
                break;

            case 3:
                initCart(cart, counter);
                cout << "Shopping cart reset!" << endl;
                break;

            case 4:
                sellCart(prodUnits, cart, counter);
                save(prodName, prodPrice, prodUnits, counter);
                cout << "Shopping process completed! See you..." << endl;
                break;

            case 5:
                cout << "Shopping canceled!" << endl;
                break;
         }
      }
   }
   return 0;
}
int menu() {
   int op = -1;
   const int numOp = 5;

   while (op < 1 || op > numOp) {
      cout << endl;
      cout << "1 - Buy a product" << endl;
      cout << "2 - See shopping cart" << endl;
      cout << "3 - Reset shopping cart" << endl;
      cout << "4 - Pay shopping" << endl;
      cout << "5 - Cancel shopping" << endl;
      cout << "Your option: ";
      cin >> op;

      if (op < 1 || op > numOp)
         cout << "Invalid option! Try again..." << endl;
   }
   return op;
}

bool load(tProdName prodName, tProdPrice prodPrice, tProdUnits prodUnits, int &counter) {
   bool ok = false;
   ifstream file(FileName);
   double price;

   if (file.is_open()) {
      ok = true;
      file >> price;
      counter = 0;

      while (price != -1 && counter < MAX) {
         prodPrice[counter] = price;
         file >> prodUnits[counter];
         file.get();
         getline(file, prodName[counter]);
         counter++;
         file >> price;
      }

   file.close();
   }

   return ok;
}

void initCart(tProdUnits cart, int counter) {
   for (int i = 0; i < counter; i++) {
      cart[i] = 0;
   }
}

void save(const tProdName prodName, const tProdPrice prodPrice, const tProdUnits prodUnits, int counter) {
   ofstream file(FileName);

   if (file.is_open()) {
      for (int i = 0; i < counter; i++) {
            file << prodPrice[i] << " " << prodUnits[i] << " " << prodName[i] << endl;
      }
        file << "-1" << endl;
   }
   file.close();
}

void display(const tProdName prodName, const tProdPrice prodPrice, const tProdUnits prodUnits, int counter) {
    cout << " # " << setw(25) << left << "Product" << setw(10) << right << "Price" << setw(8) << "Units" << endl;
      for (int i = 0; i < counter; i++) {
        cout << setw(2) << i + 1 << " " << setw(25) << left << prodName[i] << setw(10) 
        << right << fixed << setprecision(2) << prodPrice[i] << setw(8) << prodUnits[i] << endl;
      }
}

void display(const tProdUnits cart, int counter, const tProdName prodName, const tProdPrice prodPrice) {
    double total = 0;

    for (int i = 0; i < counter; i++) {
        if (cart[i] > 0) {
            double subtotal = cart[i] * prodPrice[i];
            total += subtotal;

            cout << setw(25) << left << prodName[i] << setw(8) << right << fixed << setprecision(2) 
            << prodPrice[i] << " x " << setw(5) << cart[i] << " = " << setw(10) << subtotal << endl;
      }
   }
    cout << "Total " << setw(48) << right << fixed << setprecision(2) << total << endl;
}

void sellCart(tProdUnits prodUnits, tProdUnits cart, int counter) {
    for (int i = 0; i < counter; i++) {
        prodUnits[i] -= cart[i];
        cart[i] = 0;
    }
}