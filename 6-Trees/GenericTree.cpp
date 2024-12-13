#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class TreeNode {
public:
    int data;
    vector <TreeNode*> child;

    TreeNode(int val) : data(val) {}

    void addChild(TreeNode * newchild){
        child.push_back(newchild);
    }

    TreeNode *createTree(){
        TreeNode *root = new TreeNode(1);

        TreeNode *child1 = new TreeNode(2);
        TreeNode *child2 = new TreeNode(3);
        TreeNode *child3 = new TreeNode(4);

        root->addChild(child1);
        root->addChild(child2);
        root->addChild(child3);

        TreeNode *child2_1 = new TreeNode(5);
        TreeNode *child2_2 = new TreeNode(6);
        TreeNode *child2_3 = new TreeNode(7);

        child2->addChild(child2_1);
        child2->addChild(child2_2);
        child2->addChild(child2_3);

        return root;
    }

    void preorder(TreeNode* Root){
        stack<TreeNode*> Stack;

        Stack.push(Root);
        while (!Stack.empty())
        {
            TreeNode *temp = Stack.top();
            Stack.pop();

            cout << temp->data << " ";

            for (int i = temp->child.size()-1; i >= 0 ; i--)
            {
                Stack.push(temp->child[i]);
            }
        }
        
    }
};

int main(){
    
    TreeNode* r = new TreeNode(0);
    TreeNode *t = r->createTree();
    //         1
    //      /  |  \
    //     2   3   4
    //   / | \
    //  5  6  7
    r->preorder(t);
      
    return 0;
}