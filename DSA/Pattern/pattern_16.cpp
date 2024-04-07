#include<iostream>
using namespace std;

int main() {
    int n = 5;
    char a[5] = {'A', 'B', 'C', 'D', 'E'};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}