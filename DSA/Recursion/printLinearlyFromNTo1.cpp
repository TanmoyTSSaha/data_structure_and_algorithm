#include<iostream>
using namespace std;

int counter;

void function() {
    if (counter < 1) return;
    cout << counter << endl;
    counter--;
    function();
}

int main() {
    cout << "Enter the counter number: ";
    cin >> counter;
    cout << endl;
    function();
    return 0;
}