#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int> arr, int n)
{
    int largest = arr[0];
    int sLargest = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > sLargest)
        {
            sLargest = arr[i];
        }
    }

    return sLargest;
}

int secondSmallest(vector<int> arr, int n)
{
    int smallest = arr[0];
    int sSmallest = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
        else if (arr[i] < sSmallest && smallest < sSmallest)
        {
            sSmallest = arr[i];
        }
    }
    return sSmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> arr)
{
    int sLargest = secondLargest(arr, n);
    int sSmallest = secondSmallest(arr, n);
    vector<int> x;
    x.push_back(sLargest);
    x.push_back(sSmallest);
    return x;
}

int removeDuplicates(vector<int> &nums)
{
    vector<int> nonDupeArr;

    cout << "Array at 0th index: " << nums[0] << endl;

    nonDupeArr.push_back(nums[0]);
    for (int i = 1; i <= nums.size(); i++)
    {
        if (nums[i] > nums[i - 1])
        {
            nonDupeArr.push_back(nums[i]);
        }
        else
        {
            continue;
        }
    }

    for (int i = 0; i < nonDupeArr.size(); i++)
    {
        cout << nonDupeArr[i] << " ";
    }

    cout << endl;

    return nonDupeArr.size();
}

vector<int> removeZerosToTheEnd(vector<int> arr, int n)
{
    vector<int> nonZeroArr;
    for (int i = 0; i < n; i++)
    { // -> O(n)
        if (arr[i] != 0)
        {
            nonZeroArr.push_back(arr[i]);
        }
    }

    for (int i = 0; i < nonZeroArr.size(); i++)
    { // -> O(x)
        arr[i] = nonZeroArr[i];
    }

    for (int i = nonZeroArr.size(); i < arr.size(); i++)
    { // -> O(n-x)
        arr[i] = 0;
    }

    return arr; // -> O(n) + O(x) + O(n-x) -> O(2n)
}

vector<int> removeZerosToTheEndOptimized(vector<int> arr, int n)
{
    int j = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
        return arr;

    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    return arr;
}

int linearSearch(int n, int num, vector<int> &arr)
{
    int idx = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            idx = i;
            break;
        }
    }

    return idx;
}

// vector<int> unionArrayBruteforce(vector<int> arr1, vector<int> arr2)
// {
//     set<int> unionedSet;
//     for (int i = 0; i < arr1.size(); i++)
//     {
//         unionedSet.insert(arr1[i]);
//     }

//     for (int i = 0; i < arr2.size(); i++)
//     {
//         unionedSet.insert(arr2[i]);
//     }

//     vector<int> unionedArr;
//     for (auto it : unionedSet)
//     {
//         unionedArr.push_back(it);
//     }

//     return unionedArr;
// }

vector<int> unionArrayOptimized2Pointer(vector<int> arr1, vector<int> arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0;
    int j = 0;
    vector<int> unionArray;

    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (unionArray.size() == 0 || unionArray.back() != arr1[i])
            {
                unionArray.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (unionArray.size() == 0 || unionArray.back() != arr2[j])
            {
                unionArray.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (j < n2)
    {
        if (unionArray.size() == 0 || unionArray.back() != arr2[j])
        {
            unionArray.push_back(arr2[j]);
        }
        j++;
    }

    while (i < n1)
    {
        if (unionArray.size() == 0 || unionArray.back() != arr1[i])
        {
            unionArray.push_back(arr1[i]);
        }
        i++;
    }

    return unionArray;
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

vector<int> quickSorting(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = quickPartition(arr, low, high);
        quickSorting(arr, low, pIndex - 1);
        quickSorting(arr, pIndex + 1, high);
    }

    return arr;
}

int missingNumberBruteforce(vector<int> a, int n)
{
    int i;

    for (i = 1; i <= n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (a[j] == i)
            {
                break;
                return i;
            }
            
        }
        
    }
    

    return i;
    
}

int missingNumberOptimalSum(vector<int> &a, int N) {
  int expectedSum = (N*(N+1))/2;
  int actualSum = 0;
  for(int i = 0; i < a.size(); i++) {
      actualSum+=a[i];
  }

    return expectedSum-actualSum;
  
}

int missingNumberOptimalXOR(vector<int> &a, int N) {
  int xor1 = 0;
  int xor2 = 0;
  for(int i = 1; i <= N; i++) {
    xor1 = xor1 ^ i;
  }

  for(int i = 0; i < a.size(); i++) {
    xor2 = xor2 ^ a[i];
  }

  return xor1 ^ xor2;
  
}

int missingNumberHashing(vector<int> &a, int N)
{
    int hashArr[N];

  for (int i = 1; i <= N; i++) {
    hashArr[i] = 0;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < a.size(); j++) {
      if (a[j] == i) {
        hashArr[i] = 1;
        break;
      }
    }
  }

  int missingNum;

  for (int i = 1; i <= N; i++) {
    if (hashArr[i] == 0) {
      missingNum = i;
      break;
    }
  }

  return missingNum;
    
}

