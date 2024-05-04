#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the length of Array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int hash[13] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }
    
    int q;
    cout << "Enter the number of rounds you are checking: ";
    cin >> q;
    while (q--)
    {
        int number;
        cout << "Enter the number to check: ";
        cin >> number;
        cout << "\nThe number " << number << " appears in the array: " << hash[number] << " Times" << endl;
    }


    
    return 0;
}