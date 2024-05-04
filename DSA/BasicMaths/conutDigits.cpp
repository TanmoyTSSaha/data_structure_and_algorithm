#include<iostream>
using namespace std;


void countDigit() {
    int digit = 0;
    cout << "Enter your digit: ";
    cin >> digit;
    cout << endl;

    cout << "Extracted numbers are: ";
    while (digit > 0) {
        int extractedNumber;
        extractedNumber = digit%10;
        cout << extractedNumber << " ";
        digit = digit / 10;
    }
}

int main() {
    countDigit();
    return 0;
}