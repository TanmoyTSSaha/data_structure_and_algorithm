#include <iostream>

using namespace std;

int main()
{
    int size;
    int num_to_checked;
    cout << "Enter the Size of the array: ";
    cin >> size;
    cout << "\nEnter the number to check: ";
    cin >> num_to_checked;
    bool isMatched = false;

    int array[size];

    cout << "\nEnter the numbers of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            int num_to_be_matched = array[i] + array[j];
            cout << "added no: " << num_to_be_matched << endl;
            if (num_to_be_matched == num_to_checked)
            {
                cout << "\nyes";
                isMatched = true;
                break;
            }
        }
    }

    if (isMatched == false)
    {
        cout << "\nno";
    }

    return 0;
}