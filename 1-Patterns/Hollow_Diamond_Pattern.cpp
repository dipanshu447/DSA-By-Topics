#include <iostream>
using namespace std;

int main()
{

    int n = 0;
    cout << "Enter the number of n !! : " << endl;
    cin >> n;
    cout << "Hollow Diamond pattern :" << endl;

    // top part
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << "*";
        if (i != 0)
        {
            for (int k = 0; k < 2 * i - 1; k++)
            {
                cout << " ";
            }

            cout << "*";
        }
        cout << endl;
    }

    // bottom
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << " ";
        }
        cout << "*";

        if (i != n - 2)
        {
            for (int k = 0; k < 2 * (n - i) - 5; k++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}