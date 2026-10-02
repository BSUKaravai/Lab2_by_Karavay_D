#include <iostream>
#include <cmath>
#include <iterator>

using namespace std;

int main() {
    const float limitPercent = 0.4f;
    long income, fees, payment; //<- i googled how banks represent their data let's assume 1050 = 10.50$

    cout << "Enter income (the number must be >= 0): ";
    cin >> income;
    cout << "Enter fees (the number must be >= 0): ";
    cin >> fees;
    cout << "Enter payment (the number must be >= 0): ";
    cin >> payment;

    //Long scary tenary operator to avoid working with strings directly
    if (income < 0 || fees < 0 || payment < 0){
        cout << "[WARNING] Invalid negative value for " << ((income < 0) ? ( (fees < 0) ? ( (payment < 0) ? ("income, fees & payment.\n") : ("income & fees.\n") ) 
            : ( (payment < 0) ? ("income & payment.\n") : ("income.\n") ) ) 
            
            : ( (fees < 0) ? ( (payment < 0) ? ("fees & payment.\n") : ("fees.\n") ) 
            : ( (payment < 0) ? ("payment.\n") : ("[THIS LINE SHOULDN'T EXIST]") ) ));
        return -1; //Exits code with an error
    }

    //
    if (income == 0){
        cout << "You've been denied bc you're too broke." << endl;
            
    } else {
        bool isDoublMoneyLeft = (2*payment <= (income - fees));
        bool isLessThanLimit = (payment <= limitPercent*income);
        
        if (isDoublMoneyLeft && isLessThanLimit) {
            cout << "Rejoice! You are given a credit you will have to repay for the next 15 years!" << endl;
            
        } else {
            cout << ((isDoublMoneyLeft) ? "You've been denied bc you're too broke again." : "You've been denied bc you spend too much on your food." ) << endl;
            
        }
    }
    //

    cout << "End." << endl;
    return 0;
}