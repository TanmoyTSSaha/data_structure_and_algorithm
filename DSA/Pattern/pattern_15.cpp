#include<iostream>
using namespace std;

int main() {
    char a[5] = {'A', 'B', 'C', 'D', 'E'};
    for(int i=0; i<=5; i++) {
        for(int j=0; j<5 - i; j++){
            cout << a[j] << " ";
        }
        cout << endl;
    }
    return 0;
}