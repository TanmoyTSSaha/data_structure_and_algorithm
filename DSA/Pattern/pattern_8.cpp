#include<iostream>
using namespace std;

int main() {
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            cout << " " << " ";
        }
        for (int j = i; j < 2 * n - i - 1; j++)
        {
            cout << "*" << " ";
        }
        for (int j = i; j > 0; j--)
        {
            cout << " " << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*

* * * * * * * * *   [0,9,0]
  * * * * * * *     [1,7,1]
    * * * * *       [2,5,2]
      * * *         [3,3,3]
        *           [4,1,4]

*/