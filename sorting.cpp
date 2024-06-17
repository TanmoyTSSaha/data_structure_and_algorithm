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

vector<int> superiorElementsOptimal(vector<int>&a) {
    int n = a.size();
    vector<int> ldr;
    int maxNo = INT_MIN;
    for (int i = n-1; i >= 0; i--) {
        if(a[i] > maxNo) {
            ldr.push_back(a[i]);
            maxNo=a[i];
        }
    }
    sort(ldr.begin(), ldr.end());
    return ldr;
}

int longestSuccessiveElementsBruteforce(vector<int> &a) {
  // O(n^3)
  int longestConsecutiveArr = 1;
  int n = a.size();
  sort(a.begin(), a.end());

  for (int i = 0; i < n; i++) {
    int consecutiveArrCount = 1;
    int consecutiveNumber = a[i];
    for (int j = 0; j < n; j++) {
      if (a[j] == consecutiveNumber + 1) {
        consecutiveNumber++;
        consecutiveArrCount++;
      }
    }
    if (longestConsecutiveArr < consecutiveArrCount) {
      longestConsecutiveArr = consecutiveArrCount;
    }
  }

  return longestConsecutiveArr;
}

int longestSuccessiveElementsBetter(vector<int> &a) {
  int longestConsecutiveArr = 1;
  int last_smaller = INT_MIN;
  int n = a.size();
  sort(a.begin(), a.end());

  int consecutiveCount = 1;
  for (int i = 0; i < n; i++) {
    if(a[i]-1 == last_smaller) {
      consecutiveCount++;
      last_smaller=a[i];
    } else if(a[i] != last_smaller) {
        consecutiveCount=1;
        last_smaller=a[i];
    }
    longestConsecutiveArr=max(longestConsecutiveArr,consecutiveCount);
  }

  return longestConsecutiveArr;
}

int longestSuccessiveElementsOptimal(vector<int> &a) {
  int longestConsecutiveArr = 1;
  int n = a.size();
  if (n == 0) return 0;
  int last_smaller = INT_MIN;
  unordered_set<int> st;

  for(int i=0; i<n; i++) {
    st.insert(a[i]);
  }

  for (auto it : st) {
    if(st.find(it-1) == st.end()) {
      int cnt = 1;
      int x = it;
      while(st.find(x+1) != st.end()) {
        x = x+1;
        cnt = cnt+1;
      }
      longestConsecutiveArr = max(longestConsecutiveArr, cnt);
    }
  }

  return longestConsecutiveArr;
}

void markRow(vector<vector<int>> &matrix, int m, int i) {
	for(int j=0; j<m; j++) {
		if(matrix[i][j] != 0) {
			matrix[i][j] = -1;
		}
	}
}

void markCol(vector<vector<int>> &matrix, int n, int j) {
	for(int i=0; i<n; i++) {
		if(matrix[i][j] != 0) {
			matrix[i][j] = -1;
		}
	}
}

vector<vector<int>> zeroMatrixBruteforce(vector<vector<int>> &matrix, int n, int m) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(matrix[i][j] == 0) {
				markRow(matrix, m, i);
				markCol(matrix, n, j);
			}
		}
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(matrix[i][j]==-1) {
				matrix[i][j] = 0;
			}
		}
	}

	return matrix;
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