int consecutiveOnes(vector<int>& arr){
    vector<int> consecutiveNo;
    int stNum = 1;
    for(int i = 1; i <= arr.size(); i++) {
        if(arr[i] == arr[i-1] && arr[i] == 1) {
            stNum++;
        } else {
            consecutiveNo.push_back(stNum);
            stNum = 1;
        }
    }

    int maxConsecutive = 0;

    for(int i = 0; i < consecutiveNo.size(); i++) {
        if (consecutiveNo[i] > maxConsecutive) {
            maxConsecutive = consecutiveNo[i];
        }
    }

    return maxConsecutive;
}

int consecutiveOnesOptimal(vector<int>& arr){
    int cnt = 0;
    int maxConsecutive = 0;

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == 1) {
            cnt++;
            maxConsecutive = max(maxConsecutive, cnt);
        } else {
            cnt = 0;
        }
    }

    return maxConsecutive;
}

int getSingleElementOptimised(vector<int> &arr){
	int xor1 = 0;

	for(int i = 0; i < arr.size(); i++) {
		xor1 = xor1 ^ arr[i];
	}

	return xor1;
}

int getSingleElementBruteforce(vector<int> &arr){
	for(int i = 0; i < arr.size(); i++) {
		int num = arr[i];
		int cnt = 0;
		for(int j = 0; j < arr.size(); j++) {
			if(arr[j] == num) {
				cnt++;
			}
		}

		if(cnt == 1) {
			return num;
		}
	}
}

int getLongestSubarray(vector<int>& a, int k){
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for(int i = 0; i < a.size(); i++) {
        sum += a[i];
        if(sum == k) {
            maxLen = max(maxLen, i+1);
        }
        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if(preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int longestSubarrayWithSumK(vector<int> a, long long k) {
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for(int i = 0; i < a.size(); i++) {
        sum += a[i];
        if(sum == k) {
            maxLen = max(maxLen, i+1);
        }
        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if(preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

string twoSumBruteforce(int n, vector<int> book, int target)
{
    for(int i = 0; i <n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (book[i]+book[j] == target) return "YES";
        }
    }

    return "NO";
}

string twoSumBruteforce2(int n, vector<int> book, int target)
{
    for(int i = 0; i <n; i++) {
        for (int j = i+1; j < n; j++) {
            // if (i == j) continue;
            if (book[i]+book[j] == target) return "YES";
        }
    }

    return "NO";
}

string twoSumBetter(int n, vector<int> book, int target)
{
    map <int, int> mpp;
    for(int i = 0; i <n; i++) {
        int numReq = target - book[i];
        if(mpp.find(numReq) != mpp.end()) {
            return "YES";
        }
        mpp[book[i]] = i;
    }

    return "NO";
}


string twoSumOptimal(int n, vector<int> book, int target)
{
    int left = 0, right = n-1;
    sort(book.begin(), book.end());

    while(left < right) {
        int sum = book[left] + book[right];

        if(sum==target) return "YES";
        else if (sum < target) left++;
        else right --;
    }

    return "NO";
}

void sortArrayBetter(vector<int>& arr, int n)
{
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0) cnt0++;
        else if (arr[i] == 1) cnt1++;
        else cnt2++;
    }

    for (int i = 0; i < cnt0; i++) {
        arr[i] = 0;
    }
    for (int i = cnt0; i < cnt0+cnt1; i++) {
        arr[i] = 1;
    }
    for (int i = cnt0+cnt1; i < cnt0+cnt1+cnt2; i++) {
        arr[i] = 2;
    }
}

void sortArrayOptimal(vector<int> &arr, int n) {
  int low = 0, mid = 0, high = n - 1;

  while (mid <= high) {
    if (arr[mid] == 0) {
      swap(arr[low], arr[mid]);
      low++;
      mid++;
    } else if (arr[mid] == 1) {
      mid++;
    } else {
      swap(arr[high], arr[mid]);
      high--;
    }
  }
}

int majorityElementBruteforce(vector<int> v) {
	int n = v.size();
	for(int i = 0; i < n; i++) {
		int count = 0;
		for(int j = 0; j < n; j++) {
			if(v[j] == v[i]) {
				count++;
			}

			if(count > n/2) return v[i];
		}
	}

	return -1;
}

int majorityElementBetter(vector<int> v) {
	map<int,int> mpp;
	for(int i = 0; i < v.size(); i++) {
		mpp[v[i]]++;
	}

	for(auto it: mpp) {
		if(it.second > v.size()/2) {
			return it.first;
		}
	}

	return -1;
}

int majorityElementOptimised(vector<int> v) {
  int cnt = 0;
  int el;
  for (int i = 0; i < v.size(); i++) {
    if (cnt == 0) {
      cnt = 1;
      el = v[i];
    } else if (v[i] == el) {
      cnt++;
    } else {
      cnt--;
    }
  }
  int cnt1 = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == el)
      cnt1++;
  }

  if (cnt1 > (v.size() / 2))
    return el;

  return -1;
}

long long maxSubarraySumBruteforce(vector<int> arr, int n)
{
    int maxNo = INT_MIN;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int sum = 0;
            for(int k = i; k <= j; k++) {
                sum+= arr[k];
                maxNo = max(sum, maxNo);
            }
        }
    }
    return maxNo < 0 ? 0 : maxNo;
}

