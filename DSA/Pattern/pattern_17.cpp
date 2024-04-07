#include<iostream>
using namespace std;

int main() {
    int n = 5;
    for(int i=0; i<n; i++) {
        for(int j=(n-i-1); j>=0; j--){
            cout << " " << " ";
        }

        char ch = 'A';
        int breakpoint = (2*i+1)/2;
        for(int j=0; j<(2*i+1); j++){
            cout << ch<< " ";
            if (j < breakpoint) ch++;
            else ch--;
        }

        for(int j=(n-i-1); j>=0; j--){
            cout << " " << " ";
        }
        cout << endl;
    }
    return 0;
}


/*

1 2 3 4 * 4 3 2 1   [4,1,4]
1 2 3 * * * 3 2 1   [3,3,3]
1 2 * * * * * 2 1   [2,5,2]
1 * * * * * * * 1   [1,7,1]
* * * * * * * * *   [0,9,0]

*/