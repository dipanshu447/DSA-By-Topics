#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int data;
    vector<TreeNode *> child;

    TreeNode(int val) : data(val) {}

    void addChild(TreeNode *newchild)
    {
        child.push_back(newchild);
    }

    TreeNode *createTree()
    {
        TreeNode *root = new TreeNode(1);

        TreeNode *child1 = new TreeNode(2);
        TreeNode *child2 = new TreeNode(3);
        TreeNode *child3 = new TreeNode(4);

        root->addChild(child1);
        root->addChild(child2);
        root->addChild(child3);

        TreeNode *child1_1 = new TreeNode(5);
        TreeNode *child1_2 = new TreeNode(6);
        TreeNode *child1_3 = new TreeNode(7);

        child1->addChild(child1_1);
        child1->addChild(child1_2);
        child1->addChild(child1_3);

        return root;
    }

    void preorder(TreeNode *Root)
    {
        stack<TreeNode *> Stack;

        Stack.push(Root);
        while (!Stack.empty())
        {
            TreeNode *temp = Stack.top();
            Stack.pop();

            cout << temp->data << " ";

            for (int i = temp->child.size() - 1; i >= 0; i--)
            {
                Stack.push(temp->child[i]);
            }
        }
    }

    void inOrder(TreeNode *Root)
    {
        if (Root == nullptr)
        {
            return;
        }

        int n = Root->child.size();
        for (int i = 0; i < n - 1; i++)
        {
            inOrder(Root->child[i]);
        }

        cout << Root->data << " ";
        if (n > 0)
        {
            inOrder(Root->child[n - 1]);
        }
    }
};

int main()
{

    TreeNode *r = new TreeNode(0);
    TreeNode *t = r->createTree();
    //         1
    //      /  |  \
    //     2   3   4
    //   / | \
    //  5  6  7
    // r->preorder(t);
    r->inOrder(t);
    return 0;
}