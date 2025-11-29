//
// Nicholas Vitanza
// 11/29/25
// Final Project
// COSC 2030
//

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double sales,       // Monthly Sales
           rate,        // Rate of Commission
           commission,  // Amount of Commission
           advance,     // Advanced Pay Drawn
           pay;         // Pay remaining to be paid

    cout << "Enter the salesperson's monthly sales: ";
    cin >> sales;

    cout << "Enter the amount of advanced pay for this salesperson: ";
    cin >> advance;

    if (sales < 10000)
        rate = 0.05;
    else if (sales < 15000)      // FIXED upper bound from 14999 → 15000
        rate = 0.10;
    else if (sales < 18000)      // FIXED upper bound from 17999 → 18000
        rate = 0.12;
    else if (sales < 22000)      // FIXED upper bound from 21999 → 22000
        rate = 0.14;
    else
        rate = 0.16;

    commission = sales * rate;

    pay = commission - advance;

    cout << fixed << showpoint << setprecision(2);
    cout << "\nPay Results\n";
    cout << "-----------\n";
    cout << "Sales: $" << sales << endl;
    cout << "Commission Rate: " << rate << endl;
    cout << "Commission: $" << commission << endl;
    cout << "Advanced Pay: $" << advance << endl;
    cout << "Remaining Pay: $" << pay << endl;

    return 0;
}