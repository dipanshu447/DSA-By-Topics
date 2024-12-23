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

    bool search(TreeNode *rootNode, int target)
    {
        if (rootNode == nullptr)
        {
            return false;
        }
        if (rootNode->data == target)
        {
            return true;
        }
        return search(rootNode->left, target) || search(rootNode->right, target);
    }

    bool searchIterative(TreeNode *rootNode, int target)
    {
        if (rootNode == nullptr)
        {
            return false;
        }

        queue<TreeNode *> q;
        q.push(rootNode);

        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();

            if (current->data == target)
            {
                return true;
            }

            if (current->left != nullptr)
            {
                q.push(current->left); // Add left child to queue
            }
            if (current->right != nullptr)
            {
                q.push(current->right); // Add right child to queue
            }
        }
        return false;
    }

    int recurSize(TreeNode *rootNode)
    {
        if (rootNode == nullptr)
        {
            return 0;
        }

        return recurSize(rootNode->left) + recurSize(rootNode->right) + 1;
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
        TreeNode *newNode = new TreeNode(data); // Create new node to be added
        TreeNode *current = root;
        if (root == nullptr)
        {
            root = newNode; // If the tree is empty, the new node becomes the root
            return;
        }
        else
        {
            char choice;
            while (true)
            {
                cout << "Curent Node :  " << current->data << endl; // Shows the current node
                cout << "New Node :  " << newNode->data << endl;    // Shows the new node to be inserted
                cout << "Enter the left(L) or right node(R) or (N) to insert here: " << endl;
                cin >> choice;
                // Traverse the tree based on user input or insert if user chooses 'N'
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
                    // Insert at the current node if no left or right child exists
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

    void Delection()
    {
        TreeNode *current = root;        // traverse current node
        TreeNode *parent = nullptr;      // track the parent noe of current
        TreeNode *grandparent = nullptr; // Track the grandparent node for backtracking (Its neeeded so that we can traverse back)
        bool running = true;
        char choice;
        if (root == nullptr)
        {
            cout << "Tree is empty nothing to delete" << endl;
            return;
        }
        while (running) // runs till user choose to exit
        {
            cout << "Current node : " << current->data << endl;
            cout << "Move the left(L) or right node(R) or delete this node (D), go back (B), Exit(E) here: " << endl;
            cin >> choice;
            // traverse the tree based on user inputs and tracks the parent and grandparent nodes
            if (choice == 'L' || choice == 'l')
            {
                if (current->left != nullptr)
                {
                    grandparent = parent;
                    parent = current;
                    current = current->left;
                }
                else
                {
                    cout << "Left child is already null" << endl;
                }
            }
            else if (choice == 'r' || choice == 'R')
            {
                if (current->right != nullptr)
                {
                    grandparent = parent;
                    parent = current;
                    current = current->right;
                }
                else
                {
                    cout << "Right child is already null" << endl;
                }
            }
            // so that user can traverse back to parent or grandparent node
            else if (choice == 'B' || choice == 'b')
            {
                if (parent != nullptr)
                {
                    current = parent;
                    parent = grandparent;
                    grandparent = nullptr;
                }
                else
                {
                    cout << "Already at the root node, cannot go back further!!" << endl;
                }
            }
            else if (choice == 'D' || choice == 'd')
            {
                if (current == root)
                {
                    delete root; // Delete the root node
                    root = nullptr;
                    cout << "Root node deleted" << endl;
                    return;
                }
                else
                {
                    if (parent != nullptr)
                    {
                        if (parent->left == current)
                        {
                            delete current; // Delete the left child
                            parent->left = nullptr;
                            cout << "Left child deleted" << endl;
                        }
                        else if (parent->right == current)
                        {
                            delete current; // Delete the right child
                            parent->right = nullptr;
                            cout << "Right child deleted" << endl;
                        }
                        current = parent;
                        parent = grandparent;
                        grandparent = nullptr;
                    }
                }
            }
            else if (choice == 'E' || choice == 'e')
            {
                running = false;
            }
            else
            {
                cout << "INVALID CHOICE" << endl;
            }
        }
    }

    bool Search(int targetValue)
    {
        return search(root, targetValue);
    }

    bool SearchIterative(int targetValue)
    {
        return searchIterative(root, targetValue);
    }

    int size()
    { // basically its a preorder traversal but it counts nodes
        TreeNode *current = root;
        int count = 0;
        stack<TreeNode *> s;
        while (!s.empty() || current != nullptr)
        {
            while (current != nullptr)
            {
                count++;
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            current = current->right;
        }
        return count;
    }

    int SizeRecursive()
    {
        return recurSize(root);
    }

    int height()
    {
        TreeNode *current;
        int height = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i)
            {
                current = q.front();
                q.pop();

                if (current->left != nullptr)
                {
                    q.push(current->left);
                }
                if (current->right != nullptr)
                {
                    q.push(current->right);
                }
            }
            if (!q.empty())
            {
                ++height;
            }
        }
        return height;
    }

    int MaxNumLvl()
    {
        if (root == nullptr)
        {
            return 0;
        }
        queue<TreeNode *> nodes;
        int maxSum = INT16_MIN;
        int maxLevel = 0;
        int currentLvl = 0;
        nodes.push(root);
        while (!nodes.empty())
        {
            int levelSize = nodes.size();
            int levelSum = 0;

            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *cur = nodes.front();
                nodes.pop();

                levelSum += cur->data;

                if (cur->left != nullptr)
                {
                    nodes.push(cur->left);
                }

                if (cur->right != nullptr)
                {
                    nodes.push(cur->right);
                }
            }

            if(levelSum > maxSum){
                maxSum = levelSum;
                maxLevel = currentLvl;
            }

            currentLvl++;
        }
       
        return maxLevel;
    }
};

int main()
{
    Tree t;
    // treeeeeeee
    //    10
    //   /  \ 
    //  20  30
    //  /    \ 
    // 40    50
    // /      \ 
   // 60      70

    t.Insert(10);
    t.Insert(20);
    t.Insert(30);
    t.Insert(40);
    t.Insert(50);
    t.Insert(60);
    t.Insert(70);
    // cout << "Height of the tree : " << t.height() << endl;
    cout << "Level of the tree which has the maximum sum: " << t.MaxNumLvl() << endl;

    // TreeNode *root = new TreeNode(10);
    // root->left = new TreeNode(20);
    // root->right = new TreeNode(30);
    // root->left->left= new TreeNode(40);
    // cout<< "Size of tree is : " << t.size() << endl;
    // t.Delection();

    // if (t.SearchIterative(40))
    // {
    //     cout << "Damn bro i found it " << endl;
    // }else {
    //     cout << "Nah bro its not there" << endl;
    // }

    return 0;
}