// BRUTE FORCE SOLUTION
double medianBruteForce(vector<int>& a, vector<int>& b) {
	int n1 = a.size(), n2 = b.size(), i=0, j=0;
	vector<int> c;
	while(i < n1 && j < n2) {
		if (a[i] < b[j]) {
			c.push_back(a[i]);
			i++;
		} else {
			c.push_back(b[j]);
			j++;
		}
	}

	while (i < n1) {
		c.push_back(a[i]);
		i++;
	}

	while(j < n2) {
		c.push_back(b[j]);
		j++;
	}

	int n = n1+n2;
	if(n%2 == 1) {
		return c[n/2];
	} else {
		return (double)((double)(c[n/2]) + (double)(c[(n/2)-1]))/2.0;
	}
}


// BETTER APPROACH
double medianBetterApproach(vector<int>& a, vector<int>& b) {
	int n1 = a.size(), n2 = b.size(), i=0, j=0;
	int n = n1 + n2;
	int idx1 = n/2;
	int idx2 = idx1-1;
	int cnt = 0;
	int idx1Elem = -1, idx2Elem = -1;

	while (i < n1 && j < n2) {
		if(a[i] < b[j]) {
			if(cnt == idx1) idx1Elem = a[i];
			if(cnt == idx2) idx2Elem = a[i];
			cnt++;
			i++;
		} else {
			if(cnt == idx1) idx1Elem = b[j];
			if(cnt == idx2) idx2Elem = b[j];
			cnt++;
			j++;
		}
	}

	while(i<n1) {
		if(cnt == idx1) idx1Elem = a[i];
		if(cnt == idx2) idx2Elem = a[i];
		cnt++;
		i++;
	}

	while(j<n2) {
		if(cnt == idx1) idx1Elem = b[j];
		if(cnt == idx2) idx2Elem = b[j];
		cnt++;
		j++;
	}

	if(n%2 == 1) {
		return idx1Elem;
	} else {
		return (double)((double)(idx1Elem) + (double)(idx2Elem))/2.0;
	}
}