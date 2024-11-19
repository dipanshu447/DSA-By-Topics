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

    void pre(TreeNode *rootNode)
    {
        if (rootNode != nullptr)
        {
            cout << rootNode->data << " ";
            pre(rootNode->left);
            pre(rootNode->right);
        }
    }

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

    void lvlOrder(TreeNode *RootNode)
    {
        if (RootNode == nullptr) // Return if the tree is empty
        {
            return;
        }
        queue<TreeNode *> Queue; // Queue to store tree nodes
        TreeNode *temp;
        Queue.push(RootNode);
        while (!Queue.empty()) // Loop runs until the queue is empty
        {
            temp = Queue.front(); // Retrieve the front node from the queue
            Queue.pop();
            cout << temp->data << " "; // Print the current node's data
            if (temp->left != nullptr)
            {
                Queue.push(temp->left); // Enqueue the left child if it exists
            }
            if (temp->right != nullptr)
            {
                Queue.push(temp->right); // Enqueue the right child if it exists
            }
        }
    }

public:
    Tree() : root(nullptr) {}

    void PreOrder()
    {
        pre(root);
    }

    void InOrder()
    {
        inOrd(root);
    }

    void PostOrder()
    {
        post(root);
    }

    void LevelOrder()
    {
        lvlOrder(root);
    }

    void Insert(int data)
    {
        TreeNode *newNode = new TreeNode(data);
        TreeNode *current = root;
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        else
        {
            char choice;
            while (true)
            {
                cout << "Curent Node :  " << current->data << endl;
                cout << "New Node :  " << newNode->data << endl;
                cout << "Enter the left(L) or right node(R) or (N) to insert here: " << endl;
                cin >> choice;
                if (choice == 'L' || choice == 'l')
                {
                    if (current->left != nullptr)
                    {
                        current = current->left;
                    }
                    else
                    {
                        current->left = newNode;
                        break;
                    }
                }
                else if (choice == 'r' || choice == 'R')
                {
                    if (current->right != nullptr)
                    {
                        current = current->right;
                    }
                    else
                    {
                        current->right = newNode;
                        break;
                    }
                }
                else if (choice == 'n' || choice == 'N')
                {
                    cout << "Insert as left(l) or right(r) child : " << endl;
                    cin >> choice;
                    if (choice == 'l' || choice == 'L')
                    {
                        if (current->left == nullptr)
                        {
                            current->left = newNode;
                        }
                        else
                        {
                            cout << "Left Child already exists";
                        }
                    }
                    else if (choice == 'r' || choice == 'R')
                    {
                        if (current->right == nullptr)
                        {
                            current->right = newNode;
                        }
                        else
                        {
                            cout << "Right Child already exists";
                        }
                    }
                    break;
                }
                else
                {
                    cout << "INVALID CHOICE" << endl;
                }
            }
        }
    }

    void Delection(){ // half done NOT WORKING yet It cant delete child nodes. It can only delete root node 
        TreeNode *current = root;
        char choice;
        if (root == nullptr)
        {
            cout << "Tree is empty nothing to delete" << endl;
            return;
        }
        else
        {
            while (true)
            {
                cout << "Curent Node :  " << current->data << endl;
                cout << "Delete this node (Y/N) : " << endl;
                cin >> choice;
                if(choice == 'Y' || choice == 'y'){
                    if(current == root){
                        delete root;
                        root = nullptr;
                        cout << "Root node deleted" << endl;
                        return;
                    }
                    else {
                        cout << "Cannot delete this node as root" << endl;
                    }
                }

                cout << "Move the left(L) or right node(R) or (N) to insert here: " << endl;
                cin >> choice;
                if (choice == 'L' || choice == 'l')
                {
                    if (current->left != nullptr)
                    {
                        current = current->left;
                    }
                    else
                    {
                        delete current->left;
                        current->left = nullptr;
                        break;
                    }
                }
                else if (choice == 'r' || choice == 'R')
                {
                    if (current->right != nullptr)
                    {
                        current = current->right;
                    }
                    else
                    {
                        delete current->right;
                        current->right = nullptr;
                        break;
                    }
                }
                else
                {
                    cout << "INVALID CHOICE" << endl;
                }
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

    t.Insert(10);
    t.Insert(20);
    t.Insert(30);
    t.Insert(40);

    t.Delection();


    return 0;
}