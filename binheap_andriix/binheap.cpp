#include<iostream>
#include <vector>
#include<climits>
using namespace std;

class BinHeap
{
    int *heapArray;
    int maxSize;
    int heap_size;
public:
    BinHeap(int cap)
    {
        heap_size = 0;
        maxSize = cap;
        heapArray = new int[cap];
    }

    void heapUpdate(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && heapArray[l] < heapArray[i])
            smallest = l;
        if (r < heap_size && heapArray[r] < heapArray[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(heapArray[i], heapArray[smallest]);
            heapUpdate(smallest);
        }
    }

    int parent(int i)
    {
        return (i-1)/2;
    }

    int left(int i)
    {
        return (2*i + 1);
    }

    int right(int i)
    {
        return (2*i + 2);
    }

    int extractMin()
    {
        if (heap_size <= 0)
            return INT_MAX;
        if (heap_size == 1)
        {
            heap_size--;
            return heapArray[0];
        }

        int top = heapArray[0];
        heapArray[0] = heapArray[heap_size-1];
        heap_size--;
        heapUpdate(0);

        return top;
    }

    int getMin()
    {
        return heapArray[0];    ///////////////////////////////
    }

    void insertVal(int k)
    {
        if (heap_size == maxSize)
        {
            cout << "\nOops:\(\n";
            return;
        }

        heap_size++;
        int i = heap_size - 1;
        heapArray[i] = k;

        while (i != 0 && heapArray[parent(i)] > heapArray[i])
        {
            swap(heapArray[i], heapArray[parent(i)]);
            i = parent(i);
        }
    }
};

int main()
{
    int n;
    cout<<"Enter size of your array: ";
    cin>>n;
    BinHeap h(n);
    for(int i=0; i<n; i++)
    {
        int input;
        cin>>input;
        h.insertVal(input);
    }
    cout<<"Sorted sequence: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<h.getMin()<<" ";
        h.extractMin();
    }
    cout<<endl;
    return 0;
}
