#include<iostream>
using namespace std;

int counter;
int loopCounter = 0;

void function() {
    if (loopCounter > counter) return;
    cout << loopCounter << endl;
    loopCounter++;
    function();
}

int main() {
    cout << "Enter the counter number: ";
    cin >> counter;
    cout << endl;
    function();
    return 0;
}