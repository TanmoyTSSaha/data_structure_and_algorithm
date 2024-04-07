#include <iostream>
using namespace std;

int main()
{
    int n = 4;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        for (int j = 1; j <= (2 * n) - (2 * i); j++)
        {
            cout << " "
                 << " ";
        }
        for (int j = i; j > 0; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}

/*

1 * * * * * * 1 -> [1, 6, 1]
1 2 * * * * 2 1 -> [2, 4, 2]
1 2 3 * * 3 2 1 -> [3, 2, 3]
1 2 3 4 4 3 2 1 -> [4, 0, 4]

*/