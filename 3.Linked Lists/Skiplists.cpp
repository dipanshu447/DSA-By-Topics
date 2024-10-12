#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

class SkipNode
{
public:
    int data;
    SkipNode **forward; // SkipNode **forward is a pointer to an array of pointers, where the array size can be determined dynamically at runtime,

    SkipNode(int level, int value) : data(value)
    {
        forward = new SkipNode *[level + 1];
        for (int i = 0; i <= level; i++)
        {
            forward[i] = nullptr;
        }
    }
};

class SkipList
{
    int MAX_Level = 0;
    float p;
    int current_lvl;
    SkipNode *header;

public:
    SkipList(int maxLevel, float prob) : MAX_Level(maxLevel), p(prob)
    {
        current_lvl = 0;
        header = new SkipNode(MAX_Level, -1);
    }

    // randomly decides if the node should be promoted to next level or not (basically like flipping a coin)
    int randomLevel()
    {
        int lvl = 0;
        while (((float)rand() / RAND_MAX) < p && lvl < MAX_Level)
        {
            lvl++;
        }
        return lvl;
    }
    // inserts the new elements in skip kist and uses randomLevel() to put nodes to high level using flip a coin like logic
    /* if head came it adds the node to upper level but
        if tail came it adds the node in level 0
    */
    void insert(int data)
    {
        SkipNode *current = header;
        SkipNode *update[MAX_Level + 1];
        for (int i = 0; i <= MAX_Level; i++)
        {
            update[i] = nullptr;
        }

        for (int i = current_lvl; i >= 0; i--)
        {
            while (current->forward[i] != nullptr && current->forward[i]->data < data)
            {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];

        if (current != nullptr && current->data == data)
        {
            cout << data << " already exists in the skip list!" << endl;
            return; // as the data already exists
        }
        int random_level = randomLevel();

        if (random_level > current_lvl)
        {
            for (int i = current_lvl + 1; i <= random_level; i++)
            {
                update[i] = header;
            }
            current_lvl = random_level;
        }

        SkipNode *newNode = new SkipNode(random_level, data);
        for (int i = 0; i <= random_level; i++)
        {
            newNode->forward[i] = update[i]->forward[i]; // points to next node
            update[i]->forward[i] = newNode;             // update previous node to point to new node
        }
        cout << "Inserted " << data << " sucessfully!" << endl;
    }

    // deleteing the element from all levels and updating the current_lvl count
    void deleteElement(int data)
    {
        SkipNode *current = header;
        SkipNode *update[MAX_Level + 1];
        for (int i = 0; i <= MAX_Level; i++)
        {
            update[i] = nullptr;
        }

        for (int i = current_lvl; i >= 0; i--)
        {
            while (current->forward[i] != nullptr && current->forward[i]->data < data)
            {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];

        if (current == nullptr && current->data != data)
        {
            cout << "ELement not found" << endl;
            return;
        }

        for (int i = 0; i <= current_lvl; i++)
        {
            if (update[i]->forward[i] != current)
            {
                break;
            }
            update[i]->forward[i] = current->forward[i];
            /*
            if forward[i] pointer of the nodes stored in update[] matches the current node.If yes then it updates the update[i]->forward[i] to
            skip over the current node and pointer to current->forward[i]
            */
        }

        delete current; // node is deleted from the memory

        // updating the current_lvl count
        while (current_lvl > 0 && header->forward[current_lvl] == nullptr)
        {
            current_lvl--;
        }
    }

    // searches or traverse through levels for a element
    void search(int val)
    {
        SkipNode *current = header;
        for (int i = current_lvl; i >= 0; i--)
        {
            while (current->forward[i] != nullptr && current->forward[i]->data < val)
            {
                current = current->forward[i];
            }
        }

        current = current->forward[0];
        if (current != nullptr && current->data == val)
        {
            cout << "Element found : " << current->data << endl;
        }
        else
        {
            cout << "Not Found!!!" << endl;
            return;
        }
    }

    // traverse through all the levels and print it
    void traversal()
    {
        for (int i = MAX_Level; i >= 0; i--)
        {
            SkipNode *current = header->forward[i];
            cout << "Level " << i << " : ";
            while (current != nullptr)
            {
                cout << current->data << " ";
                current = current->forward[i];
            }
            cout << endl;
        }
    }
};

int main()
{
    srand((unsigned)time(0)); // seed random number generator

    SkipList skiplist(4, 0.5);

    skiplist.insert(3);
    skiplist.insert(9);
    skiplist.insert(10);
    skiplist.insert(12);
    skiplist.insert(15);
    skiplist.insert(16);
    skiplist.insert(18);
    skiplist.insert(19);
    skiplist.insert(22);
    skiplist.insert(30);
    skiplist.insert(40);
    skiplist.insert(66);
    skiplist.insert(77);
    skiplist.insert(88);

    skiplist.traversal();
    // skiplist.search(10);
    skiplist.deleteElement(12);
    skiplist.deleteElement(19);

    skiplist.traversal();

    return 0;
}
