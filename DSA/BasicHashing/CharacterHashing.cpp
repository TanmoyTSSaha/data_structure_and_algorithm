#include<bits/stdc++.h>
using namespace std;

int main () {
    string s;
    cout << "Enter your string: ";
    cin >> s;

    // PRE-COMPUTING || HASHING STARTS HERE.
    int hash[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]]++;
    }

    int q;
    cout << "Enter the number of rounds you wanna check: ";
    cin >> q;
    while (q--)
    {
        char x;
        cout << "Please enter the character you wanted to check: ";
        cin >> x;
        cout << "\nThe character " << x << " appears in the string: " << hash[x] << " Times" << endl;
    }
    
    

    return 0;
}