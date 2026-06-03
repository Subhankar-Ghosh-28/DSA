#include <bits/stdc++.h>
using namespace std;

// find median of a stream

class Brute
{
private:
    vector<int> nums;

public:
    Brute() {}
    void addNum(int x)
    {
        nums.push_back(x);
    }

    double findMedian()
    {
        sort(nums.begin(), nums.end());

        int size = nums.size();

        if (size % 2 == 0)
        {
            return (nums[size / 2] + nums[size / 2 + 1]) / 2.0;
        }

        return nums[size / 2];

        // TC->O(n log n) sortng
        // SC->O(n)
    }
};

class Optimal
{
private:
    priority_queue<int> maxHeap;

    priority_queue<int, vector<int>, greater<>> minHeap;

public:
    Optimal() {}
    void addNum(int x)
    {
        maxHeap.push(x);
        ;

        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        return maxHeap.top();
    }
    // TC->O(n log n + m) addNum() takes O(log N), and each call to findMedian() is O(1).
    // SC->O(n)
};

int main()
{
    // brute force
    Brute mf;

    mf.addNum(1);
    mf.addNum(2);
    mf.addNum(3);
    cout << mf.findMedian() << endl;

    // optimal

    Optimal mf1;
    mf1.addNum(1);
    mf1.addNum(2);
    cout << mf1.findMedian() << endl; // Output: 1.5
    mf1.addNum(3);
    cout << mf1.findMedian() << endl; // Output: 2
    return 0;
}