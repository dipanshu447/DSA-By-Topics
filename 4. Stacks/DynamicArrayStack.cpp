#include <iostream>
using namespace std;

#define STACK_EMPTY_ERROR -9999

/* 
so this is also a simple array as its basically same as simple array approach but only difference is we used a pointer
array and take the capacity of array from the user. There is two ways to make it dynamic, 
    - First is increment array capacity by one everytime we push and transfer old array elements to new one.. 
      which will be O(n^2)
    - Second and a better approach than first is repeated doubling where if the arrya is full, we create a new 
      array which is twice the capacity of old array and copy the elemets to new array which is O(n) (amortized time complexity)

We will apply second approach here!
*/

class stack
{
    int *arr;
    int top;
    int StackCapacity;

public:
    stack(int size) : top(-1), StackCapacity(size) {
        arr = new int[StackCapacity];
    }

    // basic check empty, full operation and size which returns the size of stack
    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == StackCapacity - 1);
    }

    int size()
    {
        return top + 1;
    }

    // // simple array push
    // void push(int data)
    // {
    //     if (isFull())
    //     {
    //         cout << "Stack Overflow!" << endl;
    //         return;
    //     }

    //     arr[++top] = data;
    //     // ++top;
    // }

    // function to double the size of arry and copy it to new array
    void doubleStackSize(){

        int *newarr = new int[StackCapacity*2]; // new array

        for (int i = 0; i < StackCapacity; i++) // copy all to new array
        {
            newarr[i] = arr[i];
        }
        
        StackCapacity *= 2; // double the capacity

        delete [] arr; // delete old array
        arr = newarr; // point the old array pointer to new array pointer
    }
    
    // dynamic array push using second approach (refer to above comment)
    // if the stack is full then it doubles the size of stack using doubleStackSize() function defined above
    void push(int data)
    {
        if (isFull())
        {
            doubleStackSize();
        }

        arr[++top] = data;
        // ++top;
    }

    // simple pop just removes one element from stack
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return STACK_EMPTY_ERROR;
        }

        int del = arr[top];
        --top;
        return del;
    }

    // returns the value of the top element of stack
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return STACK_EMPTY_ERROR;
        }
        return arr[top];
    }

    // stack dont usually have a display operation but I made one to visualize a stack better
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return;
        }

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }

    // delete the stack by deleting the array pointer memory, resetting the top
    void deleteStack(){
        delete [] arr;
        arr = nullptr;
        top = -1; // reset the index
    }
};

int main()
{
    stack s(2);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << "Pop element : " << s.pop() << endl;

    s.display();

    s.deleteStack();

    s.display();

    return 0;
}