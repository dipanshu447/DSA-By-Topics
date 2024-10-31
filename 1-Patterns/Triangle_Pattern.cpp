#include <iostream>
using namespace std;

int main()
{

    int n = 0;
    cout << "Enter the number of n !! : " << endl;
    cin >> n;
    cout << "Triangle pattern :" << endl;

    // // number increment triangle version
    // for (int i = 1; i <= n; i++)
    // {
    //     // int num = 1;
    //     for (int j = 1; j < i + 1; j++)
    //     {
    //         cout << j << " ";
    //         // cout << num << " ";
    //         // num++;
    //     }
    //     cout << endl;
    // }

    // // Floyd's character triangle version
    // char c = 'A';
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j < i + 1; j++)
    //     {
    //         cout << c << " ";
    //         c++;
    //     }
    //     cout << endl;
    // }

    // // repeated character triangle version
    // char c = 'A';
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j < i + 1; j++)
    //     {
    //         cout << c << " ";
    //     }
    //     c++;
    //     cout << endl;
    // }

    // // Floyd's Triangle Pattern
    // int num = 1;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j < i+1; j++)
    //     {
    //         cout << num << " ";
    //         num++;
    //     }
    //     cout << endl;
    // }

    // // repeated number triangle version
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j < i+1; j++)
    //     {
    //         cout << i;
    //     }
    //     cout << endl;
    // }

    // // * triangle version
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i+1; j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    return 0;
}