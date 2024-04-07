#include<iostream>

using namespace std;

int main() {
    int m;
    int n;

    cin >> m >> n;
    
    int matrix_array[m][n];

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> matrix_array[i][j];
        }
    }

    int min_array[m];
    int min_no;

    for(int i=0; i<m; i++) {
        min_no = matrix_array[i][0];
        for(int j=0; j<n; j++) {
            if (min_no > matrix_array[i][j]) {
                min_no = matrix_array[i][j];
            }
        }
        min_array[i] = min_no;
    }

    int added_no = 0;

    for(int i=0; i<m; i++) {
        added_no += min_array[i];
    }

    cout << added_no;

    return 0;
}