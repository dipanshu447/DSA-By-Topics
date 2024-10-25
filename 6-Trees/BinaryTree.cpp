#include <iostream>
#include <stack>
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

    TreeNode *createNode(int data){
        TreeNode *newNode = new TreeNode(data);
        return newNode;
    }

    void pre(TreeNode *rootNode){
        if (rootNode != nullptr)
        {
            cout << rootNode->data << " ";
            pre(rootNode->left);
            pre(rootNode->right);
        }
    }

    void inOrd(TreeNode *rootNode){
        if (rootNode != nullptr)
        {
            inOrd(rootNode->left);
            cout << rootNode->data << " ";
            inOrd(rootNode->right);
        }
    }

    void nonrecPre(TreeNode *Rootnode){
        stack <TreeNode*>  s; // stack will store treenode pointers
        while (true)
        {
            while (Rootnode != nullptr)
            {
                cout << Rootnode->data << " "; // print rootnode data
                s.push(Rootnode); // push that rootnode into stack to later loop through that for its other sub trees
                Rootnode = Rootnode->left; // root goes to left subtrees
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

    // void preOrder(){
    //     pre(root);
    // }
    
};

int main()
{
    Tree t;

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

    t.inOrd(n1);

    return 0;
}