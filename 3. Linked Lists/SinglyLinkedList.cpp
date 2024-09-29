#include <iostream>
using namespace std;

// node class
class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};

class linkedList
{
private:
    Node *head;

public:
    linkedList() : head(nullptr) {}

    // function to traverse the singly linked list
    void traversal()
    {
        if (head == nullptr)
        {
            cout << "Linked List is empty or deleted" << endl;
            return;
        }

        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    // function to return the size of linked list
    int length()
    {
        Node *current = head;
        int count = 0;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    // insert value at begining of linked list and also can be used for setting head first
    void insertAtBeginning(int data)
    {
        Node *temp = new Node(data);

        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }

    // insert value at end of linked list and also can be used for setting head first
    void insertAtEnd(int data)
    {
        Node *temp = new Node(data);
        Node *current = head;

        if (current == nullptr)
        {
            head = temp;
        }
        else
        {
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = temp;
        }
    }

    /* Add a node at a given position by the user and it can also add node at the beginning of the list too if user gave head position
    NOTE : it is assumed the head is set already it can't set the head position but it can add node at the beginning of list */
    void insertAtGivenPosition(int data, int position)
    {
        Node *newnode = new Node(data);
        Node *prev = head;

        if (position <= 1)
        {
            newnode->next = head;
            head = newnode;
            return;
        }

        while (--position && prev->next != nullptr)
        {
            prev = prev->next;
        }

        newnode->next = prev->next;
        prev->next = newnode;
    }

    // it finds a node of the given value and return the given value node pointer
    Node *findNode(int value)
    {
        Node *current = head;
        while (current != nullptr && current->data != value)
        {
            current = current->next;
        }
        return current;
    }

    /* Add a node at a given value by the user and it can also add node at the beginning of the list too if user gave head value
    NOTE : it is assumed the head is set already it can't set the head value but it can add node at the beginning of list */
    void insertAtGivenValue(int data, int value)
    {
        Node *newnode = new Node(data);
        Node *prev = head;
        Node *pos = findNode(value);

        if (pos == prev)
        {
            newnode->next = head;
            head = newnode;
            return;
        }

        while (prev->next != pos && prev->next != nullptr)
        {
            prev = prev->next;
        }

        newnode->next = prev->next;
        prev->next = newnode;
    }

    // It adds a node after a given value node and it also can also add node at beginning of list (HEAD SHOULD BE SET ALREADY)
    void insertAfterGivenValue(int data, int value)
    {
        Node *newnode = new Node(data);
        Node *prevNode = findNode(value);

        if (prevNode == head)
        {
            newnode->next = head;
            head = newnode;
            return;
        }

        newnode->next = prevNode->next;
        prevNode->next = newnode;
    }

    // it deletes first node
    void deleteFirstNode()
    {
        Node *temp;
        if (head == nullptr)
        {
            return;
        }
        temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
    }

    // it deletes last node 
    void deleteLastNode()
    {
        if (head == nullptr)
        {
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        

        Node *current = head;
        Node *temp = current->next;
        while (temp->next != nullptr)
        {
            // both of them will work as they both keep the track of prev node
            current = temp;
            // current = current->next;
            temp = temp->next;
        }
        current->next = nullptr;
        delete temp;
        temp = nullptr;     
    }

    // it deletes a node from the given position
    void deleteAtGivenPosition(int position)
    {
        int k = 1;
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *current = head;
        Node *prev;
        if (position == 1)
        {
            head = head->next;
            delete current;
            return;
        }
        else
        {
            while (current != nullptr && k < position)
            {
                k++;
                prev = current;
                current = current->next;
            }

            if (current == nullptr)
            {
                cout << "Position doesnt exist!!" << endl;
                return;
            }
            else
            {
                prev->next = current->next;
                delete current;
            }
            return;
        }
    }

    // it delete the node from the given value by finding that node using findNode()
    void deleteGivenValue(int value)
    {
        Node *prev = head;
        Node *delNode = findNode(value);
        if (delNode == nullptr)
        {
            cout << "Node not found!!" << endl;
            return;
        }
        
        if (delNode == head)
        {
            head = head->next;
            delete delNode;
            return;
        }

        while (prev->next != delNode && prev->next != nullptr)
        {
            prev = prev->next;
        }

        prev->next = delNode->next;
        delete delNode;
    }

    // it delete the nodes which comes after that given value node
    void deleteAfterGivenValue(int value)
    {
        Node *del = head;
        Node *prevNode = findNode(value);

        if (prevNode == nullptr || prevNode->next == nullptr)
        {
            return;
        }

        del = prevNode->next;
        prevNode->next = del->next;
        delete del;
    }

    // it deletes the entire linked list
    void deleteLinkedList()
    {
        Node *del = head;
        while (del != nullptr)
        {
            Node *temp = del;
            del = del->next;
            delete temp;
        }
        head = nullptr;
    }
};

int main()
{
    linkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    // list.insertAtGivenPosition(60, 3);
    list.insertAtGivenValue(60, 40);
    // list.insertAfterGivenValue(60, 40);
    list.traversal();

    // list.deleteFirstNode();
    // list.deleteLastNode();
    // list.deleteAtGivenPosition(1);
    // list.deleteAfterGivenValue(30);
    // list.deleteGivenValue(40);
    // cout << endl;
    // list.traversal();
    // cout << endl;
    // list.deleteLinkedList();

    // list.traversal();
    return 0;
}