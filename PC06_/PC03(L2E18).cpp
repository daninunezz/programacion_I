#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    float price, discount = 0.0, discount_n, vat_n, pre_total, final_price, total; //we initialize discount to avoid the so called "trash variables"
    int sold;
    char opt1;
    string name, id, pa, product;
    const float VAT = 0.21;

    cout << "Enter a product's price: ";
    cin >> price;
    cout << "Enter the units sold: ";
    cin >> sold;

    cout << "Is there a 15% discount? (Y/N): ";
    cin >> opt1;
    opt1 = toupper(opt1);
    if (opt1 == 'Y') {
        discount = 0.15;
    }
    cin.ignore();
    cout << "Enter your full name: ";
    getline(cin, name);
    cout << "Enter your ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter your postal adress: ";
    getline(cin, pa);
    cout << "Enter the name of the product: ";
    getline(cin, product);

    cout << endl << "Invoice:" << endl;
    cout << setw(50) << right << name << endl;
    cout << setw(50) << pa << endl;
    cout << setw(50) << id << endl;
    cout << left << "Product: " << product << endl;
    cout << setw(40) << "Unit price" << setw(10) << right << fixed << setprecision(2) << price << endl;
    cout << setw(40) << left << "Units" << setw(10) << right << sold << endl;
    total = price * sold;
    cout << setw(40) << left << "Total" << setw(10) << right << total << endl;
    cout << setw(40) << left << "Discount" << setw(9) << right << int(100 * discount) << "%" << endl;
    discount_n = -total * discount;
    cout << setw(50) << discount_n << endl;
    pre_total = total + discount_n;
    cout << setw(40) << left << "Total after discount" << setw(10) << right << pre_total << endl;
    cout << setw(40) << left << "VAT" << setw(9) << right << int(VAT * 100) << "%" << endl;
    vat_n = pre_total * VAT;
    cout << setw(50) << vat_n << endl;
    final_price = pre_total + vat_n;
    cout << setw(40) << left << "Final Price" << setw(10) << right << final_price << endl;

    
    return 0;
}