#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
public:
    // max elements can be store
    int capacity;
    // Current no of elements in heap
    int size;

    int *arr;

    MinHeap(int cap)
    {
        capacity = cap;

        size = 0;

        arr = new int[capacity];
    }

    // Returns the parent of ith Node
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    // ith left child
    int left(int i)
    {
        return 2 * i + 1; // 0' base indexing
    }

    // ith right child
    int right(int i)
    {
        return 2 * i + 2;
    }

    // Insert a new key x
    void Insert(int x)
    {
        if (size == capacity)
        {
            cout << "Binary heap overflow" << endl;
            return;
        }

        arr[size] = x;

        int k = size;

        size++;

        while (k != 0 && arr[parent(k)] > arr[k])
        {
            swap(&arr[parent(k)], &arr[k]);
            k = parent(k);
        }
    }

    // We assume that all the subtrees of the tree rooted at index i are valid binary heaps.
    void heapify(int ind)
    {
        int li = left(ind);
        int ri = right(ind);

        int smallest = ind;
        if (li < size && arr[li] < arr[smallest])
            smallest = li;
        if (ri < size && arr[ri] < arr[smallest])
            smallest = ri;

        if (smallest != ind)
        {
            swap(&arr[ind], &arr[smallest]);
            heapify(smallest);
        }
    }

    int getMin()
    {
        if (size <= 0)
            return INT_MAX;

        return arr[0];
    }

    int ExtractMin()
    {

        if (size <= 0)
            return INT_MAX;
        if (size == 1)
        {
            size--;
            return arr[0];
        }

        int mini = arr[0];

        arr[0] = arr[size - 1];
        size--;

        heapify(0);
        return mini;
    }

    // at i index decrease the value which is given by user
    void Decreasekey(int i, int val)
    {
        arr[i] = val;

        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(&arr[parent(i)], &arr[i]);
            i = parent(i);
        }
    }

    void swap(int *a, int *b)
    {
        int *temp = a;
        a = b;
        b = temp;
    }

    void Delete(int i)
    {
        Decreasekey(i, INT_MIN);
        ExtractMin();
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

/*

    Function	Time Complexity
    Insert(): 	O(logN)
    Heapify():	O(logN)
    getMin():	O(1)
    ExtractMin():	O(logN)
    Decreasekey():	O(logN)
    Delete():	O(logN)

*/

int main()
{
    MinHeap h(20);
    h.Insert(4);
    h.Insert(1);
    h.Insert(2);
    h.Insert(6);
    h.Insert(7);
    h.Insert(3);
    h.Insert(8);
    h.Insert(5);

    cout << "Min value is " << h.getMin() << endl;

    h.Insert(-1);
    cout << "Min value is " << h.getMin() << endl;

    h.Decreasekey(3, -2);
    cout << "Min value is " << h.getMin() << endl;

    h.ExtractMin();
    cout << "Min value is " << h.getMin() << endl;

    h.Delete(0);
    cout << "Min value is " << h.getMin() << endl;
    return 0;
}