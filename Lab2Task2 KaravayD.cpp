
#include <iostream>
#include <cmath>
#include <iterator>

using namespace std;

int main() {
    const float comPerCent = 0.02f;
    const long minCom = 1;
    
    long balance, sum;
    bool isOurBank;

    //We could the same negative checks here but im too lazy
    cout << "Enter balance: ";
    cin >> balance;
    //Negative/divisibility checks for sum
    do {
        cout << "Enter sum (>0, %10 == 0): ";
        cin >> sum;
        
        if (sum <= 0){
               cout << "Invalid non-positive value for sum. Try again." << endl;
        } else if (sum % 10 != 0){
               cout << "Sum must be divisable by 10. Try again." << endl;
        }
        
    } while (sum <= 0 || sum % 10 != 0);
    //
    cout << "Enter (it is our bank): ";
    cin >> isOurBank;
    cout << endl;

    
    switch (isOurBank){
        case 0: {
            long double commission = (sum * comPerCent < minCom) ? minCom : sum * comPerCent;
            if (commission + sum > balance) {
                cout << "Not enough money wonk wonk." << endl;
            } else {
                balance -= commission + sum;
                cout << "Operation successful. Your current balance is: \n\t\t" 
                    << balance << endl;
            }
            break;
        }
        default:
            if (sum > balance) {
                cout << "Not enough money wonk wonk." << endl;
            } else {
                balance -= sum;
                cout << "Operation successful. Your current balance is: \n\t\t"
                    << balance << endl;
            }
            break;
    }

    cout << "End." << endl;
    return 0;
}