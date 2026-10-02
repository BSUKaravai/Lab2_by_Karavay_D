// Online C++ compiler (editor)
// Write and run C++ online using this editor.
// Online C++ compiler (editor)
// Write and run C++ online using this editor.

#include <iostream>
#include <cmath>
#include <iterator>
#include <cctype>
#include <regex>

using namespace std;

int main() {
    const float wComPerCent = 0.01f;
    const float tComPerCent = 0.015f;
    const float pComPerCent = 0.0f;
    
    const float wMinCom = 0.5f;
    const float tMinCom = 1.0f;
    const float pMinCom = 0.0f;

    char operation;
    cout << "Enter operation [W/T/P]: " << endl;
    cin >> operation;
    if (!regex_match(string(1, operation), regex("[WwTtPp]"))){
        cout << "[WARNING] Unknown operation type." << endl;
        return 0;
    }

    long balance;
    cout << "Enter balance: " << endl;
    cin >> balance;
    if (balance < 0){
        cout << "[WARNING] Invalid negative balance." << endl;
        return 0;
    }

    long sum;
    cout << "Enter sum: " << endl;
    cin >> sum;
    if (sum <= 0){
        cout << "[WARNING] Invalid non-positive sum." << endl;
        return 0;
    }

    if (tolower(operation) == 'w' && sum % 10 != 0){
        cout << "[WARNING] Withdrawal sum must be divisible by 10." << endl;
        return 0;
    }

    long double commission;

    switch(tolower(operation)){
        case 'w':
            commission = (sum * wComPerCent < wMinCom) ? wMinCom : sum * wComPerCent;
            break;
        case 't':
            commission = (sum * tComPerCent < tMinCom) ? tMinCom : sum * tComPerCent;
            break;
        case 'p':
            commission = pComPerCent * sum;
            break;
        default:
            break;
    }

    long double totalCharge = sum + commission;

    if (totalCharge > balance){
        cout << "[WARNING] Insufficient balance for operation and commission." << endl;
        return 0;
    }

    balance -= totalCharge;

    cout << "\n\tOperation was successful." << endl;
    cout << "Commission: " << commission << endl;
    cout << "Total charge: " << totalCharge << endl;
    cout << "New balance: " << balance << endl;

    cout << "End." << endl;
    return 0;
}