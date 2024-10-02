#include <iostream>
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
};

int main()
{

    return 0;
}