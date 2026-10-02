
#include <iostream>
#include <cmath>
#include <iterator>
#include <cctype>
#include <regex>

using namespace std;

int main() {
    const int dlimit = 500;
    const int climit = 1000;
    const int plimit = 3000;

    //regex pattern("[DdPpCc]");
    
    char cardType;
    cout << "Enter your card type [D/C/P]: " << endl;
    cin >> cardType;
    if (!regex_match(string(1, cardType), regex("[DdPpCc]"))){
        cout << "[WARNING] Unknown card type." << endl;
            return 0;
    }

    long sum;
    cout << "Enter sum: " << endl;
    cin >> sum;
    if (sum < 0){
        cout << "[WARNING] Invalid negative sum" << endl;
        return 0;
    }
    cout << endl << endl;

    switch(tolower(cardType)){
        case 'd':
            if (sum > dlimit){
               cout << "[WARNING] Entered sum exceeds 500 limit for your plan." << endl;
                return 0; 
            } else {
                cout << "The operation was successful. The sum <= " << dlimit << endl;
            }
            break;
        case 'c':
            if (sum > climit){
               cout << "[WARNING] Entered sum exceeds 1000 limit for your plan." << endl;
                return 0; 
            } else {
                cout << "The operation was successful. The sum <= " << climit << endl;
            }
            break;
        case 'p':
            if (sum > plimit){
               cout << "[WARNING] Entered sum exceeds 3000 limit for your plan." << endl;
                return 0; 
            } else {
                cout << "The operation was successful. The sum <= " << plimit << endl;
            }
            break;
        default:
            break;
    }

    cout << "End." << endl;
    return 0;
}