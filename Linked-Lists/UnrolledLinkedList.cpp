#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// unrolled linked list node structure
class Node
{
public:
    int numSize;
    int *arr;
    Node *next;

    Node(int size) : numSize(0), arr(new int[size]), next(nullptr) {}
};

// main class of this unroll linked list
class unrollLinkedList
{
private:
    Node *start;
    Node *end;
    int size_arr;
    int numOfNode;

public:
    unrollLinkedList(int size) : start(nullptr), end(nullptr), size_arr(size + 1), numOfNode(0) {}

    // traversing through the unrolled linked list elements
    void traversal()
    {
        Node *current = start;

        while (current != nullptr)
        {
            for (int i = 0; i < current->numSize; i++)
            {
                cout << current->arr[i] << " ";
            }
            cout << " -> ";
            current = current->next;
        }
    }
    // inserts elements in the linked list
    void insert(int num)
    {

        numOfNode++;

        if (start == nullptr)
        {
            start = new Node(size_arr);
            start->arr[0] = num;
            start->numSize++;
            end = start;
        }

        if (end->numSize + 1 < size_arr)
        {
            end->arr[end->numSize] = num;
            end->numSize++;
        }
        else
        {
            Node *newNode = new Node(size_arr);
            int j = 0;
            for (int i = end->numSize / 2 + 1; i < end->numSize; i++)
            {
                newNode->arr[j++] = end->arr[i];
            }

            newNode->arr[j++] = num;
            newNode->numSize = j;
            end->numSize = end->numSize / 2 + 1;
            end->next = newNode;
            end = newNode;
        }
    }

    // deleting a element in a unrolled list (Note : It deletes a element only it cant delete a node!!! For now I made this as I have no need of removing a node I just wanna remove a element)
    void deleteElement(int value)
    {
        Node *current = start;
        int index = 0;
        while (current != nullptr)
        {
            for (int i = 0; i < current->numSize; i++)
            {
                if (value == current->arr[i])
                {
                    index = i;

                    if (index < 0 || index >= current->numSize)
                    {
                        cout << "Index out of bound!!" << endl;
                        return;
                    }

                    for (int i = index; i < current->numSize; i++)
                    {
                        current->arr[i] = current->arr[i + 1];
                    }
                    current->numSize--;
                }
            }

            current = current->next;
        }
    }
};

int main()
{
    // srand(time(0));
    unrollLinkedList list(5);
    int random;
    for (int i = 0; i < 9; i++)
    {
        // random = rand() % 100;
        cin >> random;
        list.insert(random);
    }
    list.traversal();
    int del;
    cin >> del;
    list.deleteElement(del);
    cout << "After DELETE" << endl;
    list.traversal();

    return 0;
}