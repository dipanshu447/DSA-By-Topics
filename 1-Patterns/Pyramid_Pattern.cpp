#include <iostream>
using namespace std;

int main()
{

    int n = 0;
    cout << "Enter the number of n !! : " << endl;
    cin >> n;
    cout << "Pyramid pattern :" << endl;
    // star version
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }

        for (int k = i; k > 0; k--)
        {
            cout << "*";
        }
        
        cout << endl;
    }
    
    // // number version
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n - i - 1; j++)
    //     {
    //         cout << " ";
    //     }

    //     for (int j = 1; j <= i + 1; j++)
    //     {
    //         cout << j;
    //     }

    //     for (int k = i; k > 0; k--)
    //     {
    //         cout << k;
    //     }
        
    //     cout << endl;
    // }

    return 0;
}