#include<iostream>
using namespace std;

void function(int i, int n) {
    if (n >= i) return;
    cout << i-n << endl;
    function(i,n+1);
}

int main() {
    int i;
    int n = 0;
    cout << "Enter the counter number: ";
    cin >> i;
    cout << endl;
    function(i,n);
    return 0;
}