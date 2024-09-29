#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class doublylinkedlist
{
private:
    Node *head;

public:
    doublylinkedlist() : head(nullptr) {}

    // traverse the doubly linked list same as singly linked list
    void traversal()
    {
        Node *current = head;
        while (current != nullptr)
        {
            // cout << current->data << " <- ->";
            cout << current->data << " ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    // traverse and returns the count of nodes
    int length()
    {
        Node *current = head;
        int count = 0;
        while (current->next != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    // insert the newnode at the beginning
    void insertAtBeginning(int data)
    {
        Node *newnode = new Node(data);
        newnode->prev = nullptr;
        if (head == nullptr)
        {
            head = newnode;
            return;
        }
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }

    // insert the newnode at end of doubly linked list
    void insertAtEnd(int data)
    {
        Node *newnode = new Node(data);
        newnode->next = nullptr;
        Node *current = head;
        if (head == nullptr)
        {
            head = newnode;
            return;
        }

        while (current->next != nullptr)
        {
            current = current->next;
        }

        newnode->prev = current;
        current->next = newnode;
    }

    void insertAtGivenPosition(int data, int position)
    {
        Node *newNode = new Node(data);

        if (position == 1)
        {
            newNode->next = head;
            newNode->prev = nullptr;
            if (head != nullptr)
            {
                head->prev = newNode;
            }

            head = newNode;
            return;
        }
        int k = 1;
        Node *prev = head;
        while (k < position - 1 && prev->next != nullptr)
        {
            prev = prev->next;
            k++;
        }

        if (k < position - 1)
        {
            cout << "Position doesn't exist!!!" << endl;
            return;
        }

        newNode->next = prev->next;
        newNode->prev = prev;

        if (prev->next != nullptr)
        {
            prev->next->prev = newNode;
        }

        prev->next = newNode;
    }

    Node *findNode(int value)
    {
        Node *current = head;
        while (current != nullptr && value != current->data)
        {
            current = current->next;
        }
        return current;
    }

    void insertAtGivenValue(int data, int value)
    {
        Node *newNode = new Node(data);
        Node *GivenNode = findNode(value);

        if (GivenNode == nullptr)
        {
            cout << "Not Found given node by the dumb user!" << endl;
            return;
        }

        if (GivenNode == head)
        {
            newNode->next = head;
            newNode->prev = nullptr;

            if (head->next != nullptr)
            {
                head->prev = newNode;
            }

            head = newNode;
        }

        newNode->next = GivenNode;
        newNode->prev = GivenNode->prev;

        if (GivenNode->prev != nullptr)
        {
            GivenNode->prev->next = newNode;
        }

        GivenNode->prev = newNode;
    }

    void insertAfterGivenValue(int data, int value)
    {
        Node *newNode = new Node(data);
        Node *GivenNode = findNode(value);

        if (GivenNode == nullptr)
        {
            cout << "Not Found given node by the dumb user!" << endl;
            return;
        }

        newNode->next = GivenNode->next;
        newNode->prev = GivenNode;
        GivenNode->next = newNode;

        if (newNode->next != nullptr)
        {
            newNode->next->prev = newNode;
        }
    }
};

int main()
{
    doublylinkedlist list;

    list.insertAtBeginning(60);
    list.insertAtBeginning(50);
    list.insertAtBeginning(40);
    list.insertAtBeginning(30);
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);
    // list.insertAtGivenPosition(35, 7);
    // list.insertAtGivenValue(35, 40);
    list.insertAfterGivenValue(35, 30);
    list.insertAtEnd(70);

    list.traversal();

    return 0;
}