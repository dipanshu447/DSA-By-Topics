#include <iostream>
using namespace std;

int main()
{

    int n = 0;
    cout << "Enter the number of n !! : " << endl;
    cin >> n;
    cout << "Reversed Triangle pattern :" << endl;

    // reversed increment character triangle version
    for (int i = 0; i < n; i++)
    {
        char c = 'A' + i;
        for (int j = 0; j <= i; j++)
        {
            cout << c << " ";
            c--;
        }
        cout << endl;
    }

    // // reversed increment number triangle version
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i+1; j > 0; j--)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}