long long maxSubarraySumOptimized(vector<int> arr, int n)
{
    long long sum = 0, maxNo = LONG_MIN;
    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum > maxNo) {
            maxNo = sum;
        }

        if (sum < 0) {
            sum = 0;
        }
    }
    return maxNo < 0 ? 0 : maxNo;
}

int maximumProfit(vector<int> &prices){
    int mini = prices[0];
    int maxProfit = 0;
    int n = prices.size();
    
    for(int i = 1; i<n; i++) {
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }

    return maxProfit;
}

vector<int> alternateNumbersOptimalWithBetterTimeComplexity(vector<int>&a) {
    int n = a.size();
    vector<int> ans(n,0);
    int posIndex = 0, negIndex = 1;

    for(int i=0; i<n; i++) {
        if(a[i] < 0) {
            ans[negIndex] = a[i];
            negIndex+=2;
        } else {
            ans[posIndex] = a[i];
            posIndex+=2;
        }
    }

    return ans;
}

vector<int> alternateNumbersBruteforce(vector<int>&a) {
    vector<int> pos;
    vector<int> neg;

    for(int i=0; i<a.size(); i++) {
        if(a[i]>0) {
            pos.push_back(a[i]);
        } 
        else if (a[i] < 0) {
            neg.push_back(a[i]);
        }
    }

    int finalNum[a.size()];

    for(int i=0; i<a.size()/2; i++) {
        finalNum[2*i]=pos[i];
        finalNum[2*i+1]=neg[i];
    }

    vector<int> vectArr;

    for(int i=0; i<a.size(); i++) {
        vectArr.push_back(finalNum[i]);
    }

    return vectArr;
}

vector<int> nextGreaterPermutationUsingSTLBetterSol(vector<int> &A) {
    next_permutation(A.begin(), A.end());
    return A;
}

vector<int> nextGreaterPermutation(vector<int> &A) {
    int ind = -1;
    int n = A.size();
    
    for(int i=n-2; i>=0; i--) {
        if(A[i] <= A[i+1]) {
            ind = i;
            break;
        }
    }
    if(ind == -1) {
        reverse(A.begin(), A.end());
        return A;
    }

    for(int i=n-1; i>ind; i--) {
        if(A[i]>A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    reverse(A.begin() + ind + 1, A.end());
    
    return A;
}

int main()
{
    vector<int> arr1;

    for (int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        arr1.push_back(x);
    }

    int b;
    b = missingNumberBruteforce(arr1, 5);

    // cout << "Resultant Array: ";
    // // cout << "Size of the unique array is: " << b;
    // for (int i = 0; i < b.size(); i++)
    // {
    //     cout << b[i] << " ";
    // }

    // int idx = linearSearch(n,num , a);

    cout << "The missing number is: " << b;

    return 0;
}