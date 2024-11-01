#include <iostream>
using namespace std;

int main()
{

    int n = 4;
    // cout << "Enter the number of n !! : " << endl;
    // cin >> n;
    // cout << "Butterfly pattern :" << endl;
    // // Top part
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        for (int s = 1; s < 2 * (n - i) - 1; s++)
        {
            cout << " ";
        }

        for (int k = 0; k < i + 1; k++)
        {
            cout << "*";
        }

        cout << endl;
    }

    // Bottom Part
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        if (i != 0)
        {
            for (int j = 0; j < 2 * i; j++)
            {
                cout << " ";
            }
        }
        for (int k = 0; k < n - i; k++)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}