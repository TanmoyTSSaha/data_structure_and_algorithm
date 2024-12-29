#include<bits/stdc++.h>

// OPTIMAL SOLUTION USING BINARY SEARCH: NEW PATTERN IN BINARY SEARCH
int numberOfGasStationRequired(long double dist, vector<int> &arr) {
	int cnt = 0;
	for (int i = 1; i < arr.size(); i++) {
		int numberInBetween = ((arr[i] - arr[i-1]) / dist);

		if((arr[i] - arr[i-1]) / dist == numberInBetween * dist) {
			numberInBetween--;
		}

		cnt += numberInBetween;
	}

	return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	long double low = 0;
	long double high = 0;

	for (int i = 0; i < n - 1; i++) {
		high = max(high, (long double)(arr[i+1] - arr[i]));
	}

	long double diff = 1e-6;

	while(high-low > diff) {
		long double mid = (low+high) / (2.0);
		int cnt = numberOfGasStationRequired(mid, arr);
		if(cnt > k) {
			low = mid;
		} else {
			high = mid;
		}
	}

	return high;
}


// BETTER SOLUTION
double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	vector<int> howMany(n-1, 0);
	priority_queue<pair<long double, int>> pq;

	for(int i=0; i<n-1; i++) {
		pq.push({arr[i+1]-arr[i], i});
	}

	for (int gasStations = 1; gasStations <= k; gasStations++) {
		auto tp = pq.top(); pq.pop();
		int secIdx = tp.second;
		
		howMany[secIdx]++;

		long double iniDiff = arr[secIdx + 1] - arr[secIdx];
		long double newSecLen = iniDiff / (long double)(howMany[secIdx]+1);

		pq.push({newSecLen, secIdx});
	}

	return pq.top().first;
}


// BRUTE FORCE SOLUTION: EXCETION TLE
double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	vector<int> howMany(n-1, 0);

	for (int gasStations = 1; gasStations <= k; gasStations++) {
		long double maxSection = -1;
		int maxIdx = -1;

		for (int i = 0; i < n - 1; i++) {
			long double diff = (arr[i+1] - arr[i]);
			long double sectionLength = diff / (long double)(howMany[i]+1);

			if(sectionLength > maxSection) {
				maxSection = sectionLength;
				maxIdx = i;
			}
		}

		howMany[maxIdx]++;
	}

	long double maxAns = -1;

	for(int i=0; i<n-1; i++) {
		long double diff = (arr[i+1] - arr[i]);
		long double sectionLength = diff / (long double)(howMany[i]+1);

		maxAns = max(maxAns, sectionLength);
	}

	return maxAns;
}





int main() {
    return 1;
}