#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Tree
{
private:
    TreeNode *root;

public:
    Tree() : root(nullptr) {}

    void insert(int value)
    {

        TreeNode *newNode = new TreeNode(value);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        TreeNode *current = root;
        TreeNode *prev = nullptr;

        // traverse in the value order
        while (current != nullptr)
        {
            prev = current;
            if (value == current->data)
            {
                return; // cant be insert as its already inserted
            }
            else if (value < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        // after reaching the node which is nullptr we link it to newnode
        if (value < prev->data)
        {
            prev->left = newNode;
        }
        else
        {
            prev->right = newNode;
        }
    }
};

int main()
{
    Tree t;

    t.insert(10);
    t.insert(20);
    t.insert(30);



    return 0;
}