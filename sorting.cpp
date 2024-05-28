#include <bits/stdc++.h>
using namespace std;

void bubbleSorting(int a[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        bool didSwap = false;
        for (int j = 0; j <= i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                didSwap = true;
            }
        }

        if (!didSwap)
            break;
    }
}

void insertionSorting(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j > 0 && a[j - 1] > a[j]; j--)
        {
            swap(a[j - 1], a[j]);
            cout << "print" << endl;
        }
    }
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;

    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= mid)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSorting(vector<int> &arr, int low, int high)
{
    if (low == high)
        return;
    int mid = (low + high) / 2;
    mergeSorting(arr, low, mid);
    mergeSorting(arr, mid, high);
    merge(arr, low, mid, high);
}

int quickPartition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[high]);
    return j;
}

void quickSorting(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = quickPartition(arr, low, high);
        quickSorting(arr, low, pIndex - 1);
        quickSorting(arr, pIndex + 1, high);
    }
}





int main()
{
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;
    // int a[n];
    cout << "Enter the elements of the array: ";
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];

    vector<int> a;

    int input = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        a.push_back(input);
    }

    quickSorting(a, 0, a.size() - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";

    return 0;
}