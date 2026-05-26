// Merge M sorted Lists which have linked list

#include <bits/stdc++.h>
using namespace std;

struct LLNode
{
    int val;
    LLNode *next;

    LLNode(int x) : val(x), next(NULL) {};
};

class Solution
{
public:
    LLNode *mergeSortedList(vector<LLNode *> lists)
    {

        vector<int> allValue;

        for (auto list : lists)
        {

            while (list != NULL)
            {
                allValue.push_back(list->val);
                list = list->next;
            }
        }

        sort(allValue.begin(), allValue.end());

        LLNode *temp = new LLNode(allValue[0]);

        LLNode *curr = temp;

        for (int i = 1; i < allValue.size(); i++)
        {
            curr->next = new LLNode(allValue[i]);
            curr = curr->next;
        }
        return temp;

        // TC->O(n log n);
        // sc-> O(n`);
    }

    class Compare
    {
    public:
        // Comparator to order ListNode pointers based on node values
        bool operator()(LLNode *a, LLNode *b)
        {
            return a->val > b->val;
        }
    };

    LLNode *usingMnHeap(vector<LLNode *> lists)
    {
        priority_queue<LLNode *, vector<LLNode *>, Compare> pq;

        for (auto list : lists)
        {
            if (list != NULL)
                pq.push(list);
        }

        LLNode *dummy = new LLNode(0);
        LLNode *tail = dummy;

        while (!pq.empty())
        {
            LLNode *smallest = pq.top();
            pq.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next != NULL)
                pq.push(smallest->next);
        }
        return dummy->next;

        // TC->O(n log k)  N is the total number of nodes across all K linked lists. min-heap takes O(log K);
        // sc-> O(k)  heap stores at most K nodes ;
    }
};

int main()
{
    // Example: [[1,4,5],[1,3,4],[2,6]]
    LLNode *a = new LLNode(1);
    a->next = new LLNode(4);
    a->next->next = new LLNode(5);

    LLNode *b = new LLNode(1);
    b->next = new LLNode(3);
    b->next->next = new LLNode(4);

    LLNode *c = new LLNode(2);
    c->next = new LLNode(6);

    vector<LLNode *> lists = {a, b, c};

    Solution obj;
    LLNode *result = obj.usingMnHeap(lists);

    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}