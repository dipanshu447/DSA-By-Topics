// Explanation for this algo : https://www.youtube.com/watch?v=q6RicK1FCUs (paste this link in browser)

#include <iostream>
using namespace std;

// number version of disk
void TowerOfHanoi(int n, int prevRod, int midRod, int topRod)
{
    if (n == 1)
    {
        cout << "Move Disk 1 from rod " << prevRod << " to rod " << topRod << endl;
        return;
    }

    TowerOfHanoi(n - 1, prevRod, topRod, midRod);
    cout << "Move Disk " << n << " from rod " << prevRod << " to rod " << topRod << endl;
    TowerOfHanoi(n - 1, midRod, prevRod, topRod);
}

// character version of disk
void TowerOfHanoiCH(int n, char prevRod, char midRod, char topRod)
{
    if (n == 1)
    {
        cout << "Move Disk 1 from rod " << prevRod << " to rod " << topRod << endl;
        return;
    }

    TowerOfHanoiCH(n - 1, prevRod, topRod, midRod);
    cout << "Move Disk " << n << " from rod " << prevRod << " to rod " << topRod << endl;
    TowerOfHanoiCH(n - 1, midRod, prevRod, topRod);
}

int main()
{
    TowerOfHanoiCH(3,'A','B','C');
    // TowerOfHanoi(3,1,2,3);

    return 0;
}