// heapify algo -> job to take and a node to its correct place while converting to end given array to heap?
// we know that from (n/2+1) -> n the nodes are all leaf nodes which are cbt'
// we need to process 1-> n/2

// heap is a complete binary tree with heap order property
// cbt -> every level is filled except the last level
//     -> nodes always added from the left

// max heap -> cbt with every child having lesser value than parent
// min heap -> cbt with every child having more value then parent

#include <iostream>
using namespace std;

class heap
{
    public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        // find parent
        while (index>1)
        {
            int parent = index/2;

            if (arr[parent]<arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else    
                return ;
        }
    }

    void print()
    {
        for (int i=1; i<=size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    // always the root gets yeeted
    void deletefromHeap()
    {
        if (size==0)
            return ;
        
        arr[1] = arr[size];
        size--;

        // find the correct position of last ele
        int i=1;
        while (i<size)
        {
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;
            
            if (leftIndex<size and arr[i]<arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex<size and arr[i]<arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return ;
            }
        }
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    // we use <= for 1 indexing and < for 0 indexing
    if (left<=n and arr[largest]<arr[left])
    {
        largest = left;
    }
    if (right<=n and arr[largest]<arr[right])
    {
        largest = right;
    }

    if (largest!=i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
    return ;
}

void heapsort(int arr[], int n)
{
    int size = n;

    while (size>1)
    {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deletefromHeap();
    h.print();

    int n = 5;
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    
    for (int i=n/2; i>0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i=1; i<=n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    heapsort(arr, n);
    for (int i=1; i<=n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}