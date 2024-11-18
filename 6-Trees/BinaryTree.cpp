#include <iostream>
#include <stack>
#include <queue>
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

    // void pre(TreeNode *rootNode){
    //     if (rootNode != nullptr)
    //     {
    //         cout << rootNode->data << " ";
    //         pre(rootNode->left);
    //         pre(rootNode->right);
    //     }
    // }

public:
    Tree() : root(nullptr) {}

    TreeNode *createNode(int data)
    {
        TreeNode *newNode = new TreeNode(data);
        return newNode;
    }

    void pre(TreeNode *rootNode)
    {
        if (rootNode != nullptr)
        {
            cout << rootNode->data << " ";
            pre(rootNode->left);
            pre(rootNode->right);
        }
    }

    // void preOrder(){
    //     pre(root);
    // }

    void inOrd(TreeNode *rootNode)
    {
        if (rootNode != nullptr)
        {
            inOrd(rootNode->left);
            cout << rootNode->data << " ";
            inOrd(rootNode->right);
        }
    }

    void post(TreeNode *rootNode)
    {
        if (rootNode != nullptr)
        {
            post(rootNode->left);
            post(rootNode->right);
            cout << rootNode->data << " ";
        }
    }

    void nonrecPost(TreeNode *Rootnode)
    {
        stack<TreeNode *> s;          // stack will store treenode pointers
        TreeNode *previous = nullptr; // track previous nodes
        do                            // runs till stack is not empty
        {
            while (Rootnode != nullptr)
            {
                s.push(Rootnode);          // push that rootnode into stack to later loop through that for its other sub trees
                Rootnode = Rootnode->left; // root goes to left subtrees
            }
            while (Rootnode == nullptr && !s.empty()) // processes the tree nodes
            {
                Rootnode = s.top();                                            // pop subtree from stack
                if (Rootnode->right == nullptr || Rootnode->right == previous) // check if the right substree is already processed or empty
                {
                    cout << Rootnode->data << " "; // print node data
                    s.pop();
                    previous = Rootnode; // update previous
                    Rootnode = nullptr;  // make rootnode null in order to make sure the loop runs next iterations
                }
                else
                {
                    Rootnode = Rootnode->right; // root goes to to its right subtrees
                }
            }

        } while (!s.empty()); // continue till stack is empty
    }

    void nonrecInOrd(TreeNode *Rootnode)
    {
        stack<TreeNode *> s; // stack will store treenode pointers
        while (true)
        {
            while (Rootnode != nullptr)
            {
                s.push(Rootnode);          // push that rootnode into stack to later loop through that for its other sub trees
                Rootnode = Rootnode->left; // root goes to left subtrees
            }
            if (s.empty()) // if stack is empty then it means we have checked all the root subtrees so it breaks the loop
            {
                break;
            }
            Rootnode = s.top(); // pop the sub tree node to loop through
            s.pop();
            cout << Rootnode->data << " "; // print rootnode data
            Rootnode = Rootnode->right;    // root goes to to its right subtrees
        }
    }

    void nonrecPre(TreeNode *Rootnode)
    {
        stack<TreeNode *> s; // stack will store treenode pointers
        while (true)
        {
            while (Rootnode != nullptr)
            {
                cout << Rootnode->data << " "; // print rootnode data
                s.push(Rootnode);              // push that rootnode into stack to later loop through that for its other sub trees
                Rootnode = Rootnode->left;     // root goes to left subtrees
            }
            if (s.empty()) // if stack is empty then it means we have checked all the root subtrees so it breaks the loop
            {
                break;
            }
            Rootnode = s.top(); // pop the sub tree node to loop through
            s.pop();
            Rootnode = Rootnode->right; // root goes to to its right subtrees
        }
    }

    // do Level order Traversal
    void lvlOrder(TreeNode *RootNode)
    {
        if (RootNode == nullptr)
        {
            return;
        }
        queue<TreeNode *> Queue;
        TreeNode *temp;
        Queue.push(RootNode);
        while (!Queue.empty())
        {
            temp = Queue.front();
            Queue.pop();
            cout << temp->data << " ";
            if (temp->left != nullptr)
            {
                Queue.push(temp->left);
            }
            if (temp->right != nullptr)
            {
                Queue.push(temp->right);
            }
        }
    }
};

int main()
{
    Tree t;
    // treeeeeeee
    //    10
    //   /  \ 
    //  20  30
    //  /
    // 40

    TreeNode *n1 = t.createNode(10);
    TreeNode *n2 = t.createNode(20);
    TreeNode *n3 = t.createNode(30);
    TreeNode *n4 = t.createNode(40);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;

    // t.pre(n1);
    // cout << endl;
    // t.nonrecPre(n1);

    // t.inOrd(n1);
    // cout << endl;
    // t.nonrecInOrd(n1);

    // t.post(n1);
    // cout << endl;
    // t.nonrecPost(n1);

    t.lvlOrder(n1);

    return 0;
}