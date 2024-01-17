#include <iostream>
using namespace std;

class Stack
{
    public:
        int *arr;
        int size;
        int top;

    
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        this->top = -1;
    }

    void push(int ele)
    {
        if (size > top+1)
        {
            top++;
            arr[top] = ele;
            return ;
        }
        else
        {
            cout<<"bruh momnet1"<<endl;
            return ;
        }
    }

    void pop()
    {
        if (top != -1)
        {
            cout<<"yeeted ele is "<<arr[top]<<endl;
            top = top-1;
            return;
        }
        else
        {
            cout<<"bruhmoment2"<<endl;
            return ;
        }
    }

    int peek()
    {
        if (top >= 0 and top<size)
        {
            cout<<"top ele is "<<arr[top]<<endl;
            return arr[top];
        }
        else
        {
            cout<<"bruhmoment3"<<endl;
            return -1;
        }
    }

    bool isempty()
    {
        if (top == -1)
        {
            cout<<"full"<<endl;
            return true;
        }
        else
        {
            cout<<"we chillin"<<endl;
            return false;
        }
    }
};

int main()
{
    Stack stck(10);

    stck.push(2);
    stck.push(4);
    stck.push(6);
    stck.push(8);

    stck.pop();
    stck.pop();

    int num = stck.peek();
    // cout<<"peak: "<<num;
    return 0;
}