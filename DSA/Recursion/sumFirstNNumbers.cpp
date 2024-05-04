#include<iostream>
using namespace std;


void parameterizedRecursion(int i, int n) {
    if (i < 1) {
        cout << "The Parameterised Sum is: " << n << endl;
        return;
    }
    parameterizedRecursion(i-1,n+i);
}

int functionalRecursion(int i) {
    int n;
    if (i<1) return 0;
    n = i + functionalRecursion(i-1);
    return n;
}

int* reverseAnArray(int* ary, int l, int r) {
    if (l>=r) return ary;
    int swp;
    swp = ary[l];
    ary[l] = ary[r];
    ary[r]=swp;
    return reverseAnArray(ary, l+1, r-1);

}

bool func(int i, string &s) {
    if (i>=s.size()/2) return true;
    if (s[i] != s[s.size()-i-1]) return false;
    
    return func(i+1, s);
}

int main() {
    int aL;
    cout << "Enter the length of array: ";
    cin >> aL;
    int ary[aL];
    cout << endl << "Enter the array numbers: ";
    for (int i = 0; i < aL; i++)
    {
        cin >> ary[i];
    }
    cout << endl;
    
    int* reversedArray = reverseAnArray(ary, 0, aL-1);

    cout << "Your reversed array is: ";
    for (int i = 0; i < aL; i++)
    {
        cout << reversedArray[i] << " ";
    }
    cout << endl;

    return 0;
}