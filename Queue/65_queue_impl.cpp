#include <bits/stdc++.h> 
using namespace std;

class Queue {
    int* arr;
    int qfront;
    int rear;
    int size;
public:
    Queue() 
    {
        // Implement the Constructor
        size = 10000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if (qfront==rear)
            return true;
        else
            return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if (rear == size)
        {
            cout<<"Queue is full";
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if (qfront==rear)
        {
            return -1;
        }
        else
        {
            int temp = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            return temp;
        }
    }

    int front() {
        // Implement the front() function
        if (qfront == rear)
        {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};