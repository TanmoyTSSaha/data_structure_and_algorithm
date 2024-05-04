#include<iostream>
using namespace std;

void function(int i, int n) {
    if (i <= 0) return;
    cout << n-i << endl;
    function(i-1,n);
}

int main() {
    int i;
    int n;
    cout << "Enter the counter number: ";
    cin >> i;
    n=i+1;
    cout << endl;
    function(i,n);
    return 0;
}