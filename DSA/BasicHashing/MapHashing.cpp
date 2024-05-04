#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // PRE-COMPUTING START HERE
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for(auto it : mpp) {
        cout << it.first << "->" << it.second << endl;
    }
    
    int q;
    cout << "Enter the number of rounds you wanna check: ";
    cin >> q;
    while (q--)
    {
        int x;
        cout << "\nPlease enter the character you wanted to check: ";
        cin >> x;
        cout << "The character " << x << " appears in the string: " << mpp[x] << " Times" << endl;
    }

    return 0;
}