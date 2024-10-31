#include <iostream>
using namespace std;

int main(){
    
    int n = 0;
    cout << "Enter the number of n on how long square pattern you want!! : " << endl;
    cin >> n;
    cout << "Square pattern :" << endl;
    // characters goes on with pattern instead of repeating
    char c = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << c;
            c++;    
        }
        cout << endl;
    }
    
    // // number is not repeated instead it goes increment on with pattern
    // int num = 1;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << num << " ";
    //         num++;    
    //     }
    //     cout << endl;
    // }
    

    // // so basically we are taking advatage of ASCII values here so A is 65 in ascii value so if we increment it we get 66 which converts to B cause its char variable and 66 in ascii value is B
    // for (int i = 1; i <= n; i++)
    // {   
    //     char c = 'A'; // making the char = A cause we want our line to start from A always
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << c;
    //         c++;
    //     }
         
    //     cout << endl;
    // }
    
    // // print * in a square pattern
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    
    // using array to do ABCD pattern
    // char arr[] = {'A','B','C','D'};
    // cout << "Square pattern :" << endl;
    // for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    // {
    //     for (int j = 0; j < (sizeof(arr) / sizeof(arr[0])); j++)
    //     {
    //         cout << arr[j];
    //     }
    //     cout << endl;
    // }

    return 0;
}