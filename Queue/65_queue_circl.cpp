#include <bits/stdc++.h> 
class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if ((front == 0 and rear == size-1) || rear == (front-1)%size)
        {
            return false;
            // q full ra
        }
        else if(front == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = value;
        }
        else if (rear == size-1)
        {
            rear = 0;
            arr[rear] = value;
        }
        else
        {
            rear++;
            arr[rear] = value;
        }
        return true;

    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if (front==-1)
        {
            return -1;
        }
        else if(front==rear)
        {
            int temp = arr[front];
            arr[front] = -1;
            front = -1;
            rear = -1;
            return temp;
        }
        else if (front==size-1)
        {
            int temp = arr[front];
            arr[front] = -1;
            front = 0;
            return temp;
        }
        else
        {
            int temp = arr[front];
            arr[front] = -1;
            front++;
            return temp;
        }
    }
};