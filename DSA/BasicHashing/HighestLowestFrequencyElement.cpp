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

    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    int highest_frequency = 0;
    int highest_frequency_number;
    int lowest_frequency = 100000;
    int lowest_frequency_number;

    for (auto it : mpp)
    {
        if (highest_frequency < it.second)
        {
            highest_frequency = it.second;
            highest_frequency_number = it.first;
        }

        if (lowest_frequency > it.second)
        {
            lowest_frequency = it.second;
            lowest_frequency_number = it.first;
        }
    }
    
    cout << "Highest Frequency Number is: " << highest_frequency_number << " Frequency: " << highest_frequency << endl;
    cout << "Lowest Frequency Number is: " << lowest_frequency_number << " Frequency: " << lowest_frequency << endl;

    return 0;
}