#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
    int data;
    vector <TreeNode*> children;

    TreeNode(int val) : data(val) {}

    void addChild(TreeNode * child){
        children.push_back(child);
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
    }
};

int main(){
    
    
      
    return 0;
}