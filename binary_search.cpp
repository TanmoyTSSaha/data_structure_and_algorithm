int binary_search(vector<int> &nums, int low, int high, int target) {
    if (low > high) return -1;
    
    int mid = (low+high)/2;
    if (nums[mid] == target) return mid;
    else if (target > nums[mid]) return binary_search(nums, mid+1, high, target);
    return binary_search(nums, low, high - 1, target);
}

int search(vector<int> &nums, int target) {
    return binary_search(nums, 0, nums.size()-1, target);
}

int lowerBound(vector<int> arr, int n, int x) {
	int low = 0, high = n-1;
	int ans = n;

	while(low <= high) {
		int mid = (low+high)/2;

		if(arr[mid] >= x) {
			ans = mid;
			high = mid-1;
		} else {
			low = mid + 1;
		}
	}

	return ans;
}


int upperBound(vector<int> &arr, int x, int n){
	int low = 0, high = n-1;
	int ans = n;

	while(low <= high) {
		int mid = (low+high)/2;

		if(arr[mid] > x) {
			ans = mid;
			high = mid-1;
		} else {
			low = mid + 1;
		}
	}

	return ans;
}

int searchInsert(vector<int>& arr, int x)
{
	int n = arr.size();
	int low = 0, high = n-1;
	int ans = n;

	while(low <= high) {
		int mid = (low+high)/2;

		if(arr[mid] >= x) {
			ans = mid;
			high = mid-1;
		} else {
			low = mid + 1;
		}
	}

	return ans;
}

double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	vector<int> howMany(n-1, 0);

	for(int gasStations=1; gasStations<=k; gasStations++) {
		long double maxSection = -1;
		int maxInd = -1;

		// WE'LL OPTIMISE THE CODE FOR THIS SECTION.?
		// for(int i=0; i<n-1; i++) {
		// 	long double diff = (arr[i+1]-arr[i]);
		// 	long double sectionLength = diff/(long double)(howMany[i]+1);
			
		// 	if(sectionLength > maxSection) {
		// 		maxSection = sectionLength;
		// 		maxInd = i;
		// 	}
		// }

		howMany[maxInd]++;
	}

	long double maxAns = -1;
	for(int i=0; i<n-1; i++) {
		long double diff = (arr[i+1]-arr[i]);
		long double sectionLength = diff/(long double)(howMany[i]+1);
		maxAns = max(maxAns, sectionLength);
	}

	return maxAns;
}


int main() {
    return 1;
}