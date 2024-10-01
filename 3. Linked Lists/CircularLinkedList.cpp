#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};

class circularLinkedList
{
private:
    Node *head;

public:
    circularLinkedList() : head(nullptr) {}

    // traversal through the circular linked list
    void traversal()
    {
        Node *current = head;

        if (current == nullptr)
        {
            cout << "Circular Linked List is empty!" << endl;
            return;
        }

        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
    }

    // returns lenght of the ciruclar linked list by traversing
    int length()
    {
        Node *current = head;
        int count = 0;
        if (current == nullptr)
        {
            cout << "Circular Linked List is empty!" << endl;
            return 0;
        }

        do
        {
            current = current->next;
            count++;
        } while (current != head);

        return count;
    }

    // it inserts a node in a empty circular linked list
    void insertAtEmptyList(int data)
    {
        Node *newNode = new Node(data);

        newNode->next = newNode;

        head = newNode;
        return;
    }

    // it inserts a node at the end of circular linked list
    void insertAtEnd(int data)
    {
        Node *current = head;
        Node *newNode = new Node(data);

        if (newNode == nullptr)
            return;

        newNode->next = newNode;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        else
        {
            while (current->next != head)
                current = current->next;

            current->next = newNode;
            newNode->next = head;
        }
    }

    // it inserts a node at beginning of circular linked list
    void insertAtBeginning(int data)
    {
        Node *current = head;
        Node *newNode = new Node(data);

        if (current == nullptr)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        newNode->next = newNode;

        while (current->next != head)
            current = current->next;

        newNode->next = head;
        current->next = newNode;
        head = newNode;
    }

    // it inserts a node at the specific position given by user
    void insertAtPosition(int data, int pos)
    {
        Node *current = head;
        Node *newNode = new Node(data);
        int k = 1;

        if (head == nullptr)
        {
            if (pos != 1)
            {
                cout << "Invalid Position!" << endl;
                return;
            }

            head = newNode;
            newNode->next = head;
            return;
        }

        if (pos == 1)
        {
            insertAtBeginning(data);
            return;
        }

        while (k < pos - 1 && current->next != head)
        {
            current = current->next;
            k++;
        }

        if (k != pos - 1)
        {
            cout << "Invalid Position!" << endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;

        if (current->next == head)
        {
            newNode = head;
            return;
        }
    }

    // it inserts a node after the specific postion given node
    void insertAfterGivenPosition(int data, int pos)
    {
        Node *current = head;
        Node *newNode = new Node(data);
        int k = 1;

        if (head == nullptr)
        {
            if (pos != 1)
            {
                cout << "Invalid Position!" << endl;
                return;
            }

            head = newNode;
            newNode->next = head;
            return;
        }

        if (pos == 1)
        {
            Node *posNode = current->next;
            newNode->next = posNode;
            current->next = newNode;
            return;
        }

        while (k < pos && current->next != head)
        {
            current = current->next;
            k++;
        }

        if (k < pos)
        {
            cout << "Invalid Position!" << endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
    // Note : we can apply findNode(), insertAtValue is pretty much same like these all functions
};

int main()
{
    circularLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtBeginning(5);
    list.insertAtBeginning(3);
    // list.insertAtPosition(45, 7);
    list.insertAfterGivenPosition(45,2);
    // list.insertAtEmptyList(10);
    // list.insertAtEmptyList(20);
    // list.insertAtEmptyList(40);

    list.traversal();

    return 0;
}