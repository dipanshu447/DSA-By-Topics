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

    // void insertAtGivenPosition(int data, int position){
    //     Node *newNode = new Node(data);
    // }
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
    list.insertAtEnd(70);

    list.traversal();

    return 0;